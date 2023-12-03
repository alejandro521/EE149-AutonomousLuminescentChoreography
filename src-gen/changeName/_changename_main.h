#ifndef _CHANGENAME_MAIN_H
#define _CHANGENAME_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_179441020_H
#define TOP_LEVEL_PREAMBLE_179441020_H
#include <stdio.h>
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
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif
typedef struct {
    struct self_base_t base;
    
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/changeName.lf"
    bool led_on;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/changeName.lf"
    char* transmitted_message;
    #line 57 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/changeName.lf"
    char* received_message;
    struct {
        #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line2_t line2;
    } _lf_disp;
    int _lf_disp_width;
    #line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/changeName.lf"
    reaction_t _lf__reaction_0;
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/changeName.lf"
    reaction_t _lf__reaction_1;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/changeName.lf"
    trigger_t _lf__t;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/changeName.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _changename_main_main_self_t;
_changename_main_main_self_t* new__changename_main();
#endif // _CHANGENAME_MAIN_H
