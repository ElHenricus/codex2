#include <array>
#include "pico/stdlib.h"

constexpr uint8_t LEDS = 12;
constexpr uint8_t ROWS = 4;
constexpr uint8_t COLS = 4;

const char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Pins connected to LED1, LED2, LED3, ...LED12
const std::array<uint, LEDS> ledPins = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 28, 27};
const std::array<uint, ROWS> rowPins = {26, 22, 21, 20}; // Pins connected to R1, R2, R3, R4
const std::array<uint, COLS> colPins = {19, 18, 17, 16}; // Pins connected to C1, C2, C3, C4

static void init_gpio() {
  for (uint8_t l = 0; l < LEDS; l++) {
    gpio_init(ledPins[l]);
    gpio_set_dir(ledPins[l], GPIO_OUT);
    gpio_put(ledPins[l], 0);
  }

  for (uint8_t r = 0; r < ROWS; r++) {
    gpio_init(rowPins[r]);
    gpio_set_dir(rowPins[r], GPIO_IN);
    gpio_pull_up(rowPins[r]);
  }

  for (uint8_t c = 0; c < COLS; c++) {
    gpio_init(colPins[c]);
    gpio_set_dir(colPins[c], GPIO_OUT);
    gpio_put(colPins[c], 1);
  }
}

static char get_key() {
  for (uint8_t c = 0; c < COLS; c++) {
    for (uint8_t i = 0; i < COLS; i++) gpio_put(colPins[i], 1);
    gpio_put(colPins[c], 0);
    sleep_us(5);

    for (uint8_t r = 0; r < ROWS; r++) {
      if (!gpio_get(rowPins[r])) {
        while (!gpio_get(rowPins[r])) {
          sleep_ms(1);
        }
        return keys[r][c];
      }
    }
  }

  return '\0';
}

int main() {
  stdio_init_all();
  init_gpio();

  while (true) {
    char key = get_key();

    if (key != '\0') {
      switch (key) {
        case '1': gpio_put(ledPins[0], 1); break;
        case '2': gpio_put(ledPins[1], 1); break;
        case '3': gpio_put(ledPins[2], 1); break;
        case '4': gpio_put(ledPins[3], 1); break;
        case '5': gpio_put(ledPins[4], 1); break;
        case '6': gpio_put(ledPins[5], 1); break;
        case '7': gpio_put(ledPins[6], 1); break;
        case '8': gpio_put(ledPins[7], 1); break;
        case '9':
          for (uint8_t l = 0; l < 8; l++) gpio_put(ledPins[l], 1);
          break;
        case '0':
          for (uint8_t l = 0; l < 8; l++) gpio_put(ledPins[l], 0);
          break;
        case 'A': gpio_put(ledPins[8], 1); break;
        case 'B': gpio_put(ledPins[9], 1); break;
        case 'C': gpio_put(ledPins[10], 1); break;
        case 'D': gpio_put(ledPins[11], 1); break;
        case '*':
          for (uint8_t l = 8; l < 12; l++) gpio_put(ledPins[l], 1);
          break;
        case '#':
          for (uint8_t l = 8; l < 12; l++) gpio_put(ledPins[l], 0);
          break;
      }
    }

    sleep_ms(10);
  }
}
