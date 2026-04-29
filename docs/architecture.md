# Firmware Architecture

## Overview
The firmware is intentionally minimal and preserves the original behavior: a polling loop reads keypad input and updates LEDs.

## `src/main.cpp`

### Static configuration
- `keys[4][4]`: keypad character map.
- `ledPins[12]`: GPIO order used by action logic.
- `rowPins[4]`, `colPins[4]`: keypad matrix GPIO assignment.

### Initialization (`init_gpio`)
- Configures all LED pins as outputs and sets them LOW.
- Configures row pins as inputs with pull-up.
- Configures column pins as outputs and idles them HIGH.

### Key scanning (`get_key`)
- Drives one column LOW at a time.
- Reads rows for active-low press detection.
- Uses simple key-release wait debounce.
- Returns pressed key or `\0` when no key is pressed.

### Main loop
- Polls `get_key()`.
- Executes a `switch` with the same key-to-LED behavior as the provided source.
- Sleeps 10ms per cycle.

## Behavior Guarantees
- No Wi-Fi use.
- No dynamic allocation.
- Deterministic polling-based control flow.
