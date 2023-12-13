#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1011276990_H
#define TOP_LEVEL_PREAMBLE_1011276990_H
#ifndef BLUETOOTH_FUNCTIONS_H
#define BLUETOOTH_FUNCTIONS_H
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/uart.h>
#include <hardware/structs/uart.h>

#define BAUD_RATE 9600
#define UART_TX_PIN 28
#define UART_RX_PIN 29
#define MAX_MSG_LENGTH 100

// Function to send a message. The message that was transmitted is written to transmitted_message
static void transmitMessage(uart_inst_t *uart, char *message, char *transmitted_message) {
  int index = 0;
  while (*message && index < MAX_MSG_LENGTH) {
    uart_putc(uart, *message);
    transmitted_message[index] = *message;
    index++;
    message++;
  }
  uart_putc(uart, '\r'); // Carriage return
  transmitted_message[index] = '\0';
}

// Function to write response from UART to incoming_message, returns true if there is a new message
static bool receiveMessage(uart_inst_t *uart, char *incoming_message) {
  int index = 0;
  char received_char = 'a'; //'a' is just to initialize received_char to a character that is not \r
  char end_char = '\r';
  bool received_new_message = false;
  if (uart_is_readable(uart)) {
    while (received_char != end_char) { 
      received_char = uart_getc(uart);
      if (index < MAX_MSG_LENGTH - 1 && received_char != end_char) {
        incoming_message[index] = received_char;
        index += 1;
      }
    }
    received_new_message = true;
  } 
  incoming_message[index] = '\0'; // Null terminate the string
  return received_new_message;
}

#endif // BLUETOOTH_FUNCTIONS_H
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _bluetooth_outgoing_message_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _bluetooth_incoming_message_t;
typedef struct {
    struct self_base_t base;
    
    #line 64 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    char* received_message;
    #line 65 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    char* transmitted_message;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    _bluetooth_outgoing_message_t* _lf_outgoing_message;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    // width of -2 indicates that it is not a multiport.
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    int _lf_outgoing_message_width;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    // Default input (in case it does not get connected)
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    _bluetooth_outgoing_message_t _lf_default__outgoing_message;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    _bluetooth_incoming_message_t _lf_incoming_message;
    #line 61 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    int _lf_incoming_message_width;
    #line 67 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    reaction_t _lf__reaction_0;
    #line 80 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    reaction_t _lf__reaction_1;
    #line 86 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    reaction_t _lf__reaction_2;
    #line 63 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    trigger_t _lf__t;
    #line 63 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    trigger_t _lf__outgoing_message;
    #line 60 "/home/foobar/149project/src/pololu_control/Bluetooth.lf"
    reaction_t* _lf__outgoing_message_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _bluetooth_self_t;
_bluetooth_self_t* new__bluetooth();
#endif // _BLUETOOTH_H
