/*rp2040_temp_sensor_driver.c
Driver para leitura da temperatura interna do processador da rp2040*/

#include "hardware/adc.h"
#include "rp2040_temp_sensor_driver.h"
#include <stdio.h>

void rp2040_temp_sensor_init() {
    adc_init();
    adc_set_temp_sensor_enabled(true);
}

uint16_t rp2040_temp_sensor_read() {
    adc_select_input(4); // Canal ADC 4 é usado para o sensor de temperatura
    uint16_t adcValue = adc_read();
    printf("Driver ADC Value: %d\n", adcValue); //print para debug
    return adcValue;
}