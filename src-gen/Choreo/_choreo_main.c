#include "include/api/api.h"
#include "include/Choreo/Choreo.h"
#include "_choreo_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _choreo_mainreaction_function_0(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 38 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    gpio_init(RED_LED_PIN);
    gpio_init(YELLOW_LED_PIN);
    gpio_init(GREEN_LED_PIN);
    
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    
    // gpio_put(RED_LED_PIN, 1);
    // gpio_put(YELLOW_LED_PIN, 1);
    // gpio_put(GREEN_LED_PIN, 1);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _choreo_mainreaction_function_1(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct e {
        _encoders_trigger_t* trigger;
    
    } e;
    struct gyro {
        _gyroangle_trigger_t* trigger;
    
    } gyro;
    e.trigger = &(self->_lf_e.trigger);
    gyro.trigger = &(self->_lf_gyro.trigger);
    #line 52 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    lf_set(e.trigger, true);
    lf_set(gyro.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _choreo_mainreaction_function_2(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct angleToDistanceR {
        _angletodistance_distance_t* distance;
    
    } angleToDistanceR;
    struct m {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } m;
    struct d {
        _display_line0_t* line0;
    
    } d;
    angleToDistanceR.distance = self->_lf_angleToDistanceR.distance;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    reactor_mode_t* ROTATING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_ROTATING_change_type = reset_transition;
    #line 61 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    if (self->leds_on) {
      gpio_put(RED_LED_PIN, 1);
      gpio_put(YELLOW_LED_PIN, 0);
      gpio_put(GREEN_LED_PIN, 1);
      self->leds_on = !self->leds_on;
    }
    else {
      gpio_put(RED_LED_PIN, 0);
      gpio_put(YELLOW_LED_PIN, 1);
      gpio_put(GREEN_LED_PIN, 0);
      self->leds_on = !self->leds_on;
    }
    if (angleToDistanceR.distance->value - self->previousDistance > 0.5) {
      lf_set(m.left_power, 0.0f);
      lf_set(m.right_power, 0.0f);
      self->previousDistance = angleToDistanceR.distance->value;
      lf_set_mode(ROTATING);
    } else {
      lf_set(d.line0, "DRIVE");
      lf_set(m.left_power, 0.5f);
      lf_set(m.right_power, 0.5f);
    
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _choreo_mainreaction_function_3(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    struct m {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } m;
    struct d {
        _display_line0_t* line0;
    
    } d;
    gyro.z = self->_lf_gyro.z;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    reactor_mode_t* DRIVING = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    #line 101 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    if (gyro.z->value - self->previousAngle < -90.0) {
      lf_set(m.left_power, 0.0f);
      self->previousAngle = gyro.z->value;
      lf_set_mode(DRIVING);
    } else {
      lf_set(d.line0, "ROTATE");
      lf_set(m.left_power, 0.1f);
    }
}
#include "include/api/set_undef.h"
_choreo_main_main_self_t* new__choreo_main() {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)_lf_new_reactor(sizeof(_choreo_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_e_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_gyro_width = -2;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_reactions[0] = &self->_lf__reaction_3;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.reactions = self->_lf_gyro.z_reactions;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.last = NULL;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.number_of_reactions = 1;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.physical_time_of_arrival = NEVER;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_m_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_d_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_angleToDistanceR_width = -2;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_reactions[0] = &self->_lf__reaction_2;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.reactions = self->_lf_angleToDistanceR.distance_reactions;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.last = NULL;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.number_of_reactions = 1;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    #ifdef FEDERATED
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.physical_time_of_arrival = NEVER;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    #endif // FEDERATED
    #line 37 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.number = 0;
    #line 37 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.function = _choreo_mainreaction_function_0;
    #line 37 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.self = self;
    #line 37 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 37 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 37 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.name = "?";
    #line 37 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.number = 1;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.function = _choreo_mainreaction_function_1;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.self = self;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.name = "?";
    #line 51 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.number = 2;
    #line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.function = _choreo_mainreaction_function_2;
    #line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.self = self;
    #line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.name = "?";
    #line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    #line 100 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.number = 3;
    #line 100 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.function = _choreo_mainreaction_function_3;
    #line 100 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.self = self;
    #line 100 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 100 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 100 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.name = "?";
    #line 100 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.last = NULL;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 35 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    #line 59 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 59 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].name = "DRIVING";
    #line 59 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 59 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].flags = 0;
    #line 99 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 99 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].name = "ROTATING";
    #line 99 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 99 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
