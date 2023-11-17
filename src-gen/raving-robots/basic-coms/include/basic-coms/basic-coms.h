#ifndef _basic-coms_main_H
#define _basic-coms_main_H
#ifndef TOP_LEVEL_PREAMBLE_1720127312_H
#define TOP_LEVEL_PREAMBLE_1720127312_H
/*Correspondence: Range: [(9, 4), (13, 31)) -> Range: [(0, 0), (4, 31)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/structs/uart.h>
#include <hardware/regs/dreq.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct basic-coms_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool led_on;
    int end[0]; // placeholder; MSVC does not compile empty structs
} basic-coms_self_t;
#endif
