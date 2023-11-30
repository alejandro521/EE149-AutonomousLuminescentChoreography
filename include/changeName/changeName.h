#ifndef _changename_main_H
#define _changename_main_H
#ifndef TOP_LEVEL_PREAMBLE_66863151_H
#define TOP_LEVEL_PREAMBLE_66863151_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
/*Correspondence: Range: [(10, 2), (49, 1)) -> Range: [(0, 0), (39, 1)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/changeName.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/uart.h>
#include <hardware/structs/uart.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29
#define MAX_MSG_LENGTH 100



// Function to send a message. The message that was transmitted is written to transmitted_message
static void transmitMessage(uart_inst_t *uart, char *message, char *transmitted_message) {
  int index = 0;
  while (*message && index < MAX_MSG_LENGTH) {
    uart_putc(uart, *message);
    transmitted_message[index] = *message;
    index++;
    message++;
  }
  uart_putc(uart, '\r'); // Carriage return
  uart_putc(uart, '\n'); // newline
  transmitted_message[index] = '\0';
}

// Function to write response from UART to received_message
static void receiveMessage(uart_inst_t *uart, char *received_message) {
  int index = 0;
  char received_char;
  while (uart_is_readable(uart)) { 
    received_char = uart_getc(uart);
    if (index < MAX_MSG_LENGTH - 1) {
      received_message[index] = received_char;
      index += 1;
    }
  }
  received_message[index] = '\0'; // Null terminate the string
}
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct changename_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool led_on;
    char* transmitted_message;
    char* received_message;
    int end[0]; // placeholder; MSVC does not compile empty structs
} changename_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line0_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line1_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line2_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line3_t;
#endif
