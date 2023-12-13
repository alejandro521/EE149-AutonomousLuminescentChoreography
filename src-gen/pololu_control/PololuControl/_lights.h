#ifndef _LIGHTS_H
#define _LIGHTS_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1567917364_H
#define TOP_LEVEL_PREAMBLE_1567917364_H
#include <stdlib.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>

#define RED_LED_PIN 7
#define YELLOW_LED_PIN 27
#define GREEN_LED_PIN 24
#endif
typedef struct {
    struct self_base_t base;
    
    
    #line 23 "/home/foobar/149project/src/pololu_control/Lights.lf"
    reaction_t _lf__reaction_0;
    #line 33 "/home/foobar/149project/src/pololu_control/Lights.lf"
    reaction_t _lf__reaction_1;
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    trigger_t _lf__t;
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _lights_self_t;
_lights_self_t* new__lights();
#endif // _LIGHTS_H
