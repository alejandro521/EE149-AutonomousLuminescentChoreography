#include "include/api/api.h"
#include "include/Choreo/Choreo.h"
#include "_choreo_main.h"
// ***** Start of method declarations.
void _choreo_main_method_setCommand(void* instance_args);
void _choreo_main_method_receiveMessage(void* instance_args, char* received_message);
void _choreo_main_method_transmitMessage(void* instance_args, char* message, char* transmitted_message);
#define setCommand() _choreo_main_method_setCommand(self)
#define receiveMessage(...) _choreo_main_method_receiveMessage(self, ##__VA_ARGS__)
#define transmitMessage(...) _choreo_main_method_transmitMessage(self, ##__VA_ARGS__)
#line 56 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method setCommand()
void _choreo_main_method_setCommand(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 57 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    char* command; 
    if (self->received_message[0] == '0') {
      self->curr_mode = "NEW_DRIVING";
    }
    if (self->received_message[1] == '0') {
      self->speed = 0.0f;
    }
    if (self->received_message[1] == '1') {
      self->speed = 0.25f;
    }
    if (self->received_message[1] == '2') {
      self->speed = 0.5f;
    }
    if (self->received_message[1] == '3') {
      self->speed = 0.75f;
    }
    if (self->received_message[2] == '0') {
      self->leds_on = false;
    }
    if (self->received_message[2] == '1') {
      self->leds_on = true;
    }
    self->target_distance = atof(self->received_message[3]) / 10.0f;
}
#line 84 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method receiveMessage()
void _choreo_main_method_receiveMessage(void* instance_args, char* received_message) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 85 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
     char received_char;
     while (uart_is_readable(uart0)) { 
       received_char = uart_getc(uart0);
       if (received_char == '!') {
         received_message[self->i] = '\0'; // Null terminate the string
         self->i = 0;
         setCommand();
       } else if (self->i < MAX_MSG_LENGTH - 1) {
         received_message[self->i] = received_char;
         self->i += 1;
       }
     }
    // received_message[i] = '\0'; // Null terminate the string
}
#line 102 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method transmitMessage()
void _choreo_main_method_transmitMessage(void* instance_args, char* message, char* transmitted_message) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 103 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    int index = 0;
    while (*message && index < MAX_MSG_LENGTH) {
      uart_putc(uart0, *message);
      transmitted_message[index] = *message;
      index++;
      message++;
    }
    uart_putc(uart0, '\r'); // Carriage return
    uart_putc(uart0, '\n'); // newline
    transmitted_message[index] = '\0';
}
#undef setCommand
#undef receiveMessage
#undef transmitMessage
// ***** End of method declarations.
#include "include/api/set.h"
#define setCommand() _choreo_main_method_setCommand(self)
#define receiveMessage(...) _choreo_main_method_receiveMessage(self, ##__VA_ARGS__)
#define transmitMessage(...) _choreo_main_method_transmitMessage(self, ##__VA_ARGS__)
void _choreo_mainreaction_function_0(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 116 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    gpio_init(RED_LED_PIN);
    gpio_init(YELLOW_LED_PIN);
    gpio_init(GREEN_LED_PIN);
    
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    
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
#undef setCommand
#undef receiveMessage
#undef transmitMessage
#include "include/api/set_undef.h"
#include "include/api/set.h"
#define setCommand() _choreo_main_method_setCommand(self)
#define receiveMessage(...) _choreo_main_method_receiveMessage(self, ##__VA_ARGS__)
#define transmitMessage(...) _choreo_main_method_transmitMessage(self, ##__VA_ARGS__)
void _choreo_mainreaction_function_1(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct e {
        _encoders_trigger_t* trigger;
    
    } e;
    struct gyro {
        _gyroangle_trigger_t* trigger;
    
    } gyro;
    struct d {
        _display_line2_t* line2;
    
    } d;
    e.trigger = &(self->_lf_e.trigger);
    gyro.trigger = &(self->_lf_gyro.trigger);
    d.line2 = &(self->_lf_d.line2);
    #line 138 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
      lf_set(e.trigger, true);
      lf_set(gyro.trigger, true);
    
      if (uart_is_readable(uart0)) {
      receiveMessage(self->received_message);
    }
    
      static char buf_received[17];
      printf("R: %s\n", self->received_message);
      snprintf(buf_received, 17, "R:%s", self->received_message);
      printf("B: %s\n", buf_received);
      lf_set(d.line2, buf_received);
}
#undef setCommand
#undef receiveMessage
#undef transmitMessage
#include "include/api/set_undef.h"
#include "include/api/set.h"
#define setCommand() _choreo_main_method_setCommand(self)
#define receiveMessage(...) _choreo_main_method_receiveMessage(self, ##__VA_ARGS__)
#define transmitMessage(...) _choreo_main_method_transmitMessage(self, ##__VA_ARGS__)
void _choreo_mainreaction_function_2(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct angleToDistanceR {
        _angletodistance_distance_t* distance;
    
    } angleToDistanceR;
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
    angleToDistanceR.distance = self->_lf_angleToDistanceR.distance;
    gyro.z = self->_lf_gyro.z;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    reactor_mode_t* ROTATING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_ROTATING_change_type = reset_transition;
    #line 157 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    if (angleToDistanceR.distance->value - self->previousDistance > 1.0) {
      lf_set(m.left_power, 0.0f);
      lf_set(m.right_power, 0.0f);
      self->previousDistance = angleToDistanceR.distance->value;
      self->previousAngle = gyro.z->value; 
      lf_set_mode(ROTATING);
    } else {
      lf_set(d.line0, "DRIVE");
      lf_set(m.left_power, 0.5f);
      lf_set(m.right_power, 0.5f);
    
    }
}
#undef setCommand
#undef receiveMessage
#undef transmitMessage
#include "include/api/set_undef.h"
#include "include/api/set.h"
#define setCommand() _choreo_main_method_setCommand(self)
#define receiveMessage(...) _choreo_main_method_receiveMessage(self, ##__VA_ARGS__)
#define transmitMessage(...) _choreo_main_method_transmitMessage(self, ##__VA_ARGS__)
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
    #line 186 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    if (gyro.z->value - self->previousAngle < -1080.0) {
      lf_set(m.left_power, 0.0f);
      self->previousAngle = gyro.z->value;
      lf_set_mode(DRIVING);
    } else {
      lf_set(d.line0, "ROTATE");
      lf_set(m.left_power, 1.0f);
    }
}
#undef setCommand
#undef receiveMessage
#undef transmitMessage
#include "include/api/set_undef.h"
#include "include/api/set.h"
#define setCommand() _choreo_main_method_setCommand(self)
#define receiveMessage(...) _choreo_main_method_receiveMessage(self, ##__VA_ARGS__)
#define transmitMessage(...) _choreo_main_method_transmitMessage(self, ##__VA_ARGS__)
void _choreo_mainreaction_function_4(void* instance_args) {
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
    reactor_mode_t* NEW_DRIVING = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_NEW_DRIVING_change_type = reset_transition;
    #line 199 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    if (gyro.z->value - self->previousAngle < -self->num_rotations * 360) {
      lf_set(m.left_power, 0.0f);
      self->previousAngle = gyro.z->value;
      lf_set_mode(NEW_DRIVING);
    } else {
      lf_set(d.line0, "ROTATE");
      lf_set(m.left_power, self->speed);
    }
}
#undef setCommand
#undef receiveMessage
#undef transmitMessage
#include "include/api/set_undef.h"
#include "include/api/set.h"
#define setCommand() _choreo_main_method_setCommand(self)
#define receiveMessage(...) _choreo_main_method_receiveMessage(self, ##__VA_ARGS__)
#define transmitMessage(...) _choreo_main_method_transmitMessage(self, ##__VA_ARGS__)
void _choreo_mainreaction_function_5(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct angleToDistanceR {
        _angletodistance_distance_t* distance;
    
    } angleToDistanceR;
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
    angleToDistanceR.distance = self->_lf_angleToDistanceR.distance;
    gyro.z = self->_lf_gyro.z;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    reactor_mode_t* NEW_ROTATING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_NEW_ROTATING_change_type = reset_transition;
    #line 213 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    //Convert integer 0 or 1 to a bool
    if (self->leds_on) {
        gpio_put(RED_LED_PIN, 1);
        gpio_put(YELLOW_LED_PIN, 0);
        gpio_put(GREEN_LED_PIN, 1);
        self->leds_on = !self->leds_on;
    } else {
      gpio_put(RED_LED_PIN, 0);
      gpio_put(YELLOW_LED_PIN, 1);
      gpio_put(GREEN_LED_PIN, 0);            
      self->leds_on = !self->leds_on;
    }
    if (angleToDistanceR.distance->value - self->previousDistance > self->target_distance) {
      lf_set(m.left_power, self->speed); 
      lf_set(m.right_power, self->speed);
      self->previousDistance = angleToDistanceR.distance->value;
      self->previousAngle = gyro.z->value; 
      lf_set_mode(NEW_ROTATING);
    } else {
      lf_set(d.line0, "DRIVE");
      lf_set(m.left_power, self->speed);
      lf_set(m.right_power, self->speed);
    }
}
#undef setCommand
#undef receiveMessage
#undef transmitMessage
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
    self->_lf_gyro.z_reactions[1] = &self->_lf__reaction_4;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.reactions = self->_lf_gyro.z_reactions;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.last = NULL;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.number_of_reactions = 2;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.physical_time_of_arrival = NEVER;
    #line 125 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/IMU.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_d_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_m_width = -2;
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
    self->_lf_angleToDistanceR.distance_reactions[1] = &self->_lf__reaction_5;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.reactions = self->_lf_angleToDistanceR.distance_reactions;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.last = NULL;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.number_of_reactions = 2;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    #ifdef FEDERATED
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    self->_lf_angleToDistanceR.distance_trigger.physical_time_of_arrival = NEVER;
    #line 15 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/AngleToDistance.lf"
    #endif // FEDERATED
    #line 115 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.number = 0;
    #line 115 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.function = _choreo_mainreaction_function_0;
    #line 115 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.self = self;
    #line 115 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 115 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 115 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.name = "?";
    #line 115 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 137 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.number = 1;
    #line 137 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.function = _choreo_mainreaction_function_1;
    #line 137 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.self = self;
    #line 137 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 137 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 137 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.name = "?";
    #line 137 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 156 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.number = 2;
    #line 156 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.function = _choreo_mainreaction_function_2;
    #line 156 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.self = self;
    #line 156 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 156 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 156 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.name = "?";
    #line 156 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    #line 185 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.number = 3;
    #line 185 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.function = _choreo_mainreaction_function_3;
    #line 185 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.self = self;
    #line 185 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 185 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 185 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.name = "?";
    #line 185 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    #line 198 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.number = 4;
    #line 198 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.function = _choreo_mainreaction_function_4;
    #line 198 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.self = self;
    #line 198 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 198 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 198 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.name = "?";
    #line 198 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[2];
    #line 212 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.number = 5;
    #line 212 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.function = _choreo_mainreaction_function_5;
    #line 212 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.self = self;
    #line 212 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 212 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 212 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.name = "?";
    #line 212 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.mode = &self->_lf__modes[3];
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.last = NULL;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 54 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    #line 155 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 155 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].name = "DRIVING";
    #line 155 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 155 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].flags = 0;
    #line 184 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 184 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].name = "ROTATING";
    #line 184 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 184 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].flags = 0;
    #line 197 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    #line 197 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].name = "NEW_ROTATING";
    #line 197 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].deactivation_time = 0;
    #line 197 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].flags = 0;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[3].state = &_lf_self_base->_lf__mode_state;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[3].name = "NEW_DRIVING";
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[3].deactivation_time = 0;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[3].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[3];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
