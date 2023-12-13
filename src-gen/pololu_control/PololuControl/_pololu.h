#ifndef _POLOLU_H
#define _POLOLU_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_gyroangle.h"
#include "_motorswithfeedback.h"
#ifndef TOP_LEVEL_PREAMBLE_2045382343_H
#define TOP_LEVEL_PREAMBLE_2045382343_H
#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#include <stdlib.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>

int GYRO_CALIBRATION_TIMESTEPs = 400;
#include <pico/stdlib.h>
#include <imu.h>
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
} _pololu_drive_mode_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pololu_drive_direction_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pololu_drive_amount_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pololu_facing_angle_t;
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
} _pololu_current_mode_t;
typedef struct {
    struct self_base_t base;
    
    #line 35 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float left_speed;
    #line 36 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float right_speed;
    #line 38 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int step_counter;
    #line 39 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float gyro_actual_z;
    #line 40 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float gyro_start;
    #line 41 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float gyro_bias;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_mode_t* _lf_drive_mode;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // width of -2 indicates that it is not a multiport.
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_drive_mode_width;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Default input (in case it does not get connected)
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_mode_t _lf_default__drive_mode;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_direction_t* _lf_drive_direction;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // width of -2 indicates that it is not a multiport.
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_drive_direction_width;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Default input (in case it does not get connected)
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_direction_t _lf_default__drive_direction;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_amount_t* _lf_drive_amount;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // width of -2 indicates that it is not a multiport.
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_drive_amount_width;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Default input (in case it does not get connected)
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_amount_t _lf_default__drive_amount;
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_facing_angle_t _lf_facing_angle;
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_facing_angle_width;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_current_mode_t _lf_current_mode;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_current_mode_width;
    struct {
        #line 121 "/home/foobar/149project/src/lib/IMU.lf"
        _gyroangle_trigger_t trigger;
        #line 125 "/home/foobar/149project/src/lib/IMU.lf"
        _gyroangle_z_t* z;
        #line 125 "/home/foobar/149project/src/lib/IMU.lf"
        trigger_t z_trigger;
    } _lf_gyro;
    int _lf_gyro_width;
    struct {
        #line 32 "/home/foobar/149project/src/lib/Encoders.lf"
        _encoders_trigger_t trigger;
    } _lf_encoders;
    int _lf_encoders_width;
    struct {
        #line 30 "/home/foobar/149project/src/lib/MotorsWithFeedback.lf"
        _motorswithfeedback_left_speed_t left_speed;
        #line 31 "/home/foobar/149project/src/lib/MotorsWithFeedback.lf"
        _motorswithfeedback_right_speed_t right_speed;
    } _lf_motors;
    int _lf_motors_width;
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_0;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_1;
    #line 56 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_2;
    #line 64 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_3;
    #line 74 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_4;
    #line 80 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_5;
    #line 88 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_6;
    #line 101 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_7;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__t;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t* _lf__t_reactions[3];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[4];
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__drive_mode;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t* _lf__drive_mode_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__drive_direction;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__drive_amount;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[3];
} _pololu_self_t;
_pololu_self_t* new__pololu();
#endif // _POLOLU_H
