#ifndef _basiccoms_main_H
#define _basiccoms_main_H
#ifndef TOP_LEVEL_PREAMBLE_555045570_H
#define TOP_LEVEL_PREAMBLE_555045570_H
/*Correspondence: Range: [(9, 4), (17, 22)) -> Range: [(0, 0), (8, 22)) (verbatim=true; src=/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/structs/uart.h>
#include <hardware/regs/dreq.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29
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
