#include "include/api/api.h"
#include "include/RobotDriveSolution/RobotDriveSolution.h"
#include "_robotdrivesolution_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _robotdrivesolution_mainreaction_function_0(void* instance_args) {
    _robotdrivesolution_main_main_self_t* self = (_robotdrivesolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct robot {
        _robot_drive_t* drive;
    
    } robot;
    robot.drive = &(self->_lf_robot.drive);
    #line 57 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    lf_set(robot.drive, self->drive);
    // Toggle the drive state variable for next time.
    self->drive = !self->drive;
}
#include "include/api/set_undef.h"
_robotdrivesolution_main_main_self_t* new__robotdrivesolution_main() {
    _robotdrivesolution_main_main_self_t* self = (_robotdrivesolution_main_main_self_t*)_lf_new_reactor(sizeof(_robotdrivesolution_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_robot_width = -2;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.number = 0;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.function = _robotdrivesolution_mainreaction_function_0;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.self = self;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.name = "?";
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__t.last = NULL;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #ifdef FEDERATED
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
