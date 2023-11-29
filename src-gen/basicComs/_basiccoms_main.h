#ifndef _BASICCOMS_MAIN_H
#define _BASICCOMS_MAIN_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_555045570_H
#define TOP_LEVEL_PREAMBLE_555045570_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/structs/uart.h>
#include <hardware/regs/dreq.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29
#endif
typedef struct {
    struct self_base_t base;
    
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    bool led_on;
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    reaction_t _lf__reaction_0;
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    reaction_t _lf__reaction_1;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    trigger_t _lf__t;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _basiccoms_main_main_self_t;
_basiccoms_main_main_self_t* new__basiccoms_main();
#endif // _BASICCOMS_MAIN_H
