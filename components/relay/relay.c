#include <stdio.h>
#include <esp_log.h>
#include "driver/gpio.h"
#include "relay.h"

static const char *TAG_RELAY = "Relay";

// Initialize the relay control
esp_err_t relay_init(gpio_num_t gpio_num)
{
    ESP_LOGW(TAG_RELAY, "relayControl01_init() called");
    // Configurar a GPIO para o relé como saída
    gpio_pad_select_gpio(gpio_num);
    gpio_config_t out_conf = {};
    out_conf.intr_type = GPIO_INTR_DISABLE;
    out_conf.mode = GPIO_MODE_OUTPUT;
    out_conf.pin_bit_mask = (1 << gpio_num);
    out_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    out_conf.pull_up_en = GPIO_PULLDOWN_ENABLE;
    gpio_config(&out_conf);
    // Desligar o relé
    gpio_set_level(gpio_num, 0);
    return ESP_OK;
}

// Turn on the relay
esp_err_t relay_setOn(gpio_num_t gpio_num)
{
    ESP_LOGW(TAG_RELAY, "relayControl01_set() called");
    // Acionar o relé
    gpio_set_level(gpio_num, 1);
    return ESP_OK;
}

// Turn off the relay
esp_err_t relay_setOff(gpio_num_t gpio_num)
{
    ESP_LOGW(TAG_RELAY, "relayControl01_set() called");
    // Desligar o relé
    gpio_set_level(gpio_num, 0);
    return ESP_OK;
}