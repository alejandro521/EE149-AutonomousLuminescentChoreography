#include "include/api/api.h"
#include "include/Bluetooth/Bluetooth.h"
#include "_bluetooth.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _bluetoothreaction_function_0(void* instance_args) {
    _bluetooth_self_t* self = (_bluetooth_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _bluetooth_message_received_trigger_t* message_received_trigger = &self->_lf_message_received_trigger;
    #line 69 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    uart_init(uart0, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    
    lf_set(message_received_trigger, false);
    // Clear UART buffer
    while (uart_is_readable(uart0)) {
      uart_getc(uart0);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _bluetoothreaction_function_1(void* instance_args) {
    _bluetooth_self_t* self = (_bluetooth_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _bluetooth_incoming_message_t* incoming_message = &self->_lf_incoming_message;
    _bluetooth_message_received_trigger_t* message_received_trigger = &self->_lf_message_received_trigger;
    #line 84 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    if (receiveMessage(uart0, incoming_message->value)) {
      lf_set(message_received_trigger, !message_received_trigger);
    };
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _bluetoothreaction_function_2(void* instance_args) {
    _bluetooth_self_t* self = (_bluetooth_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _bluetooth_message_send_trigger_t* message_send_trigger = self->_lf_message_send_trigger;
    int message_send_trigger_width = self->_lf_message_send_trigger_width; SUPPRESS_UNUSED_WARNING(message_send_trigger_width);
    _bluetooth_outgoing_message_t* outgoing_message = self->_lf_outgoing_message;
    int outgoing_message_width = self->_lf_outgoing_message_width; SUPPRESS_UNUSED_WARNING(outgoing_message_width);
    #line 90 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    transmitMessage(uart0, outgoing_message, self->transmitted_message);
}
#include "include/api/set_undef.h"
_bluetooth_self_t* new__bluetooth() {
    _bluetooth_self_t* self = (_bluetooth_self_t*)_lf_new_reactor(sizeof(_bluetooth_self_t));
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    // Set input by default to an always absent default input.
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_message_send_trigger = &self->_lf_default__message_send_trigger;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    // Set the default source reactor pointer
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_default__message_send_trigger._base.source_reactor = (self_base_t*)self;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    // Set input by default to an always absent default input.
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_outgoing_message = &self->_lf_default__outgoing_message;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    // Set the default source reactor pointer
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf_default__outgoing_message._base.source_reactor = (self_base_t*)self;
    #line 68 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_0.number = 0;
    #line 68 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_0.function = _bluetoothreaction_function_0;
    #line 68 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_0.self = self;
    #line 68 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 68 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 68 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_0.name = "?";
    #line 68 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 83 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_1.number = 1;
    #line 83 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_1.function = _bluetoothreaction_function_1;
    #line 83 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_1.self = self;
    #line 83 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 83 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 83 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_1.name = "?";
    #line 83 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 89 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_2.number = 2;
    #line 89 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_2.function = _bluetoothreaction_function_2;
    #line 89 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_2.self = self;
    #line 89 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 89 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 89 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_2.name = "?";
    #line 89 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__t.last = NULL;
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
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
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__message_send_trigger.last = NULL;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__message_send_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__message_send_trigger_reactions[0] = &self->_lf__reaction_2;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__message_send_trigger.reactions = &self->_lf__message_send_trigger_reactions[0];
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__message_send_trigger.number_of_reactions = 1;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__message_send_trigger.physical_time_of_arrival = NEVER;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #endif // FEDERATED
    self->_lf__message_send_trigger.tmplt.type.element_size = sizeof(bool);
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__outgoing_message.last = NULL;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    self->_lf__outgoing_message.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__outgoing_message.tmplt.type.element_size = sizeof(char);
    return self;
}
