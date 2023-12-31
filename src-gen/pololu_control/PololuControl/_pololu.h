#ifndef _POLOLU_H
#define _POLOLU_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_gyroangle.h"
#include "_motorswithfeedback.h"
#ifndef TOP_LEVEL_PREAMBLE_2140322192_H
#define TOP_LEVEL_PREAMBLE_2140322192_H
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#include <pico/stdlib.h>
#include <imu.h>
#include <stdlib.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <math.h>

#define GYRO_CALIBRATION_TIMESTEPS 1600
#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
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
} _pololu_speed_t;
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
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pololu_current_mode_t;
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
} _pololu_completion_notify_t;
typedef struct {
    struct self_base_t base;
    
    #line 38 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float left_speed;
    #line 39 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float right_speed;
    #line 41 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int step_counter;
    #line 42 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float z_angle;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float start_angle;
    #line 44 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float goal_angle;
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float gyro_actual_z;
    #line 46 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float gyro_start;
    #line 47 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    float gyro_bias;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_mode_t* _lf_drive_mode;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // width of -2 indicates that it is not a multiport.
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_drive_mode_width;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Default input (in case it does not get connected)
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_mode_t _lf_default__drive_mode;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_direction_t* _lf_drive_direction;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // width of -2 indicates that it is not a multiport.
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_drive_direction_width;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Default input (in case it does not get connected)
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_direction_t _lf_default__drive_direction;
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_amount_t* _lf_drive_amount;
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // width of -2 indicates that it is not a multiport.
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_drive_amount_width;
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Default input (in case it does not get connected)
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_drive_amount_t _lf_default__drive_amount;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_speed_t* _lf_speed;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // width of -2 indicates that it is not a multiport.
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_speed_width;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Default input (in case it does not get connected)
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_speed_t _lf_default__speed;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_facing_angle_t _lf_facing_angle;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_facing_angle_width;
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_current_mode_t _lf_current_mode;
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_current_mode_width;
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    _pololu_completion_notify_t _lf_completion_notify;
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    int _lf_completion_notify_width;
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
    #line 51 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_0;
    #line 55 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_1;
    #line 62 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_2;
    #line 70 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_3;
    #line 83 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_4;
    #line 115 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_5;
    #line 123 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_6;
    #line 140 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t _lf__reaction_7;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__t;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t* _lf__t_reactions[4];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[2];
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__drive_mode;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t* _lf__drive_mode_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__drive_direction;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__drive_amount;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    trigger_t _lf__speed;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    reaction_t* _lf__speed_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    reactor_mode_t _lf__modes[4];
} _pololu_self_t;
_pololu_self_t* new__pololu();
#endif // _POLOLU_H
