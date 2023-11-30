#ifndef _CHANGENAME_MAIN_H
#define _CHANGENAME_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_718803389_H
#define TOP_LEVEL_PREAMBLE_718803389_H
#include <stdio.h>
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
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif
typedef struct {
    struct self_base_t base;
    
    #line 45 "/home/foobar/finalproject/src/changeName.lf"
    bool led_on;
    #line 46 "/home/foobar/finalproject/src/changeName.lf"
    char* message_sent;
    #line 47 "/home/foobar/finalproject/src/changeName.lf"
    char* message_received;
    struct {
        #line 25 "/home/foobar/finalproject/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/finalproject/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/finalproject/src/lib/Display.lf"
        _display_line2_t line2;
    } _lf_disp;
    int _lf_disp_width;
    #line 50 "/home/foobar/finalproject/src/changeName.lf"
    reaction_t _lf__reaction_0;
    #line 65 "/home/foobar/finalproject/src/changeName.lf"
    reaction_t _lf__reaction_1;
    #line 44 "/home/foobar/finalproject/src/changeName.lf"
    trigger_t _lf__t;
    #line 44 "/home/foobar/finalproject/src/changeName.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _changename_main_main_self_t;
_changename_main_main_self_t* new__changename_main();
#endif // _CHANGENAME_MAIN_H
