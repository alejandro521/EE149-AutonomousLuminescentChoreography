#ifndef _ROBOT_H
#define _ROBOT_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_motorswithfeedback.h"
#ifndef TOP_LEVEL_PREAMBLE_1110875562_H
#define TOP_LEVEL_PREAMBLE_1110875562_H
#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_drive_mode_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _robot_direction_t;
typedef struct {
    struct self_base_t base;
    
    #line 26 "/Users/alex/149project/src/PololuControl.lf"
    float orientation;
    #line 27 "/Users/alex/149project/src/PololuControl.lf"
    float left_speed;
    #line 28 "/Users/alex/149project/src/PololuControl.lf"
    float right_speed;
    #line 19 "/Users/alex/149project/src/PololuControl.lf"
    _robot_drive_mode_t* _lf_drive_mode;
    #line 19 "/Users/alex/149project/src/PololuControl.lf"
    // width of -2 indicates that it is not a multiport.
    #line 19 "/Users/alex/149project/src/PololuControl.lf"
    int _lf_drive_mode_width;
    #line 19 "/Users/alex/149project/src/PololuControl.lf"
    // Default input (in case it does not get connected)
    #line 19 "/Users/alex/149project/src/PololuControl.lf"
    _robot_drive_mode_t _lf_default__drive_mode;
    #line 20 "/Users/alex/149project/src/PololuControl.lf"
    _robot_direction_t* _lf_direction;
    #line 20 "/Users/alex/149project/src/PololuControl.lf"
    // width of -2 indicates that it is not a multiport.
    #line 20 "/Users/alex/149project/src/PololuControl.lf"
    int _lf_direction_width;
    #line 20 "/Users/alex/149project/src/PololuControl.lf"
    // Default input (in case it does not get connected)
    #line 20 "/Users/alex/149project/src/PololuControl.lf"
    _robot_direction_t _lf_default__direction;
    struct {
        #line 30 "/Users/alex/149project/src/lib/MotorsWithFeedback.lf"
        _motorswithfeedback_left_speed_t left_speed;
        #line 31 "/Users/alex/149project/src/lib/MotorsWithFeedback.lf"
        _motorswithfeedback_right_speed_t right_speed;
    } _lf_motors;
    int _lf_motors_width;
    struct {
        #line 32 "/Users/alex/149project/src/lib/Encoders.lf"
        _encoders_trigger_t trigger;
    } _lf_encoders;
    int _lf_encoders_width;
    #line 33 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t _lf__reaction_0;
    #line 47 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t _lf__reaction_1;
    #line 55 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t _lf__reaction_2;
    #line 68 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t _lf__reaction_3;
    #line 81 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t _lf__reaction_4;
    #line 94 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t _lf__reaction_5;
    #line 30 "/Users/alex/149project/src/PololuControl.lf"
    trigger_t _lf__t;
    #line 30 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t* _lf__t_reactions[3];
    #line 19 "/Users/alex/149project/src/PololuControl.lf"
    trigger_t _lf__drive_mode;
    #line 19 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t* _lf__drive_mode_reactions[3];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 20 "/Users/alex/149project/src/PololuControl.lf"
    trigger_t _lf__direction;
    #line 20 "/Users/alex/149project/src/PololuControl.lf"
    reaction_t* _lf__direction_reactions[2];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[3];
} _robot_self_t;
_robot_self_t* new__robot();
#endif // _ROBOT_H
