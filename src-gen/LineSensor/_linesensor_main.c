#include "include/api/api.h"
#include "include/LineSensor/LineSensor.h"
#include "_linesensor_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _linesensor_mainreaction_function_0(void* instance_args) {
    _linesensor_main_main_self_t* self = (_linesensor_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    lf_set(disp.line0, "CALIBRATING");
    lf_set(disp.line1, "Roll robot over");
    lf_set(disp.line2, "light and dark.");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _linesensor_mainreaction_function_1(void* instance_args) {
    _linesensor_main_main_self_t* self = (_linesensor_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_calibrate_t* calibrate;
    
    } line;
    line.calibrate = &(self->_lf_line.calibrate);
    #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    lf_set(line.calibrate, false);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _linesensor_mainreaction_function_2(void* instance_args) {
    _linesensor_main_main_self_t* self = (_linesensor_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    lf_set(line.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _linesensor_mainreaction_function_3(void* instance_args) {
    _linesensor_main_main_self_t* self = (_linesensor_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    
    } disp;
    line.reflect = self->_lf_line.reflect;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    #line 36 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
        if(lf_time_physical()>self->displaytime+100000000){
    
        static char buf0[17];
        static char buf1[17];
        static char buf2[17];
        snprintf(buf0, 17, "0:%4d 1:%4d ", line.reflect->value[0], line.reflect->value[1]);
        snprintf(buf1, 17, "3:%4d 4:%4d", line.reflect->value[3], line.reflect->value[4]);
        lf_set(disp.line0, buf0);
        lf_set(disp.line1, buf1);
        self->displaytime=lf_time_physical();
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _linesensor_mainreaction_function_4(void* instance_args) {
    _linesensor_main_main_self_t* self = (_linesensor_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    line.reflect = self->_lf_line.reflect;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->blockstate=0;
    
    int threshold = 400; // Replace with your threshold value
    lf_set(disp.line2, "");
    
    if(line.reflect->value[0] > threshold || line.reflect->value[1] > threshold) {
        lf_set(disp.line2, "Left");
    }
    if(line.reflect->value[3] > threshold || line.reflect->value[4] > threshold) {
        lf_set(disp.line2, "Right");
    }
    if( line.reflect->value[2] > threshold ) {
        lf_set(disp.line2, "Center");
    }
}
#include "include/api/set_undef.h"
_linesensor_main_main_self_t* new__linesensor_main() {
    _linesensor_main_main_self_t* self = (_linesensor_main_main_self_t*)_lf_new_reactor(sizeof(_linesensor_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_line_width = -2;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_reactions[0] = &self->_lf__reaction_3;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_reactions[1] = &self->_lf__reaction_4;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.reactions = self->_lf_line.reflect_reactions;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.last = NULL;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.number_of_reactions = 2;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    #ifdef FEDERATED
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.physical_time_of_arrival = NEVER;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    #endif // FEDERATED
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_0.number = 0;
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_0.function = _linesensor_mainreaction_function_0;
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_0.self = self;
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_0.name = "?";
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_1.number = 1;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_1.function = _linesensor_mainreaction_function_1;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_1.self = self;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_1.name = "?";
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_2.number = 2;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_2.function = _linesensor_mainreaction_function_2;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_2.self = self;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_2.name = "?";
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_3.number = 3;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_3.function = _linesensor_mainreaction_function_3;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_3.self = self;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_3.name = "?";
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_4.number = 4;
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_4.function = _linesensor_mainreaction_function_4;
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_4.self = self;
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_4.name = "?";
    #line 50 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[0];
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__t.last = NULL;
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_2;
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #ifdef FEDERATED
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 13 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__end_calibration.last = NULL;
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_1;
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__end_calibration.number_of_reactions = 1;
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #ifdef FEDERATED
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #line 14 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    #endif // FEDERATED
    self->_lf__end_calibration.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 49 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 49 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__modes[0].name = "drive";
    #line 49 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 49 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/LineSensor.lf"
    self->_lf__modes[0].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
