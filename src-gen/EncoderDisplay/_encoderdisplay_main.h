#ifndef _ENCODERDISPLAY_MAIN_H
#define _ENCODERDISPLAY_MAIN_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_1528516437_H
#define TOP_LEVEL_PREAMBLE_1528516437_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif
typedef struct {
    struct self_base_t base;
    
    
    struct {
        #line 32 "/Users/alex/149project/src/lib/Encoders.lf"
        _encoders_trigger_t trigger;
        #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
        _encoders_left_t* left;
        #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
        trigger_t left_trigger;
        #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
        reaction_t* left_reactions[1];
        #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
        _encoders_right_t* right;
        #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
        trigger_t right_trigger;
        #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
        reaction_t* right_reactions[1];
    } _lf_encoder;
    int _lf_encoder_width;
    struct {
        #line 25 "/Users/alex/149project/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/Users/alex/149project/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/Users/alex/149project/src/lib/Display.lf"
        _display_line2_t line2;
    } _lf_display;
    int _lf_display_width;
    #line 24 "/Users/alex/149project/src/EncoderDisplay.lf"
    reaction_t _lf__reaction_0;
    #line 28 "/Users/alex/149project/src/EncoderDisplay.lf"
    reaction_t _lf__reaction_1;
    #line 32 "/Users/alex/149project/src/EncoderDisplay.lf"
    reaction_t _lf__reaction_2;
    #line 38 "/Users/alex/149project/src/EncoderDisplay.lf"
    reaction_t _lf__reaction_3;
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    trigger_t _lf__t;
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _encoderdisplay_main_main_self_t;
_encoderdisplay_main_main_self_t* new__encoderdisplay_main();
#endif // _ENCODERDISPLAY_MAIN_H
