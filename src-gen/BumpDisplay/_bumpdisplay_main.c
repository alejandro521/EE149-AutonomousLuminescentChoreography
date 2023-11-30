#include "include/api/api.h"
#include "include/BumpDisplay/BumpDisplay.h"
#include "_bumpdisplay_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _bumpdisplay_mainreaction_function_0(void* instance_args) {
    _bumpdisplay_main_main_self_t* self = (_bumpdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bump {
        _bump_left_t* left;
    
    } bump;
    struct disp {
        _display_line0_t* line0;
    
    } disp;
    bump.left = self->_lf_bump.left;
    disp.line0 = &(self->_lf_disp.line0);
    _bumpdisplay_main_clear_t* clear = &self->_lf_clear;
    #line 24 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    lf_set(disp.line0, "Left Bumped!");
    lf_schedule(clear, SEC(2));
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _bumpdisplay_mainreaction_function_1(void* instance_args) {
    _bumpdisplay_main_main_self_t* self = (_bumpdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bump {
        _bump_right_t* right;
    
    } bump;
    struct disp {
        _display_line1_t* line1;
    
    } disp;
    bump.right = self->_lf_bump.right;
    disp.line1 = &(self->_lf_disp.line1);
    _bumpdisplay_main_clear_t* clear = &self->_lf_clear;
    #line 28 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    lf_set(disp.line1, "Right Bumped!");
    lf_schedule(clear, SEC(2));
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _bumpdisplay_mainreaction_function_2(void* instance_args) {
    _bumpdisplay_main_main_self_t* self = (_bumpdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    
    } disp;
    // Expose the action struct as a local variable whose name matches the action name.
    _bumpdisplay_main_clear_t* clear = &self->_lf_clear;
    // Set the fields of the action struct to match the current trigger.
    clear->is_present = (bool)self->_lf__clear.status;
    clear->has_value = ((self->_lf__clear.tmplt.token) != NULL && (self->_lf__clear.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)clear, (self->_lf__clear.tmplt.token));
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    lf_set(disp.line0, "");
    lf_set(disp.line1, "");
}
#include "include/api/set_undef.h"
_bumpdisplay_main_main_self_t* new__bumpdisplay_main() {
    _bumpdisplay_main_main_self_t* self = (_bumpdisplay_main_main_self_t*)_lf_new_reactor(sizeof(_bumpdisplay_main_main_self_t));
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf_clear._base.trigger = &self->_lf__clear;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf_clear.parent = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_bump_width = -2;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.left_reactions[0] = &self->_lf__reaction_0;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.reactions = self->_lf_bump.left_reactions;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.last = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.number_of_reactions = 1;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    #ifdef FEDERATED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.physical_time_of_arrival = NEVER;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    #endif // FEDERATED
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.right_reactions[0] = &self->_lf__reaction_1;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.reactions = self->_lf_bump.right_reactions;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.last = NULL;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.number_of_reactions = 1;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    #ifdef FEDERATED
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.physical_time_of_arrival = NEVER;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Bump.lf"
    #endif // FEDERATED
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_0.number = 0;
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_0.function = _bumpdisplay_mainreaction_function_0;
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_0.self = self;
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_0.name = "?";
    #line 23 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_1.number = 1;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_1.function = _bumpdisplay_mainreaction_function_1;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_1.self = self;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_1.name = "?";
    #line 27 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_2.number = 2;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_2.function = _bumpdisplay_mainreaction_function_2;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_2.self = self;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_2.name = "?";
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__clear.last = NULL;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__clear.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__clear_reactions[0] = &self->_lf__reaction_2;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__clear.reactions = &self->_lf__clear_reactions[0];
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__clear.number_of_reactions = 1;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    #ifdef FEDERATED
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    self->_lf__clear.physical_time_of_arrival = NEVER;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/BumpDisplay.lf"
    #endif // FEDERATED
    self->_lf__clear.is_physical = false;
    
    self->_lf__clear.tmplt.type.element_size = 0;
    self->_lf_clear.type.element_size = 0;
    return self;
}
