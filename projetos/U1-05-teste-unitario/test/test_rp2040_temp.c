#include <stdio.h>
#include "pico/stdlib.h"
#include "hal_led.h"
#include "led_embutido.h"
#include "hal_rp2040_temp.h"
#include "Unity/unity.h"


void setUp() {
    // Configurações antes de cada teste
    }

void tearDown() {
    // Limpeza após cada teste (opcional)
}

void test_temperature_read_rp2040() {
    // Simula um valor ADC conhecido
    float expectedTemp = 27.0f;
    uint16_t adcValue = 876; // Valor ADC simulado para o teste
    printf("Valor ADC simulado: %d\n", adcValue); //print para debug
    float actualTemp = 0.0f;
    printf("Temperatura inicializada: %.2f °C\n", actualTemp); //print para debug
    actualTemp = adc_to_celsius(adcValue); // Função a ser testada
    printf("Temperatura calculada: %.2f °C\n", actualTemp); //print para debug

    // Verifica se o resultado está dentro de uma margem de erro aceitável
    TEST_ASSERT_FLOAT_WITHIN(0.1f, expectedTemp, actualTemp);
}


void test_actual_temperature_read_rp2040(){
    float expectedTemp = 27.0f;
    float readTemp = hal_temperature_read_rp2040();
    printf("Temperatura lida: %.2f °C\n", readTemp); //print para debug
    TEST_ASSERT_FLOAT_WITHIN(5.0f, expectedTemp, readTemp); // Verifica se a temperatura lida está dentro de uma margem de erro aceitável
}

int main(void) {
    stdio_init_all();
    led_embutido_init();
    rp2040_temp_sensor_init(); 
    
    while(true){
        UNITY_BEGIN();

        // Executa os testes
        RUN_TEST(test_temperature_read_rp2040);
        RUN_TEST(test_actual_temperature_read_rp2040);
        printf("Testes concluídos.\n");
        hal_led_toggle();
        sleep_ms(3500);
    }

    return 0;
}