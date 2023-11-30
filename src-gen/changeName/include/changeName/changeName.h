#ifndef _changename_main_H
#define _changename_main_H
#ifndef TOP_LEVEL_PREAMBLE_718803389_H
#define TOP_LEVEL_PREAMBLE_718803389_H
/*Correspondence: Range: [(11, 2), (39, 1)) -> Range: [(0, 0), (28, 1)) (verbatim=true; src=/home/foobar/finalproject/src/changeName.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/uart.h>
#include <hardware/structs/uart.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29

// Function to send AT command and return the command string
static char* sendATCommand(uart_inst_t *uart, const char *command) {
  const char *tempCommand = command;
  while (*tempCommand) {
    uart_putc(uart, *tempCommand++);
  }
  uart_putc(uart, '\r'); // Carriage return to execute the command
  return command;
}

// Function to read response from UART and return the response string
static char* readUARTResponse(uart_inst_t *uart, char *response, int maxLength) {
  int count = 0;
  while (uart_is_readable(uart) && count < maxLength - 1) {
      response[count++] = uart_getc(uart);
  }
  response[count] = '\0'; // Null terminate the string
  return response;
}
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/foobar/finalproject/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
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
    char* message_sent;
    char* message_received;
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
