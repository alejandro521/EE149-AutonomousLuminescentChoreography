#ifndef _blink_main_H
#define _blink_main_H
#ifndef TOP_LEVEL_PREAMBLE_1894287849_H
#define TOP_LEVEL_PREAMBLE_1894287849_H
/*Correspondence: Range: [(15, 2), (17, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/Blink.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct blink_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool led_on;
    int end[0]; // placeholder; MSVC does not compile empty structs
} blink_self_t;
#endif
