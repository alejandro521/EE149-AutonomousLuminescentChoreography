#include "include/api/api.h"
#include "include/ReceiveMessages/ReceiveMessages.h"
#include "_receivemessages_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _receivemessages_mainreaction_function_0(void* instance_args) {
    _receivemessages_main_main_self_t* self = (_receivemessages_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 63 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
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
    #line 78 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    // Read from UART if readable
    if (uart_is_readable(uart0)) {
      receiveMessage(uart0, self->received_message);
    }
    
    
    // intercept SET_NAME_COMMAND
    if (strncmp(SET_NAME_COMMAND, self->received_message, strlen(SET_NAME_COMMAND)) == 0) {
      strcpy(self->name, self->received_message + strlen(SET_NAME_COMMAND));
    }
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
_receivemessages_main_main_self_t* new__receivemessages_main() {
    _receivemessages_main_main_self_t* self = (_receivemessages_main_main_self_t*)_lf_new_reactor(sizeof(_receivemessages_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_0.number = 0;
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_0.function = _receivemessages_mainreaction_function_0;
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_0.self = self;
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_0.name = "?";
    #line 62 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_1.number = 1;
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_1.function = _receivemessages_mainreaction_function_1;
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_1.self = self;
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_1.name = "?";
    #line 77 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__t.last = NULL;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    #ifdef FEDERATED
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 55 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceiveMessages.lf"
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
    return self;
}
