#ifndef _RECEIVEMESSAGES2_MAIN_H
#define _RECEIVEMESSAGES2_MAIN_H
#include "include/core/reactor.h"
#include "_accelerometer.h"
#include "_display.h"
#include "_robot.h"
#ifndef TOP_LEVEL_PREAMBLE_188987857_H
#define TOP_LEVEL_PREAMBLE_188987857_H
#include <pico/stdlib.h>
#include <imu.h>
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
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
  return strncmp(command, str, strlen(command)) == 0;
}
#endif
typedef struct {
    struct self_base_t base;
    
    #line 69 "/Users/alex/149project/src/ReceiveMessages2.lf"
    bool led_on;
    #line 70 "/Users/alex/149project/src/ReceiveMessages2.lf"
    char* reply;
    #line 71 "/Users/alex/149project/src/ReceiveMessages2.lf"
    char* transmitted_message;
    #line 72 "/Users/alex/149project/src/ReceiveMessages2.lf"
    char* received_message;
    #line 73 "/Users/alex/149project/src/ReceiveMessages2.lf"
    char* name;
    #line 74 "/Users/alex/149project/src/ReceiveMessages2.lf"
    int counter;
    #line 75 "/Users/alex/149project/src/ReceiveMessages2.lf"
    float x;
    #line 76 "/Users/alex/149project/src/ReceiveMessages2.lf"
    float y;
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
        #line 40 "/Users/alex/149project/src/lib/IMU.lf"
        _accelerometer_x_t* x;
        #line 40 "/Users/alex/149project/src/lib/IMU.lf"
        trigger_t x_trigger;
        #line 41 "/Users/alex/149project/src/lib/IMU.lf"
        _accelerometer_y_t* y;
        #line 41 "/Users/alex/149project/src/lib/IMU.lf"
        trigger_t y_trigger;
    } _lf_acc;
    int _lf_acc_width;
    #line 82 "/Users/alex/149project/src/ReceiveMessages2.lf"
    reaction_t _lf__reaction_0;
    #line 97 "/Users/alex/149project/src/ReceiveMessages2.lf"
    reaction_t _lf__reaction_1;
    #line 118 "/Users/alex/149project/src/ReceiveMessages2.lf"
    reaction_t _lf__reaction_2;
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    trigger_t _lf__t;
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    reaction_t* _lf__t_reactions[2];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    reactor_mode_t _lf__modes[1];
} _receivemessages2_main_main_self_t;
_receivemessages2_main_main_self_t* new__receivemessages2_main();
#endif // _RECEIVEMESSAGES2_MAIN_H
