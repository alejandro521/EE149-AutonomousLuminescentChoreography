#ifndef _BUMPDISPLAY_MAIN_H
#define _BUMPDISPLAY_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_bump.h"
#ifndef TOP_LEVEL_PREAMBLE_2082673402_H
#define TOP_LEVEL_PREAMBLE_2082673402_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <ir_sensors.h>
// others
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _bumpdisplay_main_clear_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    _bumpdisplay_main_clear_t _lf_clear;
    struct {
        #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Display.lf"
        _display_line1_t line1;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
        _bump_left_t* left;
        #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
        trigger_t left_trigger;
        #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
        reaction_t* left_reactions[1];
        #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
        _bump_right_t* right;
        #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
        trigger_t right_trigger;
        #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
        reaction_t* right_reactions[1];
    } _lf_bump;
    int _lf_bump_width;
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    reaction_t _lf__reaction_0;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    reaction_t _lf__reaction_1;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    reaction_t _lf__reaction_2;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    trigger_t _lf__clear;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    reaction_t* _lf__clear_reactions[1];
} _bumpdisplay_main_main_self_t;
_bumpdisplay_main_main_self_t* new__bumpdisplay_main();
#endif // _BUMPDISPLAY_MAIN_H
