#ifndef _GYRODISPLAY_MAIN_H
#define _GYRODISPLAY_MAIN_H
#include "include/core/reactor.h"
#include "_gyro.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_481525476_H
#define TOP_LEVEL_PREAMBLE_481525476_H
#include <pico/stdlib.h>
#include <imu.h>
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif
typedef struct {
    struct self_base_t base;
    
    
    struct {
        #line 38 "/home/foobar/149project/src/lib/IMU.lf"
        _gyro_trigger_t trigger;
        #line 40 "/home/foobar/149project/src/lib/IMU.lf"
        _gyro_x_t* x;
        #line 40 "/home/foobar/149project/src/lib/IMU.lf"
        trigger_t x_trigger;
        #line 40 "/home/foobar/149project/src/lib/IMU.lf"
        reaction_t* x_reactions[1];
        #line 41 "/home/foobar/149project/src/lib/IMU.lf"
        _gyro_y_t* y;
        #line 41 "/home/foobar/149project/src/lib/IMU.lf"
        trigger_t y_trigger;
        #line 41 "/home/foobar/149project/src/lib/IMU.lf"
        reaction_t* y_reactions[1];
        #line 42 "/home/foobar/149project/src/lib/IMU.lf"
        _gyro_z_t* z;
        #line 42 "/home/foobar/149project/src/lib/IMU.lf"
        trigger_t z_trigger;
        #line 42 "/home/foobar/149project/src/lib/IMU.lf"
        reaction_t* z_reactions[1];
    } _lf_gyro;
    int _lf_gyro_width;
    struct {
        #line 25 "/home/foobar/149project/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/149project/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/149project/src/lib/Display.lf"
        _display_line2_t line2;
        #line 28 "/home/foobar/149project/src/lib/Display.lf"
        _display_line3_t line3;
    } _lf_display;
    int _lf_display_width;
    #line 27 "/home/foobar/149project/src/GyroDisplay.lf"
    reaction_t _lf__reaction_0;
    #line 31 "/home/foobar/149project/src/GyroDisplay.lf"
    reaction_t _lf__reaction_1;
    #line 35 "/home/foobar/149project/src/GyroDisplay.lf"
    reaction_t _lf__reaction_2;
    #line 41 "/home/foobar/149project/src/GyroDisplay.lf"
    reaction_t _lf__reaction_3;
    #line 47 "/home/foobar/149project/src/GyroDisplay.lf"
    reaction_t _lf__reaction_4;
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    trigger_t _lf__t;
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _gyrodisplay_main_main_self_t;
_gyrodisplay_main_main_self_t* new__gyrodisplay_main();
#endif // _GYRODISPLAY_MAIN_H
