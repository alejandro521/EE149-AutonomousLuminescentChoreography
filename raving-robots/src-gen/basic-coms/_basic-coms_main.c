#include "include/api/api.h"
#include "include/basic-coms/basic-coms.h"
#include "_basic-coms_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _basic-coms_mainreaction_function_0(void* instance_args) {
    _basic-coms_main_main_self_t* self = (_basic-coms_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 21 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    //Set up UART and set pins
       uart_init(PICO_DEFAULT_UART, BAUD_RATE);
       gpio_set_function(TX_PIN, PICO_DEFAULT_UART_TX_PIN);
       gpio_set_function(RX_PIN, PICO_DEFAULT_UART_RX_PIN);
    
       gpio_init(PICO_DEFAULT_LED_PIN);
       gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _basic-coms_mainreaction_function_1(void* instance_args) {
    _basic-coms_main_main_self_t* self = (_basic-coms_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 33 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    for (const char *c = c; *c != '\0'; ++c) {
        uart_putc(PICO_DEFAULT_UART, *c); //Sends one char of data to bluetooth module
    }
    uart_putc(PICO_DEFAULT_UART, '\n');
    
    uart_putc(PICO_DEFAULT_UART, 'A');
    uart_putc(PICO_DEFAULT_UART, 'T')
    
    //Receive
    while (uart_is_readable(PICO_DEFAULT_UART)) {
        char c = uart_getc(PICO_DEFAULT_UART);
        printf(c);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _basic-coms_mainreaction_function_2(void* instance_args) {
    _basic-coms_main_main_self_t* self = (_basic-coms_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->led_on = !self->led_on;
    printf("LED State: %b\n", self->led_on);
    gpio_put(PICO_DEFAULT_LED_PIN, !self->led_on);
}
#include "include/api/set_undef.h"
_basic-coms_main_main_self_t* new__basic-coms_main() {
    _basic-coms_main_main_self_t* self = (_basic-coms_main_main_self_t*)_lf_new_reactor(sizeof(_basic-coms_main_main_self_t));
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_0.number = 0;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_0.function = _basic-coms_mainreaction_function_0;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_0.self = self;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_0.name = "?";
    #line 20 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_1.number = 1;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_1.function = _basic-coms_mainreaction_function_1;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_1.self = self;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_1.name = "?";
    #line 32 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_2.number = 2;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_2.function = _basic-coms_mainreaction_function_2;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_2.self = self;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_2.name = "?";
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t1.last = NULL;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t1_reactions[0] = &self->_lf__reaction_1;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t1.reactions = &self->_lf__t1_reactions[0];
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t1.number_of_reactions = 1;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #ifdef FEDERATED
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t1.physical_time_of_arrival = NEVER;
    #line 31 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #endif // FEDERATED
    self->_lf__t1.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t.last = NULL;
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_2;
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    #ifdef FEDERATED
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 48 "/home/foobar/EE149-AutonomousLuminescentChoreography/raving-robots/basic-coms.lf"
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