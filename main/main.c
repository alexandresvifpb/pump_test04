#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "relay.h"

#define RELAY_GPIO_PIN 2
#define STACK_SIZE 2048

static const char *TAG = "Main";
static const gpio_num_t relay_gpio_num = RELAY_GPIO_PIN;

void relay_task(void *pvParameters)
{
    // Configurar a GPIO para o relé como saída
    relay_init(relay_gpio_num);
 
    while (1)
    {
        // Desligar o relé
        relay_setOff(relay_gpio_num);
        ESP_LOGI(TAG, "Relay desligado");
        vTaskDelay(pdMS_TO_TICKS(5000));

        // Ligar o relé
        relay_setOn(relay_gpio_num);
        ESP_LOGI(TAG, "Relay ligado");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void app_main()
{
    // Criar a tarefa para controlar o relé
    xTaskCreate(relay_task, "relay_task", STACK_SIZE, NULL, 5, NULL);
}
