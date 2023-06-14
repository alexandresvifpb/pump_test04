#ifndef __RELAY_H__
#define __RELAY_H__

#pragma once

#include <esp_err.h>
#include "driver/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

// Function to initialize the relay control
esp_err_t relay_init(gpio_num_t gpio_num);

// Function to set the relay on
esp_err_t relay_setOn(gpio_num_t gpio_num);

// Function to set the relay off
esp_err_t relay_setOff(gpio_num_t gpio_num);

#ifdef __cplusplus
}
#endif

#endif // __RELAY_H__