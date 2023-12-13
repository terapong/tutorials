#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTON_PIN 15

int main() {
    stdio_init_all();
    gpio_init(BUTON_PIN);
    gpio_set_dir(BUTON_PIN, GPIO_IN);
    gpio_pull_up(BUTON_PIN);

    while (true) {
        if(!gpio_get(BUTON_PIN)) {
            printf("Button pressed\n");
        }

        sleep_ms(250);
    }
    
}
