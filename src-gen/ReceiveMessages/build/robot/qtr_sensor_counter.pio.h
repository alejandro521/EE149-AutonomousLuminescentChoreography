// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ------------------ //
// qtr_sensor_counter //
// ------------------ //

#define qtr_sensor_counter_wrap_target 12
#define qtr_sensor_counter_wrap 12

static const uint16_t qtr_sensor_counter_program_instructions[] = {
    0x6087, //  0: out    pindirs, 7                 
    0x4007, //  1: in     pins, 7                    
    0xa0e2, //  2: mov    osr, y                     
    0xa046, //  3: mov    y, isr                     
    0x00a7, //  4: jmp    x != y, 7                  
    0xa0c3, //  5: mov    isr, null                  
    0x0009, //  6: jmp    9                          
    0xa022, //  7: mov    x, y                       
    0x40f0, //  8: in     osr, 16                    
    0xa047, //  9: mov    y, osr                     
    0x0081, // 10: jmp    y--, 1                     
    0x4040, // 11: in     y, 32                      
            //     .wrap_target
    0xa042, // 12: nop                               
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program qtr_sensor_counter_program = {
    .instructions = qtr_sensor_counter_program_instructions,
    .length = 13,
    .origin = -1,
};

static inline pio_sm_config qtr_sensor_counter_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + qtr_sensor_counter_wrap_target, offset + qtr_sensor_counter_wrap);
    return c;
}
#endif

