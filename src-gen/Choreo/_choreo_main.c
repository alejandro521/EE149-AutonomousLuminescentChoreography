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
#line 68 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method setCommand()
void _choreo_main_method_setCommand(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 69 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    char *token = strtok(self->received_message, ",");
    self->next_mode = token;
    token = strtok(NULL, ",");
    self->speed = atof(token);
    token = strtok(NULL, ",");
    self->degrees = atoi(token);
    token = strtok(NULL, ",");
    self->target_distance = atof(token);
    token = strtok(NULL, ",");
    self->leds_on = atoi(token);
    token = strtok(NULL, ",");
    self->leds_blink = atoi(token);
    token = strtok(NULL, ",");
    
    // if (strcmp(self->next_mode, "CALIBRATION")) {
    //   lf_set_mode(CALIBRATION);
    // } else if (strcmp(self->next_mode, "DRIVE")) {
    //   lf_set_mode(NEW_DRIVING);
    // } else if (strcmp(self->next_mode, "ROTATE")) {
    //   lf_set_mode(NEW_ROTATING);
    // }
    // } else if (strcmp(self->next_mode, "STOP")) {
    //   lf_set_mode(STOP);
    // } else if (strcmp(self->next_mode, "FINALE")) {
    //   lf_set_mode(THIS_IS_WHAT_YOU_CAME_FOR);
    // }
}
#line 98 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method receiveMessage()
void _choreo_main_method_receiveMessage(void* instance_args, char* received_message) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 99 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
}
#line 115 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
// Implementation of method transmitMessage()
void _choreo_main_method_transmitMessage(void* instance_args, char* message, char* transmitted_message) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 116 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    struct d {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } d;
    d.line0 = &(self->_lf_d.line0);
    d.line1 = &(self->_lf_d.line1);
    d.line2 = &(self->_lf_d.line2);
    #line 129 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
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
    
    // lf_set(d.line0, "CALIBRATING");
    // lf_set(d.line1, "Roll robot over");
    // lf_set(d.line2, "light and dark.");
    
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
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    struct d {
        _display_line2_t* line2;
    
    } d;
    e.trigger = &(self->_lf_e.trigger);
    gyro.trigger = &(self->_lf_gyro.trigger);
    line.trigger = &(self->_lf_line.trigger);
    d.line2 = &(self->_lf_d.line2);
    #line 160 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    lf_set(e.trigger, true);
    lf_set(gyro.trigger, true);
    lf_set(line.trigger, true);
    
    if (uart_is_readable(uart0)) {
    receiveMessage(self->received_message);
    }
    
    static char buf_received[17];
    printf("R: %s\n", self->received_message);
    snprintf(buf_received, 17, "R:%s", self->received_message);
    printf("B: %s\n", buf_received);
    lf_set(d.line2, buf_received);
    
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
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct d {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    _display_line3_t* line3;
    
    } d;
    line.reflect = self->_lf_line.reflect;
    d.line0 = &(self->_lf_d.line0);
    d.line1 = &(self->_lf_d.line1);
    d.line2 = &(self->_lf_d.line2);
    d.line3 = &(self->_lf_d.line3);
    #line 192 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->leftLine = line.reflect->value[0];
    self->centerLine = (line.reflect->value[1] + line.reflect->value[2] + line.reflect->value[3]) / 3;
    self->leftLine = line.reflect->value[4];
    static char buf0[17];
    snprintf(buf0, 17, "1:%d", line.reflect->value[0]);
    static char buf1[17];
    snprintf(buf1, 17, "2: %d, 3:%d, 4:%d", line.reflect->value[1], line.reflect->value[2], line.reflect->value[3]);
    static char buf2[17];
    snprintf(buf2, 17, "5:%d", line.reflect->value[4]);
    lf_set(d.line0, buf0);
    lf_set(d.line1, buf1);
    lf_set(d.line2, buf2);
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
    reactor_mode_t* STOP = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_STOP_change_type = reset_transition;
    #line 212 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    if (gyro.z->value - self->previousAngle <= -3560) {
      lf_set(m.left_power, 0.0f);
      self->previousAngle = gyro.z->value;
      self->previousDistance = angleToDistanceR.distance->value;
      lf_set_mode(STOP);
    } else {
      lf_set(d.line0, "CALIBRATE");
      lf_set(m.left_power, 0.5f);
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
    _display_line2_t* line2;
    _display_line3_t* line3;
    
    } d;
    angleToDistanceR.distance = self->_lf_angleToDistanceR.distance;
    gyro.z = self->_lf_gyro.z;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    d.line1 = &(self->_lf_d.line1);
    d.line2 = &(self->_lf_d.line2);
    d.line3 = &(self->_lf_d.line3);
    reactor_mode_t* NEW_ROTATING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_NEW_ROTATING_change_type = reset_transition;
    reactor_mode_t* STOP = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_STOP_change_type = reset_transition;
    #line 227 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    lf_set(d.line0, "DRIVE");
    if (strcmp(self->next_mode, "Stop")) {
      self->next_mode = "";
      lf_set_mode(STOP);
    } else if (strcmp(self->next_mode, "Rotate")) {
      self->next_mode = "";
      lf_set_mode(NEW_ROTATING);
    }
    static char buf[17];
    snprintf(buf, 17, "targetDist:%f", self->target_distance);
    // lf_set(d.line1, buf);
    if (angleToDistanceR.distance->value - self->previousDistance >= self->target_distance) {
      self->previousDistance = angleToDistanceR.distance->value;
      self->previousAngle = gyro.z->value; 
      self->next_mode = "";
      lf_set_mode(STOP);
    } else {
      lf_set(m.left_power, self->speed);
      lf_set(m.right_power, self->speed);
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
    reactor_mode_t* STOP = &self->_lf__modes[3];
    lf_mode_change_type_t _lf_STOP_change_type = reset_transition;
    #line 252 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
     lf_set(d.line0, "ROTATE");
     if (strcmp(self->next_mode, "Stop")) {
       self->next_mode = "";
       lf_set_mode(STOP);
     } else if (strcmp(self->next_mode, "Drive")) {
       self->next_mode = "";
       lf_set_mode(NEW_DRIVING);
     }
     static char buf[17];
     snprintf(buf, 17, "targetZ:%i", self->degrees);
    // lf_set(d.line3, buf);
     if (abs(gyro.z->value - self->previousAngle) >= self->degrees) {
       self->previousAngle = gyro.z->value;
       self->previousDistance = angleToDistanceR.distance->value;
       self->next_mode = "";
       lf_set_mode(STOP);
     } else {
      // lf_set(d.line0, "ROTATE");
       if (self->degrees < 0) { //Rotate left  
         lf_set(m.right_power, self->speed);
       } else { //Rotate right
         lf_set(m.left_power, self->speed);
       }
       //  lf_set(d.line0, "ROTATE");
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
void _choreo_mainreaction_function_6(void* instance_args) {
    _choreo_main_main_self_t* self = (_choreo_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct m {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } m;
    struct d {
        _display_line0_t* line0;
    
    } d;
    m.left_power = &(self->_lf_m.left_power);
    m.right_power = &(self->_lf_m.right_power);
    d.line0 = &(self->_lf_d.line0);
    reactor_mode_t* NEW_DRIVING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_NEW_DRIVING_change_type = reset_transition;
    reactor_mode_t* NEW_ROTATING = &self->_lf__modes[2];
    lf_mode_change_type_t _lf_NEW_ROTATING_change_type = reset_transition;
    #line 283 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    lf_set(m.left_power, 0.0f);
    lf_set(m.right_power, 0.0f);
    lf_set(d.line0, "STOP");
    if (strcmp(self->next_mode, "Drive")) {
      self->next_mode = "";
      lf_set_mode(NEW_DRIVING);
    } else if (strcmp(self->next_mode, "Rotate")){
      self->next_mode = "";
      lf_set_mode(NEW_ROTATING);
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
    self->_lf_d_width = -2;
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
    self->_lf_gyro.z_reactions[0] = &self->_lf__reaction_5;
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
    self->_lf_line_width = -2;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_reactions[0] = &self->_lf__reaction_2;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.reactions = self->_lf_line.reflect_reactions;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.last = NULL;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.number_of_reactions = 1;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    #ifdef FEDERATED
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.physical_time_of_arrival = NEVER;
    #line 40 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/lib/Line.lf"
    #endif // FEDERATED
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
    self->_lf_angleToDistanceR.distance_reactions[0] = &self->_lf__reaction_4;
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
    #line 128 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.number = 0;
    #line 128 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.function = _choreo_mainreaction_function_0;
    #line 128 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.self = self;
    #line 128 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 128 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 128 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.name = "?";
    #line 128 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 159 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.number = 1;
    #line 159 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.function = _choreo_mainreaction_function_1;
    #line 159 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.self = self;
    #line 159 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 159 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 159 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.name = "?";
    #line 159 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 191 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.number = 2;
    #line 191 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.function = _choreo_mainreaction_function_2;
    #line 191 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.self = self;
    #line 191 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 191 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 191 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.name = "?";
    #line 191 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.number = 3;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.function = _choreo_mainreaction_function_3;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.self = self;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.name = "?";
    #line 211 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[0];
    #line 226 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.number = 4;
    #line 226 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.function = _choreo_mainreaction_function_4;
    #line 226 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.self = self;
    #line 226 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 226 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 226 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.name = "?";
    #line 226 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[1];
    #line 251 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.number = 5;
    #line 251 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.function = _choreo_mainreaction_function_5;
    #line 251 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.self = self;
    #line 251 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 251 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 251 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.name = "?";
    #line 251 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_5.mode = &self->_lf__modes[2];
    #line 282 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_6.number = 6;
    #line 282 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_6.function = _choreo_mainreaction_function_6;
    #line 282 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_6.self = self;
    #line 282 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 282 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 282 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_6.name = "?";
    #line 282 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__reaction_6.mode = &self->_lf__modes[3];
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.last = NULL;
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t_reactions[1] = &self->_lf__reaction_3;
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.number_of_reactions = 2;
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 65 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t1.last = NULL;
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t1_reactions[0] = &self->_lf__reaction_6;
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t1.reactions = &self->_lf__t1_reactions[0];
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t1.number_of_reactions = 1;
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #ifdef FEDERATED
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__t1.physical_time_of_arrival = NEVER;
    #line 281 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    #endif // FEDERATED
    self->_lf__t1.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
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
    #line 210 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 210 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].name = "CALIBRATION";
    #line 210 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 210 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[0].flags = 0;
    #line 225 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 225 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].name = "NEW_DRIVING";
    #line 225 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 225 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[1].flags = 0;
    #line 250 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].state = &_lf_self_base->_lf__mode_state;
    #line 250 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].name = "NEW_ROTATING";
    #line 250 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].deactivation_time = 0;
    #line 250 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[2].flags = 0;
    #line 280 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[3].state = &_lf_self_base->_lf__mode_state;
    #line 280 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[3].name = "STOP";
    #line 280 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[3].deactivation_time = 0;
    #line 280 "/home/foobar/EE149-AutonomousLuminescentChoreography/src/Choreo.lf"
    self->_lf__modes[3].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
