#include "include/api/api.h"
#include "include/PololuControl/PololuControl.h"
#include "_pololucontrol_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _pololucontrol_mainreaction_function_0(void* instance_args) {
    _pololucontrol_main_main_self_t* self = (_pololucontrol_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct pololu {
        _pololu_facing_angle_t* facing_angle;
    _pololu_current_mode_t* current_mode;
    
    } pololu;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    
    } disp;
    pololu.facing_angle = self->_lf_pololu.facing_angle;
    pololu.current_mode = self->_lf_pololu.current_mode;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    #line 39 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    static char mode_buf[17];
    snprintf(mode_buf, 17, "Mode: %d", pololu.current_mode->value);
    lf_set(disp.line0, mode_buf);
    
    static char angle_buf[17];
    snprintf(angle_buf, 17, "Angle: %.2f", pololu.facing_angle->value);
    lf_set(disp.line1, angle_buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _pololucontrol_mainreaction_function_1(void* instance_args) {
    _pololucontrol_main_main_self_t* self = (_pololucontrol_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bluetooth {
        _bluetooth_message_received_trigger_t* message_received_trigger;
    
    } bluetooth;
    bluetooth.message_received_trigger = self->_lf_bluetooth.message_received_trigger;
    #line 49 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    strcpy(self->command, bluetooth.incoming_message);
    float amt = 0.0f;
    char amt_str[4];
    strncpy(amt_str, &self->command[strlen(self->command)-3], 3);
    amt_str[3] = '\0'; // Null-terminate the string
    amt = atof(amt_str);
    lf_set(pololu.drive_amount, amt);
    if (matchesCommand(TURN_LEFT_COMMAND)) {
      lf_set(pololu.drive_mode, 2);
      lf_set(pololu.drive_direction, 0);
      strcpy(self->reply, "Turned left");
    } else if (matchesCommand(TURN_RIGHT_COMMAND)) {
      lf_set(pololu.drive_mode, 2);
      lf_set(pololu.drive_direction, 1);
      strcpy(self->reply, "Turned right");
    } else if (matchesCommand(MOVE_FORWARD_COMMAND)) {
      lf_set(pololu.drive_mode, 1);
      lf_set(pololu.drive_direction, 0);
      strcpy(self->reply, "Moved forward");
    } else if (matchesCommand(MOVE_BACKWARD_COMMAND)) {
      lf_set(pololu.drive_mode, 1);
      lf_set(pololu.drive_direction, 1);
      strcpy(self->reply, "Moved backward");
    } else if (matchesCommand(STOP_COMMAND)) {
      lf_set(pololu.drive_mode, 0);
      strcpy(self->reply, "Stopped");
    } else {
      strcpy(self->reply, "Unknown command");
    }
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
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.last = NULL;
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.number_of_reactions = 0;
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.facing_angle_trigger.physical_time_of_arrival = NEVER;
    #line 26 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.last = NULL;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.number_of_reactions = 0;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #ifdef FEDERATED
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    self->_lf_pololu.current_mode_trigger.physical_time_of_arrival = NEVER;
    #line 27 "/home/foobar/149project/src/pololu_control/Pololu.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_bluetooth_width = -2;
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.message_received_trigger_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.message_received_trigger_reactions[0] = &self->_lf__reaction_1;
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.message_received_trigger_trigger.reactions = self->_lf_bluetooth.message_received_trigger_reactions;
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.message_received_trigger_trigger.last = NULL;
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.message_received_trigger_trigger.number_of_reactions = 1;
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_bluetooth.message_received_trigger_trigger.physical_time_of_arrival = NEVER;
    #line 62 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #endif // FEDERATED
    #line 38 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.number = 0;
    #line 38 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.function = _pololucontrol_mainreaction_function_0;
    #line 38 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.self = self;
    #line 38 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 38 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 38 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.name = "?";
    #line 38 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 48 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.number = 1;
    #line 48 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.function = _pololucontrol_mainreaction_function_1;
    #line 48 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.self = self;
    #line 48 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 48 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 48 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.name = "?";
    #line 48 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.last = NULL;
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #ifdef FEDERATED
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 33 "/home/foobar/149project/src/pololu_control/PololuControl.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
