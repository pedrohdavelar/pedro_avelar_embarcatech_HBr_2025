# Prática - Teste Unitário
Projeto simples para demonstrar a realização de teste unitário com a biblioteca Unity.

São realizados dois testes:

- Teste da função adc_to_celsius, responsável por converter o valor lido pelo sensor de temperatura do RP2040 para um valor em celsius. O teste usa o valor de entrada 866 e espera um desvio de até 0.1 do valor esperado de 27°C

- Teste da função hal_temperature_read_rp2040, responsável por ler o valor do sensor de temperatura e depois chamar a função adc_to_celsius para então retornar a temperatura. O teste aceita uma oscilação de 5°C do valor esperado de 27°C - geralmente o RP2040 costuma operar bem próximo da temperatura ambiente.
