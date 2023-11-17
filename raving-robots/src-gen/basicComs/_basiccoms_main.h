#ifndef _BASICCOMS_MAIN_H
#define _BASICCOMS_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1253396693_H
#define TOP_LEVEL_PREAMBLE_1253396693_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/structs/uart.h>
#include <hardware/regs/dreq.h>
#include <robot-lib/pololu_3pi_2040_robot.h>
#endif
typedef struct {
    struct self_base_t base;
    
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf"
    bool led_on;
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf"
    reaction_t _lf__reaction_0;
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf"
    reaction_t _lf__reaction_1;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf"
    reaction_t _lf__reaction_2;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf"
    trigger_t _lf__t1;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf"
    reaction_t* _lf__t1_reactions[1];
    #line 49 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf"
    trigger_t _lf__t;
    #line 49 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _basiccoms_main_main_self_t;
_basiccoms_main_main_self_t* new__basiccoms_main();
#endif // _BASICCOMS_MAIN_H
