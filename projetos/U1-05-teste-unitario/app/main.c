#include <stdio.h>
#include "pico/stdlib.h"
#include "hal_led.h"
#include "led_embutido.h"
#include "hal_rp2040_temp.h"

int main() {
    stdio_init_all();
    led_embutido_init();
    rp2040_temp_sensor_init(); 

    float temperature;

    while (true) {
        hal_led_toggle();
        sleep_ms(1000);
        temperature = hal_temperature_read_rp2040(); // Lê a temperatura
        printf("Temperatura: %.2f °C\n", temperature); // Imprime a temperatura no console
    }

    return 0;
}