#include "include/api/api.h"
#include "include/ReceiveMessages2/ReceiveMessages2.h"
#include "_receivemessages2_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _receivemessages2_mainreaction_function_0(void* instance_args) {
    _receivemessages2_main_main_self_t* self = (_receivemessages2_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 83 "/Users/alex/149project/src/ReceiveMessages2.lf"
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
void _receivemessages2_mainreaction_function_1(void* instance_args) {
    _receivemessages2_main_main_self_t* self = (_receivemessages2_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 98 "/Users/alex/149project/src/ReceiveMessages2.lf"
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
void _receivemessages2_mainreaction_function_2(void* instance_args) {
    _receivemessages2_main_main_self_t* self = (_receivemessages2_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct acc {
        _accelerometer_x_t* x;
    _accelerometer_y_t* y;
    
    } acc;
    acc.x = self->_lf_acc.x;
    acc.y = self->_lf_acc.y;
    #line 119 "/Users/alex/149project/src/ReceiveMessages2.lf"
    while (self->counter < 6) {
        self->x += acc.x->value;
        self->y += acc.y->value;
        if (self->counter == 5) {
            self->x /= 5;
            self->y /=5;
        }
        self->counter += 1;
    }
}
#include "include/api/set_undef.h"
_receivemessages2_main_main_self_t* new__receivemessages2_main() {
    _receivemessages2_main_main_self_t* self = (_receivemessages2_main_main_self_t*)_lf_new_reactor(sizeof(_receivemessages2_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_acc_width = -2;
    #line 40 "/Users/alex/149project/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 40 "/Users/alex/149project/src/lib/IMU.lf"
    self->_lf_acc.x_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 40 "/Users/alex/149project/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 40 "/Users/alex/149project/src/lib/IMU.lf"
    self->_lf_acc.x_trigger.last = NULL;
    #line 40 "/Users/alex/149project/src/lib/IMU.lf"
    self->_lf_acc.x_trigger.number_of_reactions = 0;
    #line 40 "/Users/alex/149project/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 40 "/Users/alex/149project/src/lib/IMU.lf"
    self->_lf_acc.x_trigger.physical_time_of_arrival = NEVER;
    #line 40 "/Users/alex/149project/src/lib/IMU.lf"
    #endif // FEDERATED
    #line 41 "/Users/alex/149project/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 41 "/Users/alex/149project/src/lib/IMU.lf"
    self->_lf_acc.y_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 41 "/Users/alex/149project/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 41 "/Users/alex/149project/src/lib/IMU.lf"
    self->_lf_acc.y_trigger.last = NULL;
    #line 41 "/Users/alex/149project/src/lib/IMU.lf"
    self->_lf_acc.y_trigger.number_of_reactions = 0;
    #line 41 "/Users/alex/149project/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 41 "/Users/alex/149project/src/lib/IMU.lf"
    self->_lf_acc.y_trigger.physical_time_of_arrival = NEVER;
    #line 41 "/Users/alex/149project/src/lib/IMU.lf"
    #endif // FEDERATED
    #line 82 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_0.number = 0;
    #line 82 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_0.function = _receivemessages2_mainreaction_function_0;
    #line 82 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_0.self = self;
    #line 82 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 82 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 82 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_0.name = "?";
    #line 82 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 97 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_1.number = 1;
    #line 97 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_1.function = _receivemessages2_mainreaction_function_1;
    #line 97 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_1.self = self;
    #line 97 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 97 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 97 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_1.name = "?";
    #line 97 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 118 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_2.number = 2;
    #line 118 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_2.function = _receivemessages2_mainreaction_function_2;
    #line 118 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_2.self = self;
    #line 118 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 118 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 118 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_2.name = "?";
    #line 118 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__t.last = NULL;
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__t_reactions[1] = &self->_lf__reaction_2;
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__t.number_of_reactions = 2;
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    #ifdef FEDERATED
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 68 "/Users/alex/149project/src/ReceiveMessages2.lf"
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
    #line 117 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 117 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__modes[0].name = "CALIBRATING";
    #line 117 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 117 "/Users/alex/149project/src/ReceiveMessages2.lf"
    self->_lf__modes[0].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
