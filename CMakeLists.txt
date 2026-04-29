cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico_keypad_led C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(pico_keypad_led
  src/main.cpp
)

target_include_directories(pico_keypad_led PRIVATE include)

target_link_libraries(pico_keypad_led pico_stdlib)

pico_add_extra_outputs(pico_keypad_led)
