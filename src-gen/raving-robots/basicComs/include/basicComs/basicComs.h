#ifndef _basiccoms_main_H
#define _basiccoms_main_H
#ifndef TOP_LEVEL_PREAMBLE_598590967_H
#define TOP_LEVEL_PREAMBLE_598590967_H
/*Correspondence: Range: [(9, 4), (14, 44)) -> Range: [(0, 0), (5, 44)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basicComs.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/structs/uart.h>
#include <hardware/regs/dreq.h>
#include <robot-lib/pololu_3pi_2040_robot.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct basiccoms_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool led_on;
    int end[0]; // placeholder; MSVC does not compile empty structs
} basiccoms_self_t;
#endif
