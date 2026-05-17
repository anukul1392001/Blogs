# SMF IP Module

Zephyr-based IP module using SMF.

## Build

```sh
source tools/.env_setup
west build -b nrf52dk/nrf52832
```

## Layout

```text
include/    Public headers
src/app/    Application entry
src/core/   Module logic
src/port/   Zephyr port wrappers
```
