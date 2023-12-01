#ifndef _ROBOTDRIVESOLUTION_MAIN_H
#define _ROBOTDRIVESOLUTION_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_robot.h"
#ifndef TOP_LEVEL_PREAMBLE_1099694603_H
#define TOP_LEVEL_PREAMBLE_1099694603_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif
typedef struct {
    struct self_base_t base;
    
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    bool drive;
    struct {
        #line 19 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
        _robot_drive_t drive;
    } _lf_robot;
    int _lf_robot_width;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    reaction_t _lf__reaction_0;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    trigger_t _lf__t;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/RobotDriveSolution.lf"
    reaction_t* _lf__t_reactions[1];
} _robotdrivesolution_main_main_self_t;
_robotdrivesolution_main_main_self_t* new__robotdrivesolution_main();
#endif // _ROBOTDRIVESOLUTION_MAIN_H
