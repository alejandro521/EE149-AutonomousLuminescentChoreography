#include "include/api/api.h"
#include "include/ReceieveName/ReceieveName.h"
#include "_receievename_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _receievename_mainreaction_function_0(void* instance_args) {
    _receievename_main_main_self_t* self = (_receievename_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 59 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    uart_init(uart0, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    
    // Clear UART buffer
    while (uart_is_readable(uart0)) {
        uart_getc(uart0);
    }
    
    // Send AT+NAMEPololu command
    transmitMessage(uart0, "AT", self->transmitted_message);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _receievename_mainreaction_function_1(void* instance_args) {
    _receievename_main_main_self_t* self = (_receievename_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 76 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    // Read from UART if readable
    if (uart_is_readable(uart0)) {
      receiveMessage(uart0, self->received_message);
    }
    
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
_receievename_main_main_self_t* new__receievename_main() {
    _receievename_main_main_self_t* self = (_receievename_main_main_self_t*)_lf_new_reactor(sizeof(_receievename_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_0.number = 0;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_0.function = _receievename_mainreaction_function_0;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_0.self = self;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_0.name = "?";
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 75 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_1.number = 1;
    #line 75 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_1.function = _receievename_mainreaction_function_1;
    #line 75 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_1.self = self;
    #line 75 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 75 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 75 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_1.name = "?";
    #line 75 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__t.last = NULL;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    #ifdef FEDERATED
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/ReceieveName.lf"
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
