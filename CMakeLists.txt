cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_tutorial C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

#Add my test example
add_subdirectory(button_test)
add_subdirectory(analog_io)
add_subdirectory(timer_tutorial)
add_subdirectory(reflex_game)
add_subdirectory(reflex_game_adaptive)