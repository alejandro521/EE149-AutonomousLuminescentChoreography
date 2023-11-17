#ifndef _BLINK_MAIN_H
#define _BLINK_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1894287849_H
#define TOP_LEVEL_PREAMBLE_1894287849_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif
typedef struct {
    struct self_base_t base;
    
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Blink.lf"
    bool led_on;
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Blink.lf"
    reaction_t _lf__reaction_0;
    #line 29 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Blink.lf"
    reaction_t _lf__reaction_1;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Blink.lf"
    trigger_t _lf__t;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Blink.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _blink_main_main_self_t;
_blink_main_main_self_t* new__blink_main();
#endif // _BLINK_MAIN_H
