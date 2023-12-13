#include "include/api/api.h"
#include "include/PololuControl/PololuControl.h"
#include "_pololucontrol_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _pololucontrol_mainreaction_function_0(void* instance_args) {
    _pololucontrol_main_main_self_t* self = (_pololucontrol_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bluetooth {
        _bluetooth_incoming_message_t* incoming_message;
    _bluetooth_outgoing_message_t* outgoing_message;
    
    } bluetooth;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    
    } disp;
    struct pololu {
        _pololu_drive_mode_t* drive_mode;
    _pololu_drive_direction_t* drive_direction;
    _pololu_drive_amount_t* drive_amount;
    
    } pololu;
    bluetooth.incoming_message = self->_lf_bluetooth.incoming_message;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    pololu.drive_mode = &(self->_lf_pololu.drive_mode);
    pololu.drive_direction = &(self->_lf_pololu.drive_direction);
    pololu.drive_amount = &(self->_lf_pololu.drive_amount);
    bluetooth.outgoing_message = &(self->_lf_bluetooth.outgoing_message);
    #line 46 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    static char inc_msg_buf[17];
    snprintf(inc_msg_buf, 17, "C: %s", bluetooth.incoming_message->value);
    lf_set(disp.line0, inc_msg_buf);
    
    float amount = 0.0f;
    
    if (matchesCommand(bluetooth.incoming_message->value, self->TURN_LEFT_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->TURN_LEFT_COMMAND));
      lf_set(pololu.drive_mode, 2);
      lf_set(pololu.drive_direction, 0);
      lf_set(bluetooth.outgoing_message, "Turned left");
    } else if (matchesCommand(bluetooth.incoming_message->value, self->TURN_RIGHT_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->TURN_RIGHT_COMMAND));
      lf_set(pololu.drive_mode, 2);
      lf_set(pololu.drive_direction, 1);
      lf_set(bluetooth.outgoing_message, "Turned right");
    } else if (matchesCommand(bluetooth.incoming_message->value, self->MOVE_FORWARD_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->MOVE_FORWARD_COMMAND));
      lf_set(pololu.drive_mode, 1);
      lf_set(pololu.drive_direction, 0);
      lf_set(bluetooth.outgoing_message, "Moved forward");
    } else if (matchesCommand(bluetooth.incoming_message->value, self->MOVE_BACKWARD_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->MOVE_BACKWARD_COMMAND));
      lf_set(pololu.drive_mode, 1);
      lf_set(pololu.drive_direction, 1);
      lf_set(bluetooth.outgoing_message, "Moved backward");
    }
    
    lf_set(pololu.drive_amount, amount);
    static char amount_buf[17];
    snprintf(amount_buf, 17, "A: %0.2f", amount);
    lf_set(disp.line1, amount_buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololucontrol_mainreaction_function_1(void* instance_args) {
    _pololucontrol_main_main_self_t* self = (_pololucontrol_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct pololu {
        _pololu_current_mode_t* current_mode;
    
    } pololu;
    struct disp {
        _display_line2_t* line2;
    
    } disp;
    pololu.current_mode = self->_lf_pololu.current_mode;
    disp.line2 = &(self->_lf_disp.line2);
    #line 81 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    static char mode_buf[17];
    snprintf(mode_buf, 17, "M: %s", pololu.current_mode->value);
    lf_set(disp.line2, mode_buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololucontrol_mainreaction_function_2(void* instance_args) {
    _pololucontrol_main_main_self_t* self = (_pololucontrol_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct pololu {
        _pololu_facing_angle_t* facing_angle;
    
    } pololu;
    struct disp {
        _display_line3_t* line3;
    
    } disp;
    pololu.facing_angle = self->_lf_pololu.facing_angle;
    disp.line3 = &(self->_lf_disp.line3);
    #line 87 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    static char angle_buf[17];
    snprintf(angle_buf, 17, "F: %0.2f", pololu.facing_angle->value);
    lf_set(disp.line3, angle_buf);
}
#include "include/api/set_undef.h"
_pololucontrol_main_main_self_t* new__pololucontrol_main() {
    _pololucontrol_main_main_self_t* self = (_pololucontrol_main_main_self_t*)_lf_new_reactor(sizeof(_pololucontrol_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_pololu_width = -2;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_reactions[0] = &self->_lf__reaction_1;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.reactions = self->_lf_pololu.current_mode_reactions;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.last = NULL;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.number_of_reactions = 1;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.physical_time_of_arrival = NEVER;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_reactions[0] = &self->_lf__reaction_2;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.reactions = self->_lf_pololu.facing_angle_reactions;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.last = NULL;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.number_of_reactions = 1;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.physical_time_of_arrival = NEVER;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_bluetooth_width = -2;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.incoming_message_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.incoming_message_reactions[0] = &self->_lf__reaction_0;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.incoming_message_trigger.reactions = self->_lf_bluetooth.incoming_message_reactions;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.incoming_message_trigger.last = NULL;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.incoming_message_trigger.number_of_reactions = 1;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.incoming_message_trigger.physical_time_of_arrival = NEVER;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #endif // FEDERATED
    #line 45 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.number = 0;
    #line 45 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.function = _pololucontrol_mainreaction_function_0;
    #line 45 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.self = self;
    #line 45 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 45 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 45 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.name = "?";
    #line 45 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 80 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.number = 1;
    #line 80 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.function = _pololucontrol_mainreaction_function_1;
    #line 80 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.self = self;
    #line 80 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 80 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 80 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.name = "?";
    #line 80 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 86 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.number = 2;
    #line 86 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.function = _pololucontrol_mainreaction_function_2;
    #line 86 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.self = self;
    #line 86 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 86 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 86 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.name = "?";
    #line 86 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 27 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.last = NULL;
    #line 27 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 27 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 27 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
