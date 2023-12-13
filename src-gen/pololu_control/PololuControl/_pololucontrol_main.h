#ifndef _POLOLUCONTROL_MAIN_H
#define _POLOLUCONTROL_MAIN_H
#include "include/core/reactor.h"
#include "_bluetooth.h"
#include "_pololu.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_1454136448_H
#define TOP_LEVEL_PREAMBLE_1454136448_H
#include <stdlib.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <math.h>

#define GYRO_CALIBRATION_TIMESTEPS 1600
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>

static bool matchesCommand(str, command) {
  return strncmp(command, str, strlen(command)) == 0;
}
#ifndef BLUETOOTH_FUNCTIONS_H
#define BLUETOOTH_FUNCTIONS_H
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
  transmitted_message[index] = '\0';
}

// Function to write response from UART to incoming_message, returns true if there is a new message
static bool receiveMessage(uart_inst_t *uart, char *incoming_message) {
  int index = 0;
  char received_char = 'a'; //'a' is just to initialize received_char to a character that is not \r
  char end_char = '\r';
  bool received_new_message = false;
  if (uart_is_readable(uart)) {
    while (received_char != end_char) { 
      received_char = uart_getc(uart);
      if (index < MAX_MSG_LENGTH - 1 && received_char != end_char) {
        incoming_message[index] = received_char;
        index += 1;
      }
    }
    received_new_message = true;
  } 
  incoming_message[index] = '\0'; // Null terminate the string
  return received_new_message;
}

#endif // BLUETOOTH_FUNCTIONS_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif
typedef struct {
    struct self_base_t base;
    
    #line 29 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    char* TURN_LEFT_COMMAND;
    #line 30 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    char* TURN_RIGHT_COMMAND;
    #line 31 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    char* MOVE_FORWARD_COMMAND;
    #line 32 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    char* MOVE_BACKWARD_COMMAND;
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    char* STOP_COMMAND;
    struct {
        #line 25 "/home/foobar/149project/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/149project/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/149project/src/lib/Display.lf"
        _display_line2_t line2;
        #line 28 "/home/foobar/149project/src/lib/Display.lf"
        _display_line3_t line3;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        _pololu_drive_mode_t drive_mode;
        #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        _pololu_drive_direction_t drive_direction;
        #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        _pololu_drive_amount_t drive_amount;
        #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        _pololu_current_mode_t* current_mode;
        #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        trigger_t current_mode_trigger;
        #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        reaction_t* current_mode_reactions[1];
        #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        _pololu_facing_angle_t* facing_angle;
        #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        trigger_t facing_angle_trigger;
        #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
        reaction_t* facing_angle_reactions[1];
    } _lf_pololu;
    int _lf_pololu_width;
    struct {
        #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
        _bluetooth_outgoing_message_t outgoing_message;
        #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
        _bluetooth_incoming_message_t* incoming_message;
        #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
        trigger_t incoming_message_trigger;
        #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
        reaction_t* incoming_message_reactions[1];
    } _lf_bluetooth;
    int _lf_bluetooth_width;
    #line 45 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    reaction_t _lf__reaction_0;
    #line 80 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    reaction_t _lf__reaction_1;
    #line 86 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    reaction_t _lf__reaction_2;
    #line 27 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    trigger_t _lf__t;
} _pololucontrol_main_main_self_t;
_pololucontrol_main_main_self_t* new__pololucontrol_main();
#endif // _POLOLUCONTROL_MAIN_H
