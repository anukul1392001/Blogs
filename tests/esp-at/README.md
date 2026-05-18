ESP-AT Wi-Fi Connection Test
############################

Overview
********

This test brings up an ESP-AT Wi-Fi module over UART and connects it to the
SSID configured in ``src/wifi_test.c``.

The application only tests Wi-Fi connection. MQTT, shell commands, and DNS
resolution are not used.

Hardware Setup
**************

Connect the ESP-AT module UART to the nRF52 DK UART configured in
``app.overlay``:

.. code-block:: text

   ESP TX  -> nRF RX
   ESP RX  -> nRF TX
   ESP GND -> nRF GND
   ESP 3V3 -> stable 3.3 V supply

RTS and CTS are not used.

Use a supply that can handle ESP Wi-Fi current bursts. If the ESP resets when
station mode is enabled or while joining an access point, add bulk capacitance
near the ESP module power pins.

ESP-AT UART Setup
*****************

Before running this test, configure the ESP UART default to 115200 baud with
flow control disabled:

.. code-block:: text

   AT
   AT+UART_DEF=115200,8,1,0,0
   AT+RST
   AT+UART_CUR?

The expected UART query result is:

.. code-block:: text

   +UART_CUR:115200,8,1,0,0
   OK

Logging
*******

Zephyr logs are routed over SEGGER RTT so that the hardware UART can be used
only for ESP-AT traffic.

Start an RTT viewer for the nRF52 target, then reset the board.

Expected Output
***************

Successful ESP-AT initialization should show:

.. code-block:: console

   wifi_esp_at: Waiting for interface to come up
   wifi_esp_at: ESP Wi-Fi ready
   WIFI_TEST: Wi-Fi connection starting
   WIFI_TEST: Connecting to SSID: ...

If ``Unexpected reset`` appears after station mode is enabled, check ESP power,
reset wiring, and the ESP UART default flow-control setting.
