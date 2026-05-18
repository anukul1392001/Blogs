/*
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include <errno.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/net/net_if.h>
#include <zephyr/net/wifi_mgmt.h>

LOG_MODULE_REGISTER(WIFI_TEST, LOG_LEVEL_DBG);

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PSK "YOUR_WIFI_PASSWORD"
#define WIFI_IFACE_TIMEOUT_MS 15000
#define WIFI_CONNECT_TIMEOUT K_SECONDS(30)

static struct net_mgmt_event_callback wifi_cb;
static K_SEM_DEFINE(wifi_connect_sem, 0, 1);

static int wifi_connect_status;
static bool connected;

static int wait_for_wifi_iface(struct net_if *iface)
{
	int64_t deadline = k_uptime_get() + WIFI_IFACE_TIMEOUT_MS;

	while (k_uptime_get() < deadline) {
		if (net_if_is_carrier_ok(iface)) {
			return 0;
		}

		k_sleep(K_MSEC(100));
	}

	return -ETIMEDOUT;
}

static void wifi_event_handler(struct net_mgmt_event_callback *cb,
			       uint64_t mgmt_event, struct net_if *iface)
{
	switch (mgmt_event) {
	case NET_EVENT_WIFI_CONNECT_RESULT: {
		struct wifi_status *status = (struct wifi_status *)cb->info;

		wifi_connect_status = status->status;

		if (wifi_connect_status == 0) {
			connected = true;
			LOG_INF("Wi-Fi connected");
		} else {
			connected = false;
			LOG_ERR("Wi-Fi connection failed: %d", wifi_connect_status);
		}

		k_sem_give(&wifi_connect_sem);
		break;
	}

	case NET_EVENT_WIFI_DISCONNECT_RESULT:
		connected = false;
		LOG_WRN("Wi-Fi disconnected");
		break;

	default:
		break;
	}
}

static int connect_to_wifi(void)
{
	struct net_if *iface = net_if_get_default();
	struct wifi_connect_req_params wifi_params = { 0 };
	int ret;

	if (iface == NULL) {
		LOG_ERR("No default network interface found");
		return -ENODEV;
	}

	ret = wait_for_wifi_iface(iface);
	if (ret != 0) {
		LOG_ERR("Timed out waiting for ESP Wi-Fi interface");
		return ret;
	}

	net_mgmt_init_event_callback(&wifi_cb, wifi_event_handler,
				     NET_EVENT_WIFI_CONNECT_RESULT |
				     NET_EVENT_WIFI_DISCONNECT_RESULT);
	net_mgmt_add_event_callback(&wifi_cb);

	wifi_params.ssid = WIFI_SSID;
	wifi_params.ssid_length = strlen(WIFI_SSID);
	wifi_params.psk = WIFI_PSK;
	wifi_params.psk_length = strlen(WIFI_PSK);
	wifi_params.channel = WIFI_CHANNEL_ANY;
	wifi_params.security = WIFI_SECURITY_TYPE_PSK;

	LOG_INF("Connecting to SSID: %s", WIFI_SSID);

	ret = net_mgmt(NET_REQUEST_WIFI_CONNECT, iface, &wifi_params,
		       sizeof(wifi_params));
	if (ret != 0) {
		LOG_ERR("Wi-Fi connection request failed: %d", ret);
		return ret;
	}

	ret = k_sem_take(&wifi_connect_sem, WIFI_CONNECT_TIMEOUT);
	if (ret != 0) {
		LOG_ERR("Timed out waiting for Wi-Fi connection");
		return -ETIMEDOUT;
	}

	return wifi_connect_status;
}

int main(void)
{
	int ret;

	LOG_INF("Wi-Fi connection starting");

	ret = connect_to_wifi();
	if (ret != 0) {
		LOG_ERR("Failed to connect to Wi-Fi: %d", ret);
		return 0;
	}

	while (true) {
		LOG_INF("Wi-Fi status: %s", connected ? "connected" : "disconnected");
		k_sleep(K_SECONDS(10));
	}

	return 0;
}
