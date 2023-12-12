#ifndef _RECEIVEMESSAGES_MAIN_H
#define _RECEIVEMESSAGES_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_robot.h"
#ifndef TOP_LEVEL_PREAMBLE_148210119_H
#define TOP_LEVEL_PREAMBLE_148210119_H
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
static char DRIVE_FORWARD_COMMAND[14] = "DRIVE_FORWARD";
static char DRIVE_BACKWARD_COMMAND[15] = "DRIVE_BACKWARD";
static char TURN_LEFT_COMMAND[10] = "TURN_LEFT";
static char TURN_RIGHT_COMMAND[11] = "TURN_RIGHT";

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
  transmitted_message[index] = '\0';
}

// Function to write response from UART to received_message
static void receiveMessage(uart_inst_t *uart, char *received_message) {
  int index = 0;
  char received_char = 'a'; //'a' is just to initialize received_char to a character that is not \r
  char end_char = '\r';
  if (uart_is_readable(uart)) {
    while (received_char != end_char) { 
      received_char = uart_getc(uart);
      if (index < MAX_MSG_LENGTH - 1 && received_char != end_char) {
        received_message[index] = received_char;
        index += 1;
      }
    }
  }
  received_message[index] = '\0'; // Null terminate the string
}

static bool matchesCommand(command, str) {
  return strncmp(command, str, strlen(command)) == 0
}
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif
typedef struct {
    struct self_base_t base;
    
    #line 67 "/Users/alex/149project/src/ReceiveMessages.lf"
    bool led_on;
    #line 68 "/Users/alex/149project/src/ReceiveMessages.lf"
    char* reply;
    #line 69 "/Users/alex/149project/src/ReceiveMessages.lf"
    char* transmitted_message;
    #line 70 "/Users/alex/149project/src/ReceiveMessages.lf"
    char* received_message;
    #line 71 "/Users/alex/149project/src/ReceiveMessages.lf"
    char* name;
    struct {
        #line 25 "/Users/alex/149project/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/Users/alex/149project/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/Users/alex/149project/src/lib/Display.lf"
        _display_line2_t line2;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        #line 19 "/Users/alex/149project/src/PololuControl.lf"
        _robot_drive_mode_t drive_mode;
        #line 20 "/Users/alex/149project/src/PololuControl.lf"
        _robot_direction_t direction;
    } _lf_pololu;
    int _lf_pololu_width;
    #line 76 "/Users/alex/149project/src/ReceiveMessages.lf"
    reaction_t _lf__reaction_0;
    #line 91 "/Users/alex/149project/src/ReceiveMessages.lf"
    reaction_t _lf__reaction_1;
    #line 112 "/Users/alex/149project/src/ReceiveMessages.lf"
    reaction_t _lf__reaction_2;
    #line 136 "/Users/alex/149project/src/ReceiveMessages.lf"
    reaction_t _lf__reaction_3;
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    trigger_t _lf__t;
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    reaction_t* _lf__t_reactions[3];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    reactor_mode_t _lf__modes[2];
} _receivemessages_main_main_self_t;
_receivemessages_main_main_self_t* new__receivemessages_main();
#endif // _RECEIVEMESSAGES_MAIN_H
