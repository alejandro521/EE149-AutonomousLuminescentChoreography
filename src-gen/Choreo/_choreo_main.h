#ifndef _CHOREO_MAIN_H
#define _CHOREO_MAIN_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_display.h"
#include "_gyroangle.h"
#include "_angletodistance.h"
#include "_motors.h"
#ifndef TOP_LEVEL_PREAMBLE_468457220_H
#define TOP_LEVEL_PREAMBLE_468457220_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <pico/stdlib.h>
#include <imu.h>
#include <motors.h>
#include <math.h>
#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#include <math.h>
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
typedef struct {
    struct self_base_t base;
    
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    char* transmitted_message;
    #line 63 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    char* received_message;
    #line 64 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float previousDistance;
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float previousAngle;
    #line 66 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    bool leds_on;
    #line 67 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float leds_speed;
    #line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float speed;
    #line 69 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float target_distance;
    struct {
        #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Encoders.lf"
        _encoders_trigger_t trigger;
    } _lf_e;
    int _lf_e_width;
    struct {
        #line 121 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
        _gyroangle_trigger_t trigger;
        #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
        _gyroangle_z_t* z;
        #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
        trigger_t z_trigger;
        #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
        reaction_t* z_reactions[1];
    } _lf_gyro;
    int _lf_gyro_width;
    struct {
        #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Motors.lf"
        _motors_left_power_t left_power;
        #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Motors.lf"
        _motors_right_power_t right_power;
    } _lf_m;
    int _lf_m_width;
    struct {
        #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line0_t line0;
    } _lf_d;
    int _lf_d_width;
    struct {
        #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
        _angletodistance_distance_t* distance;
        #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
        trigger_t distance_trigger;
        #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
        reaction_t* distance_reactions[2];
    } _lf_angleToDistanceR;
    int _lf_angleToDistanceR_width;
    #line 80 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_0;
    #line 102 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_1;
    #line 111 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_2;
    #line 140 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_3;
    #line 154 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_4;
    #line 78 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    trigger_t _lf__t;
    #line 78 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    reactor_mode_t _lf__modes[3];
} _choreo_main_main_self_t;
_choreo_main_main_self_t* new__choreo_main();
#endif // _CHOREO_MAIN_H
