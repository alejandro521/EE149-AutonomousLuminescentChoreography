#include "include/api/api.h"
#include "include/PololuControl/Robot.h"
#include "_robot.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _robotreaction_function_0(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robot_drive_mode_t* drive_mode = self->_lf_drive_mode;
    int drive_mode_width = self->_lf_drive_mode_width; SUPPRESS_UNUSED_WARNING(drive_mode_width);
    reactor_mode_t* STOPPED = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_STOPPED_change_type = reset_transition;
    reactor_mode_t* DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    reactor_mode_t* TURNING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_TURNING_change_type = reset_transition;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    switch (drive_mode->value) {
      case 0: 
        lf_set_mode(STOPPED);
        break;
      case 1:
        lf_set_mode(DRIVING);
        break;
      case 2:
        lf_set_mode(TURNING);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_1(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    struct encoders {
        _encoders_trigger_t* trigger;
    
    } encoders;
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    encoders.trigger = &(self->_lf_encoders.trigger);
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    lf_set(encoders.trigger, !encoders.trigger->value);
    lf_set(motors.left_speed, 0);
    lf_set(motors.right_speed, 0);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_2(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robot_drive_mode_t* drive_mode = self->_lf_drive_mode;
    int drive_mode_width = self->_lf_drive_mode_width; SUPPRESS_UNUSED_WARNING(drive_mode_width);
    reactor_mode_t* STOPPED = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_STOPPED_change_type = reset_transition;
    reactor_mode_t* DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    reactor_mode_t* TURNING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_TURNING_change_type = reset_transition;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    switch (drive_mode->value) {
      case 0: 
        lf_set_mode(STOPPED);
        break;
      case 1:
        lf_set_mode(DRIVING);
        break;
      case 2:
        lf_set_mode(TURNING);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_3(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    struct encoders {
        _encoders_trigger_t* trigger;
    
    } encoders;
    _robot_direction_t* direction = self->_lf_direction;
    int direction_width = self->_lf_direction_width; SUPPRESS_UNUSED_WARNING(direction_width);
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    encoders.trigger = &(self->_lf_encoders.trigger);
    #line 69 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    lf_set(encoders.trigger, !encoders.trigger->value);
    if (direction->value) {
      lf_set(motors.left_speed, -self->left_speed);
      lf_set(motors.right_speed, -self->right_speed);
    } else {
      lf_set(motors.left_speed, self->left_speed);
      lf_set(motors.right_speed, self->right_speed);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_4(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robot_drive_mode_t* drive_mode = self->_lf_drive_mode;
    int drive_mode_width = self->_lf_drive_mode_width; SUPPRESS_UNUSED_WARNING(drive_mode_width);
    reactor_mode_t* STOPPED = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_STOPPED_change_type = reset_transition;
    reactor_mode_t* DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    reactor_mode_t* TURNING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_TURNING_change_type = reset_transition;
    #line 82 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    switch (drive_mode->value) {
      case 0: 
        lf_set_mode(STOPPED);
        break;
      case 1:
        lf_set_mode(DRIVING);
        break;
      case 2:
        lf_set_mode(TURNING);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_5(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motorswithfeedback_left_speed_t* left_speed;
    _motorswithfeedback_right_speed_t* right_speed;
    
    } motors;
    struct encoders {
        _encoders_trigger_t* trigger;
    
    } encoders;
    _robot_direction_t* direction = self->_lf_direction;
    int direction_width = self->_lf_direction_width; SUPPRESS_UNUSED_WARNING(direction_width);
    motors.left_speed = &(self->_lf_motors.left_speed);
    motors.right_speed = &(self->_lf_motors.right_speed);
    encoders.trigger = &(self->_lf_encoders.trigger);
    #line 95 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    lf_set(encoders.trigger, !encoders.trigger->value);
    if (direction->value) {
      lf_set(motors.left_speed, -self->left_speed);
      lf_set(motors.right_speed, self->right_speed);
    } else {
      lf_set(motors.left_speed, self->left_speed);
      lf_set(motors.right_speed, -self->right_speed);
    }
}
#include "include/api/set_undef.h"
_robot_self_t* new__robot() {
    _robot_self_t* self = (_robot_self_t*)_lf_new_reactor(sizeof(_robot_self_t));
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    // Set input by default to an always absent default input.
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf_drive_mode = &self->_lf_default__drive_mode;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    // Set the default source reactor pointer
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf_default__drive_mode._base.source_reactor = (self_base_t*)self;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    // Set input by default to an always absent default input.
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf_direction = &self->_lf_default__direction;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    // Set the default source reactor pointer
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf_default__direction._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_motors_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_encoders_width = -2;
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_0.number = 0;
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_0.function = _robotreaction_function_0;
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_0.self = self;
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_0.name = "?";
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_0.mode = &self->_lf__modes[0];
    #line 47 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_1.number = 1;
    #line 47 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_1.function = _robotreaction_function_1;
    #line 47 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_1.self = self;
    #line 47 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 47 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 47 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_1.name = "?";
    #line 47 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_1.mode = &self->_lf__modes[0];
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_2.number = 2;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_2.function = _robotreaction_function_2;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_2.self = self;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_2.name = "?";
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[1];
    #line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_3.number = 3;
    #line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_3.function = _robotreaction_function_3;
    #line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_3.self = self;
    #line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_3.name = "?";
    #line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    #line 81 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_4.number = 4;
    #line 81 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_4.function = _robotreaction_function_4;
    #line 81 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_4.self = self;
    #line 81 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 81 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 81 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_4.name = "?";
    #line 81 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[2];
    #line 94 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_5.number = 5;
    #line 94 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_5.function = _robotreaction_function_5;
    #line 94 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_5.self = self;
    #line 94 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 94 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 94 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_5.name = "?";
    #line 94 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__reaction_5.mode = &self->_lf__modes[2];
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__t.last = NULL;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__t_reactions[1] = &self->_lf__reaction_3;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__t_reactions[2] = &self->_lf__reaction_5;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__t.number_of_reactions = 3;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #ifdef FEDERATED
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__drive_mode.last = NULL;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__drive_mode.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__drive_mode_reactions[0] = &self->_lf__reaction_0;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__drive_mode_reactions[1] = &self->_lf__reaction_2;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__drive_mode_reactions[2] = &self->_lf__reaction_4;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__drive_mode.reactions = &self->_lf__drive_mode_reactions[0];
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__drive_mode.number_of_reactions = 3;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #ifdef FEDERATED
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__drive_mode.physical_time_of_arrival = NEVER;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #endif // FEDERATED
    self->_lf__drive_mode.tmplt.type.element_size = sizeof(int);
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__direction.last = NULL;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__direction.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__direction_reactions[0] = &self->_lf__reaction_3;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__direction_reactions[1] = &self->_lf__reaction_5;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__direction.reactions = &self->_lf__direction_reactions[0];
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__direction.number_of_reactions = 2;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #ifdef FEDERATED
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__direction.physical_time_of_arrival = NEVER;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    #endif // FEDERATED
    self->_lf__direction.tmplt.type.element_size = sizeof(int);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[0].name = "STOPPED";
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[0].flags = 0;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[1].name = "DRIVING";
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[1].flags = 0;
    #line 80 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    #line 80 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[2].name = "TURNING";
    #line 80 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[2].deactivation_time = 0;
    #line 80 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/PololuControl.lf"
    self->_lf__modes[2].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
