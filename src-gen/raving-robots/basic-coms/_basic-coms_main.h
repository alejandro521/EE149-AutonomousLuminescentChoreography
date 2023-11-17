#ifndef _BASIC-COMS_MAIN_H
#define _BASIC-COMS_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1720127312_H
#define TOP_LEVEL_PREAMBLE_1720127312_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/structs/uart.h>
#include <hardware/regs/dreq.h>
#endif
typedef struct {
    struct self_base_t base;
    
    #line 49 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    bool led_on;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    reaction_t _lf__reaction_0;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    reaction_t _lf__reaction_1;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    reaction_t _lf__reaction_2;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    trigger_t _lf__t1;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    reaction_t* _lf__t1_reactions[1];
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    trigger_t _lf__t;
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _basic-coms_main_main_self_t;
_basic-coms_main_main_self_t* new__basic-coms_main();
#endif // _BASIC-COMS_MAIN_H
