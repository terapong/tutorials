#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#define LED_PIN 15
#define BUTTON_PIN 14

int led_value = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    led_value = 1 - led_value;
    gpio_put(LED_PIN, led_value);
    printf("LED tokkled\n");

    return true;
}

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    printf("Alarm Fired");
    return 2000000;
}

void button_callback(uint gpio, uint32_t events) {
    printf("Interrupt occured at pin %d with event %d", gpio, events);
}

int main() {
    stdio_init_all();
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    gpio_set_irq_enabled_with_callback(BUTTON_PIN, 0x04, 1, button_callback);

    struct repeating_timer timer;
    add_repeating_timer_ms(500, repeating_timer_callback, NULL, &timer);

    add_alarm_in_ms(2000, alarm_callback, NULL, false);

    while (1) {
        tight_loop_contents();
    }
    
}