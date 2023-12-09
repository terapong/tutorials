add_executable(reflex_game_adaptive
reflex_game_adaptive.c
    )

# pull in our pico stdlib which pulls in commonly used feature
target_link_libraries(reflex_game_adaptive pico_stdlib hardware_gpio hardware_timer)

# enable usb output, disable uart output
pico_enable_stdio_usb(reflex_game_adaptive 1)
pico_enable_stdio_uart(reflex_game_adaptive 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(reflex_game_adaptive)

