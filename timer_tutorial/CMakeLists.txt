add_executable(timer_tutorial
        timer_tutorial.c
    )

# pull in our pico stdlib which pulls in commonly used feature
target_link_libraries(timer_tutorial pico_stdlib hardware_gpio hardware_timer)

# enable usb output, disable uart output
pico_enable_stdio_usb(timer_tutorial 1)
pico_enable_stdio_uart(timer_tutorial 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(timer_tutorial)

