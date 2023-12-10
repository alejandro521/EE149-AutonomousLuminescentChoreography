#ifndef _LINESENSOR_MAIN_H
#define _LINESENSOR_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_line.h"
#ifndef TOP_LEVEL_PREAMBLE_696154163_H
#define TOP_LEVEL_PREAMBLE_696154163_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <ir_sensors.h>
#endif
typedef struct {
    struct self_base_t base;
    #line 9 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    interval_t calibration_time;
    #line 9 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    interval_t sample_period;
    #line 16 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    int blockstate;
    #line 17 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    int64_t blockedtime;
    #line 18 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    int64_t displaytime;
    struct {
        #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line2_t line2;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        #line 38 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        _line_calibrate_t calibrate;
        #line 39 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        _line_trigger_t trigger;
        #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        _line_reflect_t* reflect;
        #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        trigger_t reflect_trigger;
        #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
        reaction_t* reflect_reactions[2];
    } _lf_line;
    int _lf_line_width;
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    reaction_t _lf__reaction_0;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    reaction_t _lf__reaction_1;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    reaction_t _lf__reaction_2;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    reaction_t _lf__reaction_3;
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    reaction_t _lf__reaction_4;
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    trigger_t _lf__t;
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    reaction_t* _lf__t_reactions[1];
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    trigger_t _lf__end_calibration;
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    reactor_mode_t _lf__modes[1];
} _linesensor_main_main_self_t;
_linesensor_main_main_self_t* new__linesensor_main();
#endif // _LINESENSOR_MAIN_H
