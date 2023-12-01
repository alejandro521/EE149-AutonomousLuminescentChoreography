#include "include/api/api.h"
#include "include/RobotDriveSolution/Robot.h"
#include "_robot.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _robotreaction_function_0(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _robot_notify_t* notify = &self->_lf_notify;
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    lf_set(notify, "INIT");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_1(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } m;
    _robot_drive_t* drive = self->_lf_drive;
    int drive_width = self->_lf_drive_width; SUPPRESS_UNUSED_WARNING(drive_width);
    reactor_mode_t* DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    _robot_notify_t* notify = &self->_lf_notify;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    if (drive->value) {
      lf_set_mode(DRIVING);
      lf_set(m.left_power, 0.1f);
      lf_set(m.right_power, 0.1f);
      lf_set(notify, "DRIVING");
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotreaction_function_2(void* instance_args) {
    _robot_self_t* self = (_robot_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } m;
    _robot_drive_t* drive = self->_lf_drive;
    int drive_width = self->_lf_drive_width; SUPPRESS_UNUSED_WARNING(drive_width);
    reactor_mode_t* STOPPED = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_STOPPED_change_type = reset_transition;
    _robot_notify_t* notify = &self->_lf_notify;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    #line 41 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    if (!drive->value) {
      lf_set_mode(STOPPED);
      lf_set(m.left_power, 0.0f);
      lf_set(m.right_power, 0.0f);
      lf_set(notify, "STOPPED");
    }
}
#include "include/api/set_undef.h"
_robot_self_t* new__robot() {
    _robot_self_t* self = (_robot_self_t*)_lf_new_reactor(sizeof(_robot_self_t));
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    // Set input by default to an always absent default input.
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf_drive = &self->_lf_default__drive;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    // Set the default source reactor pointer
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf_default__drive._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_m_width = -2;
    #line 24 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.number = 0;
    #line 24 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.function = _robotreaction_function_0;
    #line 24 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.self = self;
    #line 24 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 24 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 24 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.name = "?";
    #line 24 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 29 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_1.number = 1;
    #line 29 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_1.function = _robotreaction_function_1;
    #line 29 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_1.self = self;
    #line 29 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 29 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 29 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_1.name = "?";
    #line 29 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_1.mode = &self->_lf__modes[0];
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_2.number = 2;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_2.function = _robotreaction_function_2;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_2.self = self;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_2.name = "?";
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[1];
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__drive.last = NULL;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__drive.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__drive_reactions[0] = &self->_lf__reaction_1;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__drive_reactions[1] = &self->_lf__reaction_2;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__drive.reactions = &self->_lf__drive_reactions[0];
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__drive.number_of_reactions = 2;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #ifdef FEDERATED
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__drive.physical_time_of_arrival = NEVER;
    #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #endif // FEDERATED
    self->_lf__drive.tmplt.type.element_size = sizeof(bool);
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__modes[0].name = "STOPPED";
    #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__modes[0].flags = 0;
    #line 39 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 39 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__modes[1].name = "DRIVING";
    #line 39 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 39 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__modes[1].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
