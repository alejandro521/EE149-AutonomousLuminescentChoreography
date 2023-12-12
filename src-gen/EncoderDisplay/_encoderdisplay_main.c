#include "include/api/api.h"
#include "include/EncoderDisplay/EncoderDisplay.h"
#include "_encoderdisplay_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _encoderdisplay_mainreaction_function_0(void* instance_args) {
    _encoderdisplay_main_main_self_t* self = (_encoderdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct encoder {
        _encoders_trigger_t* trigger;
    
    } encoder;
    encoder.trigger = &(self->_lf_encoder.trigger);
    #line 25 "/Users/alex/149project/src/EncoderDisplay.lf"
    lf_set(encoder.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _encoderdisplay_mainreaction_function_1(void* instance_args) {
    _encoderdisplay_main_main_self_t* self = (_encoderdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct display {
        _display_line0_t* line0;
    
    } display;
    display.line0 = &(self->_lf_display.line0);
    #line 29 "/Users/alex/149project/src/EncoderDisplay.lf"
    lf_set(display.line0, "ENCODERS:");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _encoderdisplay_mainreaction_function_2(void* instance_args) {
    _encoderdisplay_main_main_self_t* self = (_encoderdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct encoder {
        _encoders_left_t* left;
    
    } encoder;
    struct display {
        _display_line1_t* line1;
    
    } display;
    encoder.left = self->_lf_encoder.left;
    display.line1 = &(self->_lf_display.line1);
    #line 33 "/Users/alex/149project/src/EncoderDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "L: %d", encoder.left->value);
    lf_set(display.line1, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _encoderdisplay_mainreaction_function_3(void* instance_args) {
    _encoderdisplay_main_main_self_t* self = (_encoderdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct encoder {
        _encoders_right_t* right;
    
    } encoder;
    struct display {
        _display_line2_t* line2;
    
    } display;
    encoder.right = self->_lf_encoder.right;
    display.line2 = &(self->_lf_display.line2);
    #line 39 "/Users/alex/149project/src/EncoderDisplay.lf"
    static char buf[17];
    snprintf(buf, 17, "R: %d", encoder.right->value);
    lf_set(display.line2, buf);
}
#include "include/api/set_undef.h"
_encoderdisplay_main_main_self_t* new__encoderdisplay_main() {
    _encoderdisplay_main_main_self_t* self = (_encoderdisplay_main_main_self_t*)_lf_new_reactor(sizeof(_encoderdisplay_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_encoder_width = -2;
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.left_reactions[0] = &self->_lf__reaction_2;
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.reactions = self->_lf_encoder.left_reactions;
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.last = NULL;
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.number_of_reactions = 1;
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    #ifdef FEDERATED
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.physical_time_of_arrival = NEVER;
    #line 34 "/Users/alex/149project/src/lib/Encoders.lf"
    #endif // FEDERATED
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.right_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.right_reactions[0] = &self->_lf__reaction_3;
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.right_trigger.reactions = self->_lf_encoder.right_reactions;
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.right_trigger.last = NULL;
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.right_trigger.number_of_reactions = 1;
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    #ifdef FEDERATED
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    self->_lf_encoder.right_trigger.physical_time_of_arrival = NEVER;
    #line 33 "/Users/alex/149project/src/lib/Encoders.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_display_width = -2;
    #line 24 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_0.number = 0;
    #line 24 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_0.function = _encoderdisplay_mainreaction_function_0;
    #line 24 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_0.self = self;
    #line 24 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 24 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 24 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_0.name = "?";
    #line 24 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 28 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_1.number = 1;
    #line 28 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_1.function = _encoderdisplay_mainreaction_function_1;
    #line 28 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_1.self = self;
    #line 28 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 28 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 28 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_1.name = "?";
    #line 28 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 32 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_2.number = 2;
    #line 32 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_2.function = _encoderdisplay_mainreaction_function_2;
    #line 32 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_2.self = self;
    #line 32 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 32 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 32 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_2.name = "?";
    #line 32 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 38 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_3.number = 3;
    #line 38 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_3.function = _encoderdisplay_mainreaction_function_3;
    #line 38 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_3.self = self;
    #line 38 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 38 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 38 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_3.name = "?";
    #line 38 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__t.last = NULL;
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    #ifdef FEDERATED
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 22 "/Users/alex/149project/src/EncoderDisplay.lf"
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
