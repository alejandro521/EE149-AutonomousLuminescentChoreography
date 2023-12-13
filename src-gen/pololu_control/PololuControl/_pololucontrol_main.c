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
    
    } bluetooth;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    
    } disp;
    struct pololu {
        _pololu_speed_t* speed;
    _pololu_drive_mode_t* drive_mode;
    _pololu_drive_direction_t* drive_direction;
    _pololu_drive_amount_t* drive_amount;
    
    } pololu;
    bluetooth.incoming_message = self->_lf_bluetooth.incoming_message;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    pololu.speed = &(self->_lf_pololu.speed);
    pololu.drive_mode = &(self->_lf_pololu.drive_mode);
    pololu.drive_direction = &(self->_lf_pololu.drive_direction);
    pololu.drive_amount = &(self->_lf_pololu.drive_amount);
    #line 51 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    static char inc_msg_buf[17];
    snprintf(inc_msg_buf, 17, "C: %s", bluetooth.incoming_message->value);
    lf_set(disp.line0, inc_msg_buf);
    
    float amount = 0.0f;
    
    if (matchesCommand(bluetooth.incoming_message->value, self->TURN_LEFT_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->TURN_LEFT_COMMAND));
      lf_set(pololu.drive_mode, 2);
      lf_set(pololu.drive_direction, 0);
      // snprintf(self->reply, 100, "Turned left");
    } else if (matchesCommand(bluetooth.incoming_message->value, self->TURN_RIGHT_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->TURN_RIGHT_COMMAND));
      lf_set(pololu.drive_mode, 2);
      lf_set(pololu.drive_direction, 1);
      // snprintf(self->reply, 100, "Turned right");
    } else if (matchesCommand(bluetooth.incoming_message->value, self->MOVE_FORWARD_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->MOVE_FORWARD_COMMAND));
      lf_set(pololu.drive_mode, 1);
      lf_set(pololu.drive_direction, 0);
      // snprintf(self->reply, 100, "Moved forward");
    } else if (matchesCommand(bluetooth.incoming_message->value, self->MOVE_BACKWARD_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->MOVE_BACKWARD_COMMAND));
      lf_set(pololu.drive_mode, 1);
      lf_set(pololu.drive_direction, 1);
      // snprintf(self->reply, 100, "Moved backward");
    } else if (matchesCommand(bluetooth.incoming_message->value, self->SET_SPEED_COMMAND)) {
      amount = atof(bluetooth.incoming_message->value + strlen(self->SET_SPEED_COMMAND));
      lf_set(pololu.drive_mode, 0);
      lf_set(pololu.speed, amount);
      // snprintf(self->reply, 100, "Moved backward");
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
    #line 91 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
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
    #line 97 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    static char angle_buf[17];
    snprintf(angle_buf, 17, "F: %0.2f", pololu.facing_angle->value);
    lf_set(disp.line3, angle_buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololucontrol_mainreaction_function_3(void* instance_args) {
    _pololucontrol_main_main_self_t* self = (_pololucontrol_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct pololu {
        _pololu_completion_notify_t* completion_notify;
    
    } pololu;
    struct bluetooth {
        _bluetooth_outgoing_message_t* outgoing_message;
    
    } bluetooth;
    pololu.completion_notify = self->_lf_pololu.completion_notify;
    bluetooth.outgoing_message = &(self->_lf_bluetooth.outgoing_message);
    #line 103 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    lf_set(bluetooth.outgoing_message, "Completed");
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
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_reactions[0] = &self->_lf__reaction_1;
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.reactions = self->_lf_pololu.current_mode_reactions;
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.last = NULL;
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.number_of_reactions = 1;
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.physical_time_of_arrival = NEVER;
    #line 29 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_reactions[0] = &self->_lf__reaction_2;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.reactions = self->_lf_pololu.facing_angle_reactions;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.last = NULL;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.number_of_reactions = 1;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.physical_time_of_arrival = NEVER;
    #line 28 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.completion_notify_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.completion_notify_reactions[0] = &self->_lf__reaction_3;
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.completion_notify_trigger.reactions = self->_lf_pololu.completion_notify_reactions;
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.completion_notify_trigger.last = NULL;
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.completion_notify_trigger.number_of_reactions = 1;
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.completion_notify_trigger.physical_time_of_arrival = NEVER;
    #line 30 "/home/foobar/149project/src/pololu_control/Pololu.lf"
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
    #line 50 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.number = 0;
    #line 50 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.function = _pololucontrol_mainreaction_function_0;
    #line 50 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.self = self;
    #line 50 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 50 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 50 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.name = "?";
    #line 50 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 90 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.number = 1;
    #line 90 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.function = _pololucontrol_mainreaction_function_1;
    #line 90 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.self = self;
    #line 90 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 90 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 90 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.name = "?";
    #line 90 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 96 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.number = 2;
    #line 96 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.function = _pololucontrol_mainreaction_function_2;
    #line 96 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.self = self;
    #line 96 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 96 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 96 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.name = "?";
    #line 96 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 102 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_3.number = 3;
    #line 102 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_3.function = _pololucontrol_mainreaction_function_3;
    #line 102 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_3.self = self;
    #line 102 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 102 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 102 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_3.name = "?";
    #line 102 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 29 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.last = NULL;
    #line 29 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 29 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 29 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
