#include "include/api/api.h"
#include "include/MotorsWithFeedback/MotorsWithFeedback.h"
#include "_motorswithfeedback.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _motorswithfeedbackreaction_function_0(void* instance_args) {
    _motorswithfeedback_self_t* self = (_motorswithfeedback_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _motorswithfeedback_left_speed_t* left_speed = self->_lf_left_speed;
    int left_speed_width = self->_lf_left_speed_width; SUPPRESS_UNUSED_WARNING(left_speed_width);
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->target_speed_left = left_speed->value;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _motorswithfeedbackreaction_function_1(void* instance_args) {
    _motorswithfeedback_self_t* self = (_motorswithfeedback_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _motorswithfeedback_right_speed_t* right_speed = self->_lf_right_speed;
    int right_speed_width = self->_lf_right_speed_width; SUPPRESS_UNUSED_WARNING(right_speed_width);
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->target_speed_right = right_speed->value;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _motorswithfeedbackreaction_function_2(void* instance_args) {
    _motorswithfeedback_self_t* self = (_motorswithfeedback_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct control_left {
        _picontrol_err_t* err;
    
    } control_left;
    struct control_right {
        _picontrol_err_t* err;
    
    } control_right;
    _motorswithfeedback_left_t* left = self->_lf_left;
    int left_width = self->_lf_left_width; SUPPRESS_UNUSED_WARNING(left_width);
    _motorswithfeedback_right_t* right = self->_lf_right;
    int right_width = self->_lf_right_width; SUPPRESS_UNUSED_WARNING(right_width);
    control_left.err = &(self->_lf_control_left.err);
    control_right.err = &(self->_lf_control_right.err);
    #line 57 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Ignore the first input because we can't estimate speed.
    instant_t now = lf_time_logical();
    if (self->prev_time > 0) {
      interval_t interval = now - self->prev_time;
    
      // Ignore intervals that are too small. Assume a maximum sample rate of 1kHz.
      if (interval >= MSEC(1)) {
        float est_speed_left = ((left->value - self->prev_left) * TICKS_PER_METER) / (interval * 1e-9f);
        float est_speed_right = ((right->value - self->prev_right) * TICKS_PER_METER) / (interval * 1e-9f);
    
        self->prev_left = left->value;
        self->prev_right = right->value;
    
        lf_set(control_left.err, self->target_speed_left - est_speed_left);
        lf_set(control_right.err, self->target_speed_right - est_speed_right);
      }
    }
    self->prev_time = now;
}
#include "include/api/set_undef.h"
_motorswithfeedback_self_t* new__motorswithfeedback() {
    _motorswithfeedback_self_t* self = (_motorswithfeedback_self_t*)_lf_new_reactor(sizeof(_motorswithfeedback_self_t));
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Set input by default to an always absent default input.
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf_left_speed = &self->_lf_default__left_speed;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Set the default source reactor pointer
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf_default__left_speed._base.source_reactor = (self_base_t*)self;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Set input by default to an always absent default input.
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf_right_speed = &self->_lf_default__right_speed;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Set the default source reactor pointer
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf_default__right_speed._base.source_reactor = (self_base_t*)self;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Set input by default to an always absent default input.
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf_left = &self->_lf_default__left;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Set the default source reactor pointer
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf_default__left._base.source_reactor = (self_base_t*)self;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Set input by default to an always absent default input.
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf_right = &self->_lf_default__right;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    // Set the default source reactor pointer
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf_default__right._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_control_left_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_control_right_width = -2;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_0.number = 0;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_0.function = _motorswithfeedbackreaction_function_0;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_0.self = self;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_0.name = "?";
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_1.number = 1;
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_1.function = _motorswithfeedbackreaction_function_1;
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_1.self = self;
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_1.name = "?";
    #line 53 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_2.number = 2;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_2.function = _motorswithfeedbackreaction_function_2;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_2.self = self;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_2.name = "?";
    #line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left_speed.last = NULL;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left_speed.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left_speed_reactions[0] = &self->_lf__reaction_0;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left_speed.reactions = &self->_lf__left_speed_reactions[0];
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left_speed.number_of_reactions = 1;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #ifdef FEDERATED
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left_speed.physical_time_of_arrival = NEVER;
    #line 30 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #endif // FEDERATED
    self->_lf__left_speed.tmplt.type.element_size = sizeof(float);
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right_speed.last = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right_speed.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right_speed_reactions[0] = &self->_lf__reaction_1;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right_speed.reactions = &self->_lf__right_speed_reactions[0];
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right_speed.number_of_reactions = 1;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #ifdef FEDERATED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right_speed.physical_time_of_arrival = NEVER;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #endif // FEDERATED
    self->_lf__right_speed.tmplt.type.element_size = sizeof(float);
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left.last = NULL;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left_reactions[0] = &self->_lf__reaction_2;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left.reactions = &self->_lf__left_reactions[0];
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left.number_of_reactions = 1;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #ifdef FEDERATED
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__left.physical_time_of_arrival = NEVER;
    #line 34 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #endif // FEDERATED
    self->_lf__left.tmplt.type.element_size = sizeof(int32_t);
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right.last = NULL;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right_reactions[0] = &self->_lf__reaction_2;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right.reactions = &self->_lf__right_reactions[0];
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right.number_of_reactions = 1;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #ifdef FEDERATED
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    self->_lf__right.physical_time_of_arrival = NEVER;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/MotorsWithFeedback.lf"
    #endif // FEDERATED
    self->_lf__right.tmplt.type.element_size = sizeof(int32_t);
    return self;
}
