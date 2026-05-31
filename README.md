# SMF IP Module

Zephyr-based IP module using SMF.

## Build

```sh
source tools/.env_setup
west build -p always -b nrf52dk/nrf52832 .
```

## Flash & Debug

```sh
west flash
```

## RTT Logs

Terminal 1:
```sh
JLinkExe -device nRF52832_xxAA -if SWD -speed 4000 -autoconnect 1
```

Terminal 2:
```sh
JLinkRTTClientExe
```

## Layout

```text
include/          Public headers
src/app/          Application entry
src/core/         Module logic
src/port/zephyr/
  hw_timer/       Hardware timer abstraction
  kernel/         Kernel utilities
  log/            Logging macros
  smf/            SMF include wrapper
  threads/        Thread utilities
```
