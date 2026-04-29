# Wiring and GPIO Mapping

## Components List (from `diagram.json`)
- 1x Raspberry Pi Pico / Pico W board
- 1x 4x4 membrane keypad
- 12x LEDs (8 blue, 4 red)
- 12x 220Ω resistors (LED current limiting)
- 4x 1kΩ resistors (keypad row pull-ups to 3V3)
- Jumper wires / breadboard interconnects

## Keypad Wiring
### Columns
| Keypad pin | Pico GPIO |
|---|---|
| C1 | GP19 |
| C2 | GP18 |
| C3 | GP17 |
| C4 | GP16 |

### Rows
| Keypad pin | Pico GPIO | Extra resistor |
|---|---|---|
| R1 | GP26 | 1kΩ pull-up to 3V3 |
| R2 | GP22 | 1kΩ pull-up to 3V3 |
| R3 | GP21 | 1kΩ pull-up to 3V3 |
| R4 | GP20 | 1kΩ pull-up to 3V3 |

## LED Wiring
All LED cathodes connect to GND. Each LED anode is connected to its GPIO through a 220Ω resistor.

| Logical LED | Label | Pico GPIO |
|---|---|---|
| LED1 | 1 | GP11 |
| LED2 | 2 | GP10 |
| LED3 | 3 | GP9 |
| LED4 | 4 | GP8 |
| LED5 | 5 | GP7 |
| LED6 | 6 | GP6 |
| LED7 | 7 | GP5 |
| LED8 | 8 | GP4 |
| LED9 | A | GP3 |
| LED10 | B | GP2 |
| LED11 | C | GP28 |
| LED12 | D | GP27 |

## Assumptions and Notes
- The provided firmware treats row inputs as active-low during scan.
- External 1kΩ row pull-ups from the diagram are retained; internal pull-ups are also enabled in firmware for robustness.
- Pin mapping follows the source arrays exactly to preserve behavior.
