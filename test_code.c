#include "mbed.h"

DigitalIn button(SW2);  // Botón de entrada
DigitalOut led(LED1);   // LED de salida

int main() {
    int count = 0;      // Contador de pulsaciones del botón
    while (1) {
        if (button == 0) {    // Si el botón está presionado
            wait_ms(10);      // Espera para evitar rebotes
            if (button == 0) {  // Si el botón sigue presionado después de la espera
                count++;         // Incrementa el contador de pulsaciones
                while (button == 0);  // Espera a que se suelte el botón
            }
        }
        if (count == 3) {      // Si se han pulsado 3 veces
            wait_ms(2000);     // Espera 2 segundos
            for (int i = 0; i < 3; i++) {
                led = 1;           // Enciende el LED
                wait_ms(200);      // Espera 200 ms
                led = 0;           // Apaga el LED
                wait_ms(200);      // Espera 200 ms
            }
            count = 0;           // Reinicia el contador de pulsaciones
        }
        if (count == 4) {      // Si se han pulsado 4 veces
            wait_ms(1000);     // Espera 1 segundo
            for (int i = 0; i < 4; i++) {
                led = 1;           // Enciende el LED
                wait_ms(200);      // Espera 200 ms
                led = 0;           // Apaga el LED
                wait_ms(200);      // Espera 200 ms
            }
            count = 0;           // Reinicia el contador de pulsaciones
        }
    }
}