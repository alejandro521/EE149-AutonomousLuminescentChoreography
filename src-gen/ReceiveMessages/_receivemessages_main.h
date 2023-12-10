#ifndef _RECEIVEMESSAGES_MAIN_H
#define _RECEIVEMESSAGES_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_1411487742_H
#define TOP_LEVEL_PREAMBLE_1411487742_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/uart.h>
#include <hardware/structs/uart.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29
#define MAX_MSG_LENGTH 100

// COMMANDS TO POLOLU GO HERE
static char SET_NAME_COMMAND[10] = "SET_NAME:";

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
typedef struct {
    struct self_base_t base;
    
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    bool led_on;
    #line 57 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    char* transmitted_message;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    char* received_message;
    #line 59 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    char* name;
    struct {
        #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line2_t line2;
    } _lf_disp;
    int _lf_disp_width;
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    reaction_t _lf__reaction_0;
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    reaction_t _lf__reaction_1;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    trigger_t _lf__t;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _receivemessages_main_main_self_t;
_receivemessages_main_main_self_t* new__receivemessages_main();
#endif // _RECEIVEMESSAGES_MAIN_H
