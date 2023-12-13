#include "include/api/api.h"
#include "include/Pololu/Pololu.h"
#include "_pololu.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _pololureaction_function_0(void* instance_args) {
    _pololu_self_t* self = (_pololu_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _pololu_facing_angle_t* facing_angle = &self->_lf_facing_angle;
    #line 46 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    lf_set(facing_angle, 0);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololureaction_function_1(void* instance_args) {
    _pololu_self_t* self = (_pololu_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_trigger_t* trigger;
    
    } gyro;
    struct encoders {
        _encoders_trigger_t* trigger;
    
    } encoders;
    gyro.trigger = &(self->_lf_gyro.trigger);
    encoders.trigger = &(self->_lf_encoders.trigger);
    _pololu_facing_angle_t* facing_angle = &self->_lf_facing_angle;
    #line 50 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    lf_set(gyro.trigger, !gyro.trigger->value);
    lf_set(encoders.trigger, !encoders.trigger->value);
    lf_set(facing_angle, gyro_actual_z);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololureaction_function_2(void* instance_args) {
    _pololu_self_t* self = (_pololu_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    gyro.z = self->_lf_gyro.z;
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    _pololu_current_mode_t* current_mode = &self->_lf_current_mode;
    #line 57 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    lf_set(motors.left_speed, 0);
    lf_set(motors.right_speed, 0);
    self->step_counter = 0;
    self->gyro_start = gyro.z->value;
    lf_set(current_mode, 1);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololureaction_function_3(void* instance_args) {
    _pololu_self_t* self = (_pololu_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    gyro.z = self->_lf_gyro.z;
    reactor_mode_t* STOPPED = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_STOPPED_change_type = reset_transition;
    #line 65 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->step_counter += 1;
    if (self->step_counter >= GYRO_CALIBRATION_TIMESTEPS) {
      self->gyro_bias = (gyro.z->value - self->gyro_start) / GYRO_CALIBRATION_TIMESTEPS; //gyro.z accumulates bias over time, so we divide the total change by the timesteps passed
      lf_set_mode(STOPPED);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololureaction_function_4(void* instance_args) {
    _pololu_self_t* self = (_pololu_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    _pololu_current_mode_t* current_mode = &self->_lf_current_mode;
    #line 75 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    lf_set(motors.left_speed, 0);
    lf_set(motors.right_speed, 0);
    lf_set(current_mode, 2);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololureaction_function_5(void* instance_args) {
    _pololu_self_t* self = (_pololu_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _pololu_drive_mode_t* drive_mode = self->_lf_drive_mode;
    int drive_mode_width = self->_lf_drive_mode_width; SUPPRESS_UNUSED_WARNING(drive_mode_width);
    reactor_mode_t* TURNING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_TURNING_change_type = reset_transition;
    #line 81 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    if (drive_mode->value == 2) {
      lf_set_mode(TURNING);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololureaction_function_6(void* instance_args) {
    _pololu_self_t* self = (_pololu_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    _pololu_drive_direction_t* drive_direction = self->_lf_drive_direction;
    int drive_direction_width = self->_lf_drive_direction_width; SUPPRESS_UNUSED_WARNING(drive_direction_width);
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    _pololu_current_mode_t* current_mode = &self->_lf_current_mode;
    #line 89 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    if (drive_direction->value) {
      lf_set(motors.left_speed, self->left_speed);
      lf_set(motors.right_speed, -self->right_speed);
    } else {
      lf_set(motors.left_speed, -self->left_speed);
      lf_set(motors.right_speed, self->right_speed);
    }
    self->step_counter = 0;
    self->gyro_start = gyro.z;
    lf_set(current_mode, 3);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololureaction_function_7(void* instance_args) {
    _pololu_self_t* self = (_pololu_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    gyro.z = self->_lf_gyro.z;
    _pololu_drive_amount_t* drive_amount = self->_lf_drive_amount;
    int drive_amount_width = self->_lf_drive_amount_width; SUPPRESS_UNUSED_WARNING(drive_amount_width);
    reactor_mode_t* STOPPED = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_STOPPED_change_type = reset_transition;
    #line 102 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->step_counter += 1;
    self->gyro_actual_z = gyro.z - self->gyro_start - (self->gyro_bias * self->step_counter);
    if (abs(self->gyro_actual_z) >= drive_amout->value) {
      lf_set_mode(STOPPED);
    }
}
#include "include/api/set_undef.h"
_pololu_self_t* new__pololu() {
    _pololu_self_t* self = (_pololu_self_t*)_lf_new_reactor(sizeof(_pololu_self_t));
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Set input by default to an always absent default input.
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_drive_mode = &self->_lf_default__drive_mode;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Set the default source reactor pointer
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_default__drive_mode._base.source_reactor = (self_base_t*)self;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Set input by default to an always absent default input.
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_drive_direction = &self->_lf_default__drive_direction;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Set the default source reactor pointer
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_default__drive_direction._base.source_reactor = (self_base_t*)self;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Set input by default to an always absent default input.
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_drive_amount = &self->_lf_default__drive_amount;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    // Set the default source reactor pointer
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_default__drive_amount._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_gyro_width = -2;
    #line 125 "/home/foobar/149project/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 125 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 125 "/home/foobar/149project/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 125 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.last = NULL;
    #line 125 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.number_of_reactions = 0;
    #line 125 "/home/foobar/149project/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 125 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.physical_time_of_arrival = NEVER;
    #line 125 "/home/foobar/149project/src/lib/IMU.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_encoders_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_motors_width = -2;
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_0.number = 0;
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_0.function = _pololureaction_function_0;
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_0.self = self;
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_0.name = "?";
    #line 45 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_1.number = 1;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_1.function = _pololureaction_function_1;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_1.self = self;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_1.name = "?";
    #line 49 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 56 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_2.number = 2;
    #line 56 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_2.function = _pololureaction_function_2;
    #line 56 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_2.self = self;
    #line 56 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 56 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 56 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_2.name = "?";
    #line 56 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    #line 64 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_3.number = 3;
    #line 64 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_3.function = _pololureaction_function_3;
    #line 64 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_3.self = self;
    #line 64 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 64 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 64 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_3.name = "?";
    #line 64 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[0];
    #line 74 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_4.number = 4;
    #line 74 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_4.function = _pololureaction_function_4;
    #line 74 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_4.self = self;
    #line 74 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 74 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 74 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_4.name = "?";
    #line 74 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[1];
    #line 80 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_5.number = 5;
    #line 80 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_5.function = _pololureaction_function_5;
    #line 80 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_5.self = self;
    #line 80 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 80 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 80 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_5.name = "?";
    #line 80 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_5.mode = &self->_lf__modes[1];
    #line 88 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_6.number = 6;
    #line 88 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_6.function = _pololureaction_function_6;
    #line 88 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_6.self = self;
    #line 88 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 88 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 88 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_6.name = "?";
    #line 88 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_6.mode = &self->_lf__modes[2];
    #line 101 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_7.number = 7;
    #line 101 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_7.function = _pololureaction_function_7;
    #line 101 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_7.self = self;
    #line 101 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_7.deadline_violation_handler = NULL;
    #line 101 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_7.STP_handler = NULL;
    #line 101 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_7.name = "?";
    #line 101 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__reaction_7.mode = &self->_lf__modes[2];
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__t.last = NULL;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__t_reactions[1] = &self->_lf__reaction_3;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__t_reactions[2] = &self->_lf__reaction_7;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__t.number_of_reactions = 3;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 43 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup_reactions[1] = &self->_lf__reaction_2;
    self->_lf__startup_reactions[2] = &self->_lf__reaction_4;
    self->_lf__startup_reactions[3] = &self->_lf__reaction_6;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 4;
    self->_lf__startup.is_timer = false;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_mode.last = NULL;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_mode.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_mode_reactions[0] = &self->_lf__reaction_5;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_mode.reactions = &self->_lf__drive_mode_reactions[0];
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_mode.number_of_reactions = 1;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_mode.physical_time_of_arrival = NEVER;
    #line 23 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED
    self->_lf__drive_mode.tmplt.type.element_size = sizeof(int);
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_direction.last = NULL;
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_direction.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 24 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__drive_direction.tmplt.type.element_size = sizeof(bool);
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_amount.last = NULL;
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__drive_amount.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 25 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__drive_amount.tmplt.type.element_size = sizeof(float);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 55 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 55 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[0].name = "CALIBRATING_GYRO";
    #line 55 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 55 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[0].flags = 0;
    #line 73 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 73 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[1].name = "STOPPED";
    #line 73 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 73 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[1].flags = 0;
    #line 87 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    #line 87 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[2].name = "TURNING";
    #line 87 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[2].deactivation_time = 0;
    #line 87 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf__modes[2].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
