#include "include/api/api.h"
#include "include/Lights/Lights.h"
#include "_lights.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _lightsreaction_function_0(void* instance_args) {
    _lights_self_t* self = (_lights_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 24 "/home/foobar/149project/src/pololu_control/Lights.lf"
    gpio_init(RED_LED_PIN);
    gpio_init(YELLOW_LED_PIN);
    gpio_init(GREEN_LED_PIN);
    
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _lightsreaction_function_1(void* instance_args) {
    _lights_self_t* self = (_lights_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 34 "/home/foobar/149project/src/pololu_control/Lights.lf"
    gpio_put(RED_LED_PIN, !gpio_get(RED_LED_PIN));
    gpio_put(GREEN_LED_PIN, !gpio_get(GREEN_LED_PIN));
    gpio_put(YELLOW_LED_PIN, !gpio_get(YELLOW_LED_PIN));
}
#include "include/api/set_undef.h"
_lights_self_t* new__lights() {
    _lights_self_t* self = (_lights_self_t*)_lf_new_reactor(sizeof(_lights_self_t));
    #line 23 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_0.number = 0;
    #line 23 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_0.function = _lightsreaction_function_0;
    #line 23 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_0.self = self;
    #line 23 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 23 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 23 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_0.name = "?";
    #line 23 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 33 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_1.number = 1;
    #line 33 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_1.function = _lightsreaction_function_1;
    #line 33 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_1.self = self;
    #line 33 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 33 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 33 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_1.name = "?";
    #line 33 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__t.last = NULL;
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    #ifdef FEDERATED
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 21 "/home/foobar/149project/src/pololu_control/Lights.lf"
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
