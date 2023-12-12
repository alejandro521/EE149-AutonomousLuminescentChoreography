#include "include/api/api.h"
#include "include/ReceiveMessages/ReceiveMessages.h"
#include "_receivemessages_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _receivemessages_mainreaction_function_0(void* instance_args) {
    _receivemessages_main_main_self_t* self = (_receivemessages_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 77 "/Users/alex/149project/src/ReceiveMessages.lf"
    uart_init(uart0, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    
    // Clear UART buffer
    while (uart_is_readable(uart0)) {
        uart_getc(uart0);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _receivemessages_mainreaction_function_1(void* instance_args) {
    _receivemessages_main_main_self_t* self = (_receivemessages_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 92 "/Users/alex/149project/src/ReceiveMessages.lf"
    lf_set(disp.line0, self->name);
    
    // Display last transmitted message
    static char buf_sent[17];
    snprintf(buf_sent, 17, "S:%s", self->transmitted_message);
    lf_set(disp.line1, buf_sent);
    
    // Display last received message
    static char buf_received[17];
    printf("R: %s\n", self->received_message);
    snprintf(buf_received, 17, "R:%s", self->received_message);
    printf("B: %s\n", buf_received);
    lf_set(disp.line2, buf_received);
    
    // LED Blink
    self->led_on = !self->led_on;
    gpio_put(PICO_DEFAULT_LED_PIN, self->led_on);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _receivemessages_mainreaction_function_2(void* instance_args) {
    _receivemessages_main_main_self_t* self = (_receivemessages_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct pololu {
        _robot_drive_mode_t* drive_mode;
    _robot_direction_t* direction;
    
    } pololu;
    reactor_mode_t* REPLYING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_REPLYING_change_type = reset_transition;
    pololu.drive_mode = &(self->_lf_pololu.drive_mode);
    pololu.direction = &(self->_lf_pololu.direction);
    #line 113 "/Users/alex/149project/src/ReceiveMessages.lf"
    // Read from UART if readable
    if (uart_is_readable(uart0)) {
      receiveMessage(uart0, self->received_message);
      if (strncmp(SET_NAME_COMMAND, self->received_message, strlen(SET_NAME_COMMAND)) == 0) {
        strcpy(self->name, self->received_message + strlen(SET_NAME_COMMAND));
        snprintf(self->reply, 100, "Name:%s", self->name);
      } else if (strncmp(DRIVE_COMMAND, self->received_message, strlen(DRIVE_COMMAND)) == 0) {
        lf_set(pololu.drive_mode, 1);
        lf_set(pololu.direction, 0);
        snprintf(self->reply, 100, "%s is driving", self->name);  
      } else if (strncmp(TURN_COMMAND, self->received_message, strlen(TURN_COMMAND)) == 0) {
        lf_set(pololu.drive_mode, 2);
        lf_set(pololu.direction, 0);
        snprintf(self->reply, 100, "%s is turning", self->name);  
      } else {
        snprintf(self->reply, 100, "Received: %s", self->received_message);  
      }
      lf_set_mode(REPLYING);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _receivemessages_mainreaction_function_3(void* instance_args) {
    _receivemessages_main_main_self_t* self = (_receivemessages_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    reactor_mode_t* RECEIVING = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_RECEIVING_change_type = reset_transition;
    #line 137 "/Users/alex/149project/src/ReceiveMessages.lf"
    transmitMessage(uart0, self->reply, self->transmitted_message);
    lf_set_mode(RECEIVING);
}
#include "include/api/set_undef.h"
_receivemessages_main_main_self_t* new__receivemessages_main() {
    _receivemessages_main_main_self_t* self = (_receivemessages_main_main_self_t*)_lf_new_reactor(sizeof(_receivemessages_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_pololu_width = -2;
    #line 76 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_0.number = 0;
    #line 76 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_0.function = _receivemessages_mainreaction_function_0;
    #line 76 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_0.self = self;
    #line 76 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 76 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 76 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_0.name = "?";
    #line 76 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 91 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_1.number = 1;
    #line 91 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_1.function = _receivemessages_mainreaction_function_1;
    #line 91 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_1.self = self;
    #line 91 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 91 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 91 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_1.name = "?";
    #line 91 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 112 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_2.number = 2;
    #line 112 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_2.function = _receivemessages_mainreaction_function_2;
    #line 112 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_2.self = self;
    #line 112 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 112 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 112 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_2.name = "?";
    #line 112 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    #line 136 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_3.number = 3;
    #line 136 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_3.function = _receivemessages_mainreaction_function_3;
    #line 136 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_3.self = self;
    #line 136 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 136 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 136 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_3.name = "?";
    #line 136 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__t.last = NULL;
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__t_reactions[1] = &self->_lf__reaction_2;
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__t_reactions[2] = &self->_lf__reaction_3;
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__t.number_of_reactions = 3;
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    #ifdef FEDERATED
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 66 "/Users/alex/149project/src/ReceiveMessages.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
    #line 111 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 111 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__modes[0].name = "RECEIVING";
    #line 111 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 111 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__modes[0].flags = 0;
    #line 135 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 135 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__modes[1].name = "REPLYING";
    #line 135 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 135 "/Users/alex/149project/src/ReceiveMessages.lf"
    self->_lf__modes[1].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
