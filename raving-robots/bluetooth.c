#define BAUD_RATE 9600
#define TX_PIN 0
#define RX_PIN 1
#define PICO_DEFAULT_UART 0
#define PICO_DEFAULT_UART_TX_PIN 28
#define PICO_DEFAULT_UART_RX_PIN 29

#include "pico/stdlib.h"

void send(const char* c) {
    for (const char *c = c; *c != '\0'; ++c) {
        uart_putc(PICO_DEFAULT_UART, *c); //Sends one char of data to bluetooth module
    }
    uart_putc(PICO_DEFAULT_UART, '\n');
}

int main() {
    stdio_init_all();
    //Set up UART and set pins
    uart_init(PICO_DEFAULT_UART, BAUD_RATE);
    gpio_set_function(TX_PIN, PICO_DEFAULT_UART_TX_PIN);
    gpio_set_function(RX_PIN, PICO_DEFAULT_UART_RX_PIN);

    send('AT');
    
    //Receive
    while (uart_is_readable(PICO_DEFAULT_UART)) {
        char c = uart_getc(PICO_DEFAULT_UART);
        printf(c);
    }
}