# Pico W Keypad-to-LED Controller

A Raspberry Pi Pico W C++ firmware project that reads a 4x4 membrane keypad and drives 12 LEDs.

## Features
- 4x4 keypad scanning on 8 GPIO pins
- 12 independent LED outputs
- Key actions map directly to LED groups:
  - `1..8`: turn on LED 1..8
  - `9`: turn on LED 1..8 together
  - `0`: turn off LED 1..8 together
  - `A..D`: turn on LED 9..12
  - `*`: turn on LED 9..12 together
  - `#`: turn off LED 9..12 together

## Repository Layout
- `src/main.cpp`: Firmware entry point and keypad/LED control logic
- `include/`: Reserved for headers if the firmware grows
- `docs/wiring.md`: Components and pin mapping from Wokwi diagram
- `docs/architecture.md`: Module and behavior documentation
- `CMakeLists.txt`: Pico SDK build file

## Hardware
See `docs/wiring.md` for full details.

## Build and Flash (Real Pico W)
1. Install Pico SDK toolchain.
2. Set `PICO_SDK_PATH`.
3. Build:
   ```bash
   mkdir -p build
   cd build
   cmake ..
   make -j
   ```
4. Hold **BOOTSEL** while connecting Pico W via USB.
5. Copy generated `pico_keypad_led.uf2` to `RPI-RP2` mass storage.

## Run in Wokwi
1. Create a new **Raspberry Pi Pico** C++ project in Wokwi.
2. Replace `diagram.json` with the provided diagram.
3. Replace source with `src/main.cpp` contents.
4. Start simulation and press keypad buttons.

## Wi-Fi Note
This firmware does not use Wi-Fi. No credentials are required.
