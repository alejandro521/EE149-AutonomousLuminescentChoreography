#ifndef _MOTORSWITHFEEDBACK_H
#define _MOTORSWITHFEEDBACK_H
#include "include/core/reactor.h"
#include "_picontrol.h"
#include "_motors.h"
#ifndef TOP_LEVEL_PREAMBLE_1926296244_H
#define TOP_LEVEL_PREAMBLE_1926296244_H
#include <math.h>
#define WHEEL_DIAMETER 0.032 // meters
#define COUNTS_PER_REV 360 //CPR
#define TICKS_PER_METER (WHEEL_DIAMETER * M_PI) / COUNTS_PER_REV
#include <motors.h>
#endif
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
} _motorswithfeedback_left_speed_t;
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
} _motorswithfeedback_right_speed_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorswithfeedback_left_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motorswithfeedback_right_t;
typedef struct {
    struct self_base_t base;
    #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    float p_gain;
    #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    float i_gain;
    #line 39 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    interval_t prev_time;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    int32_t prev_left;
    #line 41 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    int32_t prev_right;
    #line 42 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    float target_speed_left;
    #line 43 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    float target_speed_right;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    _motorswithfeedback_left_speed_t* _lf_left_speed;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // width of -2 indicates that it is not a multiport.
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    int _lf_left_speed_width;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Default input (in case it does not get connected)
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    _motorswithfeedback_left_speed_t _lf_default__left_speed;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    _motorswithfeedback_right_speed_t* _lf_right_speed;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // width of -2 indicates that it is not a multiport.
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    int _lf_right_speed_width;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Default input (in case it does not get connected)
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    _motorswithfeedback_right_speed_t _lf_default__right_speed;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    _motorswithfeedback_left_t* _lf_left;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // width of -2 indicates that it is not a multiport.
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    int _lf_left_width;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Default input (in case it does not get connected)
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    _motorswithfeedback_left_t _lf_default__left;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    _motorswithfeedback_right_t* _lf_right;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // width of -2 indicates that it is not a multiport.
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    int _lf_right_width;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Default input (in case it does not get connected)
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    _motorswithfeedback_right_t _lf_default__right;
    struct {
        #line 79 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
        _picontrol_err_t err;
    } _lf_control_left;
    int _lf_control_left_width;
    struct {
        #line 79 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
        _picontrol_err_t err;
    } _lf_control_right;
    int _lf_control_right_width;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    reaction_t _lf__reaction_0;
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    reaction_t _lf__reaction_1;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    reaction_t _lf__reaction_2;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    trigger_t _lf__left_speed;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    reaction_t* _lf__left_speed_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    trigger_t _lf__right_speed;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    reaction_t* _lf__right_speed_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    trigger_t _lf__left;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    reaction_t* _lf__left_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    trigger_t _lf__right;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    reaction_t* _lf__right_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _motorswithfeedback_self_t;
_motorswithfeedback_self_t* new__motorswithfeedback();
#endif // _MOTORSWITHFEEDBACK_H
