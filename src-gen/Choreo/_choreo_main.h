#ifndef _CHOREO_MAIN_H
#define _CHOREO_MAIN_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_display.h"
#include "_gyroangle.h"
#include "_angletodistance.h"
#include "_line.h"
#include "_motors.h"
#ifndef TOP_LEVEL_PREAMBLE_1591683105_H
#define TOP_LEVEL_PREAMBLE_1591683105_H
#include <motors.h>
#include <ir_sensors.h>
#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#include <pico/stdlib.h>
#include <imu.h>
#include <math.h>
#include <stdlib.h>
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
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <math.h>
#endif
typedef struct {
    struct self_base_t base;
    
    #line 37 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    char* transmitted_message;
    #line 38 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    char* received_message;
    #line 39 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float previousDistance;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float previousAngle;
    #line 41 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    char* next_mode;
    #line 42 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int leds_on;
    #line 43 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float leds_speed;
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float speed;
    #line 45 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    float target_distance;
    #line 46 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int degrees;
    #line 47 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int leds_blink;
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int i;
    #line 49 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int leds_state;
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int x;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int y;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int leftLine;
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int centerLine;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int rightLine;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int threshold;
    struct {
        #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line2_t line2;
        #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line3_t line3;
    } _lf_d;
    int _lf_d_width;
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
        #line 39 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        _line_trigger_t trigger;
        #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        _line_reflect_t* reflect;
        #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        trigger_t reflect_trigger;
        #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        reaction_t* reflect_reactions[1];
    } _lf_line;
    int _lf_line_width;
    struct {
        #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Motors.lf"
        _motors_left_power_t left_power;
        #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Motors.lf"
        _motors_right_power_t right_power;
    } _lf_m;
    int _lf_m_width;
    struct {
        #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
        _angletodistance_distance_t* distance;
        #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
        trigger_t distance_trigger;
        #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
        reaction_t* distance_reactions[1];
    } _lf_angleToDistanceR;
    int _lf_angleToDistanceR_width;
    #line 128 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_0;
    #line 159 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_1;
    #line 191 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_2;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_3;
    #line 226 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_4;
    #line 251 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_5;
    #line 282 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t _lf__reaction_6;
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    trigger_t _lf__t;
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t* _lf__t_reactions[2];
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    trigger_t _lf__t1;
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    reaction_t* _lf__t1_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    reactor_mode_t _lf__modes[4];
} _choreo_main_main_self_t;
_choreo_main_main_self_t* new__choreo_main();
#endif // _CHOREO_MAIN_H
