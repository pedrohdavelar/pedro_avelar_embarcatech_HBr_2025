#include "hal_rp2040_temp.h"
#include "rp2040_temp_sensor_driver.h"
#include <stdio.h>

float adc_to_celsius(uint16_t adcValue) {
    const float conversionFactor = 3.3f / 4095; // Conversão de ADC para tensão (12 bits)
    float voltage = adcValue * conversionFactor; // Converte o valor ADC para tensão
    printf("Hal Voltage: %.3f V\n", voltage); //print para debug
    float temperature = 27.0f - (voltage - 0.706f) / 0.001721f; // converte a tensão para temperatura Celsius
    printf("Hal Temperature: %.2f °C\n", temperature); //print para debug
    return temperature;
}

float hal_temperature_read_rp2040() {
    uint16_t adcValue = rp2040_temp_sensor_read(); // Lê o sensor de temperatura
    printf("Hal ADC Value: %d\n", adcValue); //print para debug
    return adc_to_celsius(adcValue); //devolve o valor convertido para Celsius
}