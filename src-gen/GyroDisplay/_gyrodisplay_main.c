#include "include/api/api.h"
#include "include/GyroDisplay/GyroDisplay.h"
#include "_gyrodisplay_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _gyrodisplay_mainreaction_function_0(void* instance_args) {
    _gyrodisplay_main_main_self_t* self = (_gyrodisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyro_trigger_t* trigger;
    
    } gyro;
    gyro.trigger = &(self->_lf_gyro.trigger);
    #line 28 "/home/foobar/149project/src/GyroDisplay.lf"
    lf_set(gyro.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _gyrodisplay_mainreaction_function_1(void* instance_args) {
    _gyrodisplay_main_main_self_t* self = (_gyrodisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct display {
        _display_line0_t* line0;
    
    } display;
    display.line0 = &(self->_lf_display.line0);
    #line 32 "/home/foobar/149project/src/GyroDisplay.lf"
    lf_set(display.line0, "GYRO:");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _gyrodisplay_mainreaction_function_2(void* instance_args) {
    _gyrodisplay_main_main_self_t* self = (_gyrodisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyro_x_t* x;
    
    } gyro;
    struct display {
        _display_line1_t* line1;
    
    } display;
    gyro.x = self->_lf_gyro.x;
    display.line1 = &(self->_lf_display.line1);
    #line 36 "/home/foobar/149project/src/GyroDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "x: %.1f", gyro.x->value);
    lf_set(display.line1, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _gyrodisplay_mainreaction_function_3(void* instance_args) {
    _gyrodisplay_main_main_self_t* self = (_gyrodisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyro_y_t* y;
    
    } gyro;
    struct display {
        _display_line2_t* line2;
    
    } display;
    gyro.y = self->_lf_gyro.y;
    display.line2 = &(self->_lf_display.line2);
    #line 42 "/home/foobar/149project/src/GyroDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "y: %.1f", gyro.y->value);
    lf_set(display.line2, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _gyrodisplay_mainreaction_function_4(void* instance_args) {
    _gyrodisplay_main_main_self_t* self = (_gyrodisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyro_z_t* z;
    
    } gyro;
    struct display {
        _display_line3_t* line3;
    
    } display;
    gyro.z = self->_lf_gyro.z;
    display.line3 = &(self->_lf_display.line3);
    #line 48 "/home/foobar/149project/src/GyroDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "z: %.1f", gyro.z->value);
    lf_set(display.line3, buf);
}
#include "include/api/set_undef.h"
_gyrodisplay_main_main_self_t* new__gyrodisplay_main() {
    _gyrodisplay_main_main_self_t* self = (_gyrodisplay_main_main_self_t*)_lf_new_reactor(sizeof(_gyrodisplay_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_gyro_width = -2;
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.x_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.x_reactions[0] = &self->_lf__reaction_2;
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.x_trigger.reactions = self->_lf_gyro.x_reactions;
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.x_trigger.last = NULL;
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.x_trigger.number_of_reactions = 1;
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.x_trigger.physical_time_of_arrival = NEVER;
    #line 40 "/home/foobar/149project/src/lib/IMU.lf"
    #endif // FEDERATED
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.y_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.y_reactions[0] = &self->_lf__reaction_3;
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.y_trigger.reactions = self->_lf_gyro.y_reactions;
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.y_trigger.last = NULL;
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.y_trigger.number_of_reactions = 1;
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.y_trigger.physical_time_of_arrival = NEVER;
    #line 41 "/home/foobar/149project/src/lib/IMU.lf"
    #endif // FEDERATED
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_reactions[0] = &self->_lf__reaction_4;
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.reactions = self->_lf_gyro.z_reactions;
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.last = NULL;
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.number_of_reactions = 1;
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.physical_time_of_arrival = NEVER;
    #line 42 "/home/foobar/149project/src/lib/IMU.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_display_width = -2;
    #line 27 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_0.number = 0;
    #line 27 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_0.function = _gyrodisplay_mainreaction_function_0;
    #line 27 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_0.self = self;
    #line 27 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 27 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 27 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_0.name = "?";
    #line 27 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 31 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_1.number = 1;
    #line 31 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_1.function = _gyrodisplay_mainreaction_function_1;
    #line 31 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_1.self = self;
    #line 31 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 31 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 31 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_1.name = "?";
    #line 31 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 35 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_2.number = 2;
    #line 35 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_2.function = _gyrodisplay_mainreaction_function_2;
    #line 35 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_2.self = self;
    #line 35 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 35 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 35 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_2.name = "?";
    #line 35 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 41 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_3.number = 3;
    #line 41 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_3.function = _gyrodisplay_mainreaction_function_3;
    #line 41 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_3.self = self;
    #line 41 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 41 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 41 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_3.name = "?";
    #line 41 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 47 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_4.number = 4;
    #line 47 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_4.function = _gyrodisplay_mainreaction_function_4;
    #line 47 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_4.self = self;
    #line 47 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 47 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 47 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_4.name = "?";
    #line 47 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__t.last = NULL;
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    #ifdef FEDERATED
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 25 "/home/foobar/149project/src/GyroDisplay.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_1;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}
