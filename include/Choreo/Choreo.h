#ifndef _choreo_main_H
#define _choreo_main_H
#ifndef TOP_LEVEL_PREAMBLE_468457220_H
#define TOP_LEVEL_PREAMBLE_468457220_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
/*Correspondence: Range: [(22, 2), (23, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf)*/#include <pico/stdlib.h>
#include <imu.h>
/*Correspondence: Range: [(18, 2), (18, 21)) -> Range: [(0, 0), (0, 19)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Motors.lf)*/#include <motors.h>
/*Correspondence: Range: [(9, 4), (9, 21)) -> Range: [(0, 0), (0, 17)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf)*/#include <math.h>
/*Correspondence: Range: [(19, 2), (27, 17)) -> Range: [(0, 0), (8, 17)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Encoders.lf)*/#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
/*Correspondence: Range: [(15, 4), (57, 1)) -> Range: [(0, 0), (42, 1)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf)*/#include <math.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/uart.h>
#include <hardware/structs/uart.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29
#define MAX_MSG_LENGTH 100

#define RED_LED_PIN 7
#define YELLOW_LED_PIN 27
#define GREEN_LED_PIN 24

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
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct choreo_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    char* transmitted_message;
    char* received_message;
    float previousDistance;
    float previousAngle;
    bool leds_on;
    float leds_speed;
    float speed;
    float target_distance;
    int end[0]; // placeholder; MSVC does not compile empty structs
} choreo_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motors_left_power_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motors_right_power_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} encoders_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} encoders_right_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} encoders_left_t;
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

} gyroangle_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} gyroangle_x_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} gyroangle_y_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} gyroangle_z_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} angletodistance_degrees_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} angletodistance_distance_t;
#endif