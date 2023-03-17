#ifndef BLINK_H
#define BLINK_H

#define LED_PIN CYW43_WL_GPIO_LED_PIN
#define HEARTBEAT_PERIOD_MS 250

#include "btstack_config.h"
#include "btstack.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "pico/btstack_cyw43.h"
#include <stdint.h>

int btstack_main(void);
int le_setup(void);
int16_t toggle_led(int16_t led_state);
int main();

#endif
