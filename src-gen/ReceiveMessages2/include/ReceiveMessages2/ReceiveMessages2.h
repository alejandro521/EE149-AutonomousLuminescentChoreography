#ifndef _receivemessages2_main_H
#define _receivemessages2_main_H
#ifndef TOP_LEVEL_PREAMBLE_1731275141_H
#define TOP_LEVEL_PREAMBLE_1731275141_H
/*Correspondence: Range: [(22, 2), (23, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/home/foobar/149project/src/lib/IMU.lf)*/#include <pico/stdlib.h>
#include <imu.h>
/*Correspondence: Range: [(13, 4), (33, 1)) -> Range: [(0, 0), (20, 1)) (verbatim=true; src=/home/foobar/149project/src/ReceiveMessages2.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/uart.h>
#include <hardware/structs/uart.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29
#define MAX_MSG_LENGTH 100

// COMMANDS TO POLOLU GO HERE
// static char SET_NAME_COMMAND[10] = "SET_NAME:";
// static char DRIVE_FORWARD_COMMAND[14] = "DRIVE_FORWARD";
// static char DRIVE_BACKWARD_COMMAND[15] = "DRIVE_BACKWARD";
// static char TURN_LEFT_COMMAND[10] = "TURN_LEFT";
// static char TURN_RIGHT_COMMAND[11] = "TURN_RIGHT";

static bool matchesCommand(command, str) {
  return strncmp(command, str, strlen(command)) == 0;
}
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/foobar/149project/src/lib/Display.lf)*/#include <pico/stdlib.h>
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
