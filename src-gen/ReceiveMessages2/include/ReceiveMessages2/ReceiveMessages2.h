#ifndef _receivemessages2_main_H
#define _receivemessages2_main_H
#ifndef TOP_LEVEL_PREAMBLE_224192895_H
#define TOP_LEVEL_PREAMBLE_224192895_H
/*Correspondence: Range: [(13, 4), (63, 1)) -> Range: [(0, 0), (50, 1)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages2.lf)*/#include <stdio.h>
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
/*Correspondence: Range: [(12, 2), (14, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
/*Correspondence: Range: [(22, 2), (23, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf)*/#include <pico/stdlib.h>
#include <imu.h>
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf)*/#include <pico/stdlib.h>
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
typedef struct receivemessages2_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool led_on;
    char* reply;
    char* transmitted_message;
    char* received_message;
    char* name;
    int counter;
    float x;
    float y;
    int end[0]; // placeholder; MSVC does not compile empty structs
} receivemessages2_self_t;
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
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;

} robot_drive_mode_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;

} robot_direction_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} accelerometer_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} accelerometer_x_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} accelerometer_y_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} accelerometer_z_t;
#endif
