#include "include/api/api.h"
#include "include/basicComs/basicComs.h"
#include "_basiccoms_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _basiccoms_mainreaction_function_0(void* instance_args) {
    _basiccoms_main_main_self_t* self = (_basiccoms_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    #line 28 "/home/foobar/finalproject/src/basicComs.lf"
    //Set up UART and set pins
       lf_set(disp.line0, "START UP");
       uart_init(uart0, BAUD_RATE);
       uart_set_fifo_enabled(uart0, false);
       uart_set_hw_flow(uart0, false, false); 
       gpio_init(UART_TX_PIN);
       gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
       gpio_init(UART_RX_PIN);
       gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
       gpio_init(PICO_DEFAULT_LED_PIN);
       gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    
       const char* setNameCmd = "AT+NAME?";
       static char buf[17];
       if (!uart_is_enabled(uart0) || !uart_is_writable(uart0)) {
         lf_set(disp.line0, "UART NOT ENABLED OR WRITABLE");
       }
       for (const char* c = setNameCmd; *c != '\n'; ++c) {
           uart_putc(uart0, *c); // Send each character of the command
           // printf("char in send: %c", c);
           snprintf(buf, 17, "char sent:%c", c);
           lf_set(disp.line1, buf);
       }
       uart_putc(uart0, '\r'); // Carriage return to execute the command
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _basiccoms_mainreaction_function_1(void* instance_args) {
    _basiccoms_main_main_self_t* self = (_basiccoms_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line2_t* line2;
    _display_line3_t* line3;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line2 = &(self->_lf_disp.line2);
    disp.line3 = &(self->_lf_disp.line3);
    #line 56 "/home/foobar/finalproject/src/basicComs.lf"
    self->led_on = !self->led_on;
    // printf("LED State: %b/n", self->led_on);
    // lf_set(disp.line1, "LED STATE: ");
    gpio_put(PICO_DEFAULT_LED_PIN, !self->led_on);
    char tempStr[10];
    static char buf[17];
    int i = 0;
    // while (1) {
    //     char d[17] = uart_getc(uart0); // read each character of the command
    //     // printf("char: %c", c);
    //     // snprintf(buf, 1, "char recevied: %c", d);
    //     lf_set(disp.line2, d);
    //     break;
    //     // if (c == '\n') {
    //     //   tempStr[i] = c;
    //     // }
    //     // else {
    //     //   break; 
    //     // }
    //     // i += 1;
    // }
    lf_set(disp.line3, "DONE");
    printf("Check connection and read name: %s\n", tempStr);
}
#include "include/api/set_undef.h"
_basiccoms_main_main_self_t* new__basiccoms_main() {
    _basiccoms_main_main_self_t* self = (_basiccoms_main_main_self_t*)_lf_new_reactor(sizeof(_basiccoms_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    #line 27 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_0.number = 0;
    #line 27 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_0.function = _basiccoms_mainreaction_function_0;
    #line 27 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_0.self = self;
    #line 27 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 27 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 27 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_0.name = "?";
    #line 27 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 55 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_1.number = 1;
    #line 55 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_1.function = _basiccoms_mainreaction_function_1;
    #line 55 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_1.self = self;
    #line 55 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 55 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 55 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_1.name = "?";
    #line 55 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__t.last = NULL;
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    #ifdef FEDERATED
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 24 "/home/foobar/finalproject/src/basicComs.lf"
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
