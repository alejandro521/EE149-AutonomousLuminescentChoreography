#ifndef _BASICCOMS_MAIN_H
#define _BASICCOMS_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_2012116605_H
#define TOP_LEVEL_PREAMBLE_2012116605_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
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
    
    #line 25 "/home/foobar/finalproject/src/basicComs.lf"
    bool led_on;
    struct {
        #line 25 "/home/foobar/finalproject/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/finalproject/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/finalproject/src/lib/Display.lf"
        _display_line2_t line2;
        #line 28 "/home/foobar/finalproject/src/lib/Display.lf"
        _display_line3_t line3;
    } _lf_disp;
    int _lf_disp_width;
    #line 27 "/home/foobar/finalproject/src/basicComs.lf"
    reaction_t _lf__reaction_0;
    #line 55 "/home/foobar/finalproject/src/basicComs.lf"
    reaction_t _lf__reaction_1;
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    trigger_t _lf__t;
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _basiccoms_main_main_self_t;
_basiccoms_main_main_self_t* new__basiccoms_main();
#endif // _BASICCOMS_MAIN_H
