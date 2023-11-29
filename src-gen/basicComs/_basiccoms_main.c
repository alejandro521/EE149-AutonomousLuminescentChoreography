#include "include/api/api.h"
#include "include/basicComs/basicComs.h"
#include "_basiccoms_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _basiccoms_mainreaction_function_0(void* instance_args) {
    _basiccoms_main_main_self_t* self = (_basiccoms_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 26 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    //Set up UART and set pins
       uart_init(uart0, BAUD_RATE);
       gpio_init(UART_TX_PIN);
       gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
       gpio_init(UART_RX_PIN);
       gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
       gpio_init(PICO_DEFAULT_LED_PIN);
       gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    
       const char* setNameCmd = "AT+NAME=Pololu";
       for (const char* c = setNameCmd; *c != '\0'; ++c) {
           uart_putc(uart0, *c); // Send each character of the command
           printf("char in send: %c", c);
       }
       uart_putc(uart0, '\r'); // Carriage return to execute the command
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _basiccoms_mainreaction_function_1(void* instance_args) {
    _basiccoms_main_main_self_t* self = (_basiccoms_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 45 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->led_on = !self->led_on;
    printf("LED State: %b/n", self->led_on);
    gpio_put(PICO_DEFAULT_LED_PIN, !self->led_on);
    char tempStr[10];
    int i = 0;
    while (1) {
        char c = uart_getc(uart0); // read each character of the command
        printf("char: %c", c);
        if (c != '\n') {
          tempStr[i] = c;
        }
        i += 1;
    }
    printf("Check connection and read name: %s\n", tempStr);
}
#include "include/api/set_undef.h"
_basiccoms_main_main_self_t* new__basiccoms_main() {
    _basiccoms_main_main_self_t* self = (_basiccoms_main_main_self_t*)_lf_new_reactor(sizeof(_basiccoms_main_main_self_t));
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_0.number = 0;
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_0.function = _basiccoms_mainreaction_function_0;
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_0.self = self;
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_0.name = "?";
    #line 25 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_1.number = 1;
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_1.function = _basiccoms_mainreaction_function_1;
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_1.self = self;
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_1.name = "?";
    #line 44 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__t.last = NULL;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    #ifdef FEDERATED
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 22 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/basicComs.lf"
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
