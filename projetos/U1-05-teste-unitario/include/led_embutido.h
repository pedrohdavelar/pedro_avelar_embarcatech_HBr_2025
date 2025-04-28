#ifndef LED_EMBUTIDO_H
#define LED_EMBUTIDO_H

#include <stdbool.h> // Inclui o cabeçalho para bool, true e false

void led_embutido_init(void);
void led_embutido_set(bool state);

#endif // LED_EMBUTIDO_H