#ifndef _pololucontrol_main_H
#define _pololucontrol_main_H
#ifndef TOP_LEVEL_PREAMBLE_1776589441_H
#define TOP_LEVEL_PREAMBLE_1776589441_H
/*Correspondence: Range: [(14, 2), (20, 1)) -> Range: [(0, 0), (6, 1)) (verbatim=true; src=/home/foobar/149project/src/pololu_control/PololuControl.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>

static bool matchesCommand(str, command) {
  return strncmp(command, str, strlen(command)) == 0;
}
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/foobar/149project/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
/*Correspondence: Range: [(13, 2), (19, 39)) -> Range: [(0, 0), (6, 39)) (verbatim=true; src=/home/foobar/149project/src/pololu_control/Pololu.lf)*/#include <stdlib.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <math.h>

#define GYRO_CALIBRATION_TIMESTEPS 1600
/*Correspondence: Range: [(9, 4), (55, 31)) -> Range: [(0, 0), (46, 31)) (verbatim=true; src=/home/foobar/149project/src/pololu_control/Bluetooth.lf)*/#ifndef BLUETOOTH_FUNCTIONS_H
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
/*Correspondence: Range: [(9, 4), (16, 24)) -> Range: [(0, 0), (7, 24)) (verbatim=true; src=/home/foobar/149project/src/pololu_control/Lights.lf)*/#include <stdlib.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>

#define RED_LED_PIN 7
#define YELLOW_LED_PIN 27
#define GREEN_LED_PIN 24
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct pololucontrol_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    char* TURN_LEFT_COMMAND;
    char* TURN_RIGHT_COMMAND;
    char* MOVE_FORWARD_COMMAND;
    char* MOVE_BACKWARD_COMMAND;
    char* SET_SPEED_COMMAND;
    char* reply;
    int end[0]; // placeholder; MSVC does not compile empty structs
} pololucontrol_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;

} pololu_drive_mode_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} pololu_drive_direction_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} pololu_drive_amount_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} pololu_speed_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} pololu_facing_angle_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} pololu_current_mode_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} pololu_completion_notify_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} bluetooth_outgoing_message_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} bluetooth_incoming_message_t;
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
