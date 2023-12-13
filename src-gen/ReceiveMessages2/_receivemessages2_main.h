#ifndef _RECEIVEMESSAGES2_MAIN_H
#define _RECEIVEMESSAGES2_MAIN_H
#include "include/core/reactor.h"
#include "_accelerometer.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_1731275141_H
#define TOP_LEVEL_PREAMBLE_1731275141_H
#include <pico/stdlib.h>
#include <imu.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/uart.h>
#include <hardware/structs/uart.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29
#define MAX_MSG_LENGTH 100

// COMMANDS TO POLOLU GO HERE
// static char SET_NAME_COMMAND[10] = "SET_NAME:";
// static char DRIVE_FORWARD_COMMAND[14] = "DRIVE_FORWARD";
// static char DRIVE_BACKWARD_COMMAND[15] = "DRIVE_BACKWARD";
// static char TURN_LEFT_COMMAND[10] = "TURN_LEFT";
// static char TURN_RIGHT_COMMAND[11] = "TURN_RIGHT";

static bool matchesCommand(command, str) {
  return strncmp(command, str, strlen(command)) == 0;
}
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif
typedef struct {
    struct self_base_t base;
    
    #line 39 "/home/foobar/149project/src/ReceiveMessages2.lf"
    bool led_on;
    #line 40 "/home/foobar/149project/src/ReceiveMessages2.lf"
    char* reply;
    #line 41 "/home/foobar/149project/src/ReceiveMessages2.lf"
    char* transmitted_message;
    #line 42 "/home/foobar/149project/src/ReceiveMessages2.lf"
    char* received_message;
    #line 43 "/home/foobar/149project/src/ReceiveMessages2.lf"
    char* name;
    #line 44 "/home/foobar/149project/src/ReceiveMessages2.lf"
    int counter;
    #line 45 "/home/foobar/149project/src/ReceiveMessages2.lf"
    float x;
    #line 46 "/home/foobar/149project/src/ReceiveMessages2.lf"
    float y;
    struct {
        #line 25 "/home/foobar/149project/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/149project/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/149project/src/lib/Display.lf"
        _display_line2_t line2;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        #line 40 "/home/foobar/149project/src/lib/IMU.lf"
        _accelerometer_x_t* x;
        #line 40 "/home/foobar/149project/src/lib/IMU.lf"
        trigger_t x_trigger;
        #line 41 "/home/foobar/149project/src/lib/IMU.lf"
        _accelerometer_y_t* y;
        #line 41 "/home/foobar/149project/src/lib/IMU.lf"
        trigger_t y_trigger;
    } _lf_acc;
    int _lf_acc_width;
    #line 52 "/home/foobar/149project/src/ReceiveMessages2.lf"
    reaction_t _lf__reaction_0;
    #line 67 "/home/foobar/149project/src/ReceiveMessages2.lf"
    reaction_t _lf__reaction_1;
    #line 88 "/home/foobar/149project/src/ReceiveMessages2.lf"
    reaction_t _lf__reaction_2;
    #line 38 "/home/foobar/149project/src/ReceiveMessages2.lf"
    trigger_t _lf__t;
    #line 38 "/home/foobar/149project/src/ReceiveMessages2.lf"
    reaction_t* _lf__t_reactions[2];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    reactor_mode_t _lf__modes[1];
} _receivemessages2_main_main_self_t;
_receivemessages2_main_main_self_t* new__receivemessages2_main();
#endif // _RECEIVEMESSAGES2_MAIN_H
