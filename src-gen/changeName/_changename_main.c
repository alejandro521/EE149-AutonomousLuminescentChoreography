#include "include/api/api.h"
#include "include/changeName/changeName.h"
#include "_changename_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _changename_mainreaction_function_0(void* instance_args) {
    _changename_main_main_self_t* self = (_changename_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 58 "/home/foobar/finalproject/src/changeName.lf"
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
    transmitMessage(uart0, "AT+NAMEPololu1", self->transmitted_message);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _changename_mainreaction_function_1(void* instance_args) {
    _changename_main_main_self_t* self = (_changename_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 75 "/home/foobar/finalproject/src/changeName.lf"
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
    snprintf(buf_received, 17, "R:%s", self->received_message);
    lf_set(disp.line2, buf_received);
    
    // LED Blink
    self->led_on = !self->led_on;
    gpio_put(PICO_DEFAULT_LED_PIN, self->led_on);
}
#include "include/api/set_undef.h"
_changename_main_main_self_t* new__changename_main() {
    _changename_main_main_self_t* self = (_changename_main_main_self_t*)_lf_new_reactor(sizeof(_changename_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    #line 57 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_0.number = 0;
    #line 57 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_0.function = _changename_mainreaction_function_0;
    #line 57 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_0.self = self;
    #line 57 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 57 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 57 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_0.name = "?";
    #line 57 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 74 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_1.number = 1;
    #line 74 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_1.function = _changename_mainreaction_function_1;
    #line 74 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_1.self = self;
    #line 74 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 74 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 74 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_1.name = "?";
    #line 74 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__t.last = NULL;
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    #ifdef FEDERATED
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 51 "/home/foobar/finalproject/src/changeName.lf"
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
