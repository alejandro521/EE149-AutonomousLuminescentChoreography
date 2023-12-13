#ifndef _lights_H
#define _lights_H
#ifndef TOP_LEVEL_PREAMBLE_504634946_H
#define TOP_LEVEL_PREAMBLE_504634946_H
/*Correspondence: Range: [(9, 4), (16, 24)) -> Range: [(0, 0), (7, 24)) (verbatim=true; src=/home/foobar/149project/src/pololu_control/Lights.lf)*/#include <stdlib.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>

#define RED_LED_PIN 7
#define YELLOW_LED_PIN 27
#define GREEN_LED_PIN 24
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct lights_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} lights_self_t;
#endif
