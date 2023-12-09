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
#line 60 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method setCommand()
void _choreo_main_method_setCommand(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 61 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    if (self->received_message[0] == '0') {
      self->curr_mode = "NEW_DRIVING";
    }
    self->speed = (float)(self->received_message[1] - '0') / 10.0;
    self->leds_on = self->received_message[2] - '0';
    self->target_distance = (float)(self->received_message[3] - '0') / 10.0;
    self->leds_blink = self->received_message[4] - '0';
    self->num_rotations = self->received_message[5] - '0';
    self->calibration_speed = 0.5f;
}
#line 73 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method receiveMessage()
void _choreo_main_method_receiveMessage(void* instance_args, char* received_message) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 74 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
#line 91 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method transmitMessage()
void _choreo_main_method_transmitMessage(void* instance_args, char* message, char* transmitted_message) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 92 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    
    #line 105 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    #line 127 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    
    // static char buf_received[17];
    // snprintf(buf_received, 17, "LEDS ON:%d", self->leds_on);
    // lf_set(d.line2, buf_received);
    
    if (self->leds_on) {
      if (self->leds_blink) {
        gpio_put(RED_LED_PIN, !gpio_get(RED_LED_PIN));
        gpio_put(GREEN_LED_PIN, !gpio_get(GREEN_LED_PIN));
        gpio_put(YELLOW_LED_PIN, !gpio_get(YELLOW_LED_PIN));
      } else {
        gpio_put(RED_LED_PIN, 1);
        gpio_put(YELLOW_LED_PIN, 1);
        gpio_put(GREEN_LED_PIN, 1);   
      }
    } else {
      gpio_put(RED_LED_PIN, 0);
      gpio_put(YELLOW_LED_PIN, 0);
      gpio_put(GREEN_LED_PIN, 0);    
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
void _choreo_mainreaction_function_2(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
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
    gyro.z = self->_lf_gyro.z;
    angleToDistanceR.distance = self->_lf_angleToDistanceR.distance;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    reactor_mode_t* NEW_DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_NEW_DRIVING_change_type = reset_transition;
    #line 167 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    if (gyro.z->value - self->previousAngle <= -3570) {
      lf_set(m.left_power, 0.0f);
      self->previousAngle = gyro.z->value;
      self->previousDistance = angleToDistanceR.distance->value;
      lf_set_mode(NEW_DRIVING);
    } else {
      lf_set(d.line0, "CALIBRATE");
      lf_set(m.left_power, self->calibration_speed);
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
    _display_line1_t* line1;
    
    } d;
    angleToDistanceR.distance = self->_lf_angleToDistanceR.distance;
    gyro.z = self->_lf_gyro.z;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    d.line1 = &(self->_lf_d.line1);
    reactor_mode_t* NEW_ROTATING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_NEW_ROTATING_change_type = reset_transition;
    #line 181 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    static char buf[17];
    snprintf(buf, 17, "targetDist:%f", self->target_distance);
    lf_set(d.line1, buf);
    if (angleToDistanceR.distance->value - self->previousDistance >= self->target_distance) {
      lf_set(m.left_power, 0.0f); 
      lf_set(m.right_power, 0.0f);
      self->previousDistance = angleToDistanceR.distance->value;
      self->previousAngle = gyro.z->value; 
      lf_set_mode(NEW_ROTATING);
    } else {
      lf_set(d.line0, "DRIVE");
      lf_set(m.left_power, self->speed);
      lf_set(m.right_power, self->speed - 0.005f);
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
    struct angleToDistanceR {
        _angletodistance_distance_t* distance;
    
    } angleToDistanceR;
    struct m {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } m;
    struct d {
        _display_line0_t* line0;
    _display_line3_t* line3;
    
    } d;
    gyro.z = self->_lf_gyro.z;
    angleToDistanceR.distance = self->_lf_angleToDistanceR.distance;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    d.line3 = &(self->_lf_d.line3);
    reactor_mode_t* NEW_DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_NEW_DRIVING_change_type = reset_transition;
    #line 201 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    static char buf[17];
    snprintf(buf, 17, "targetZ:%i", -self->num_rotations * 360);
    lf_set(d.line3, buf);
    if (gyro.z->value - self->previousAngle <= -self->num_rotations * 348) {
      lf_set(m.left_power, 0.0f);
      self->previousAngle = gyro.z->value;
      self->previousDistance = angleToDistanceR.distance->value;
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
    self->_lf_gyro.z_reactions[0] = &self->_lf__reaction_4;
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
    self->_lf_angleToDistanceR.distance_reactions[0] = &self->_lf__reaction_3;
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
    #line 104 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.number = 0;
    #line 104 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.function = _choreo_mainreaction_function_0;
    #line 104 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.self = self;
    #line 104 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 104 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 104 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.name = "?";
    #line 104 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 126 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.number = 1;
    #line 126 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.function = _choreo_mainreaction_function_1;
    #line 126 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.self = self;
    #line 126 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 126 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 126 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.name = "?";
    #line 126 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 166 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.number = 2;
    #line 166 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.function = _choreo_mainreaction_function_2;
    #line 166 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.self = self;
    #line 166 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 166 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 166 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.name = "?";
    #line 166 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    #line 180 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.number = 3;
    #line 180 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.function = _choreo_mainreaction_function_3;
    #line 180 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.self = self;
    #line 180 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 180 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 180 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.name = "?";
    #line 180 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[1];
    #line 200 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.number = 4;
    #line 200 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.function = _choreo_mainreaction_function_4;
    #line 200 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.self = self;
    #line 200 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 200 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 200 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.name = "?";
    #line 200 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[2];
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.last = NULL;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t_reactions[1] = &self->_lf__reaction_2;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.number_of_reactions = 2;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 58 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    #line 165 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 165 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].name = "CALIBRATION";
    #line 165 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 165 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].flags = 0;
    #line 179 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 179 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].name = "NEW_DRIVING";
    #line 179 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 179 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].flags = 0;
    #line 199 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    #line 199 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].name = "NEW_ROTATING";
    #line 199 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].deactivation_time = 0;
    #line 199 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
