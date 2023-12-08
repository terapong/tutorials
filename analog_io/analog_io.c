#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

#define POT_PIN 26
#define LED_PIN 14

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x, - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main() {
    stdio_init_all();
    adc_init();
    adc_gpio_init(POT_PIN);
    adc_select_input(LED_PIN);

    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);

    pwm_set_wrap(slice_num, 255);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);

    while (1) {
        uint16_t result = adc_read();
        long pwm_value = map(result, 0, 4095, 0, 255);

        printf("Raw: %d \t PWM: %d\n", result, pwm_value);

        pwm_set_chan_level(slice_num, PWM_CHAN_A, pwm_value);

        sleep_ms(50);
    }
    
}