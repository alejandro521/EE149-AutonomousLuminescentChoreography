// Code generated by the Lingua Franca compiler from:
// file://home/foobar/EE149-AutonomousLuminescentChoreography/src/Blink.lf
#define LOG_LEVEL 2
#define TARGET_FILES_DIRECTORY "/home/foobar/EE149-AutonomousLuminescentChoreography/src-gen/Blink"

#include <limits.h>
#include "include/core/platform.h"
#include "include/api/api.h"
#include "include/core/reactor.h"
#include "include/core/reactor_common.h"
#include "include/core/mixed_radix.h"
#include "include/core/port.h"
#include "include/core/environment.h"
int lf_reactor_c_main(int argc, const char* argv[]);
int main(void) {
   return lf_reactor_c_main(0, NULL);
}
void _lf_set_default_command_line_options() {}
#include "_blink_main.h"
typedef enum {
    blink_main,
    _num_enclaves
} _enclave_id;
// The global array of environments associated with each enclave
environment_t envs[_num_enclaves];
// 'Create' and initialize the environments in the program
void _lf_create_environments() {
    environment_init(&envs[blink_main],blink_main,_lf_number_of_workers,1,1,0,0,0,0,0,NULL);
}
// Update the pointer argument to point to the beginning of the environment array
// and return the size of that array
int _lf_get_environments(environment_t ** return_envs) {
   (*return_envs) = (environment_t *) envs;
   return _num_enclaves;
}
// No watchdogs found.
typedef void watchdog_t;
watchdog_t* _lf_watchdogs = NULL;
int _lf_watchdog_count = 0;
void _lf_initialize_trigger_objects() {
    int startup_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(startup_reaction_count);
    int shutdown_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(shutdown_reaction_count);
    int reset_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(reset_reaction_count);
    int timer_triggers_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(timer_triggers_count);
    int modal_state_reset_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(modal_state_reset_count);
    int modal_reactor_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(modal_reactor_count);
    int bank_index;
    SUPPRESS_UNUSED_WARNING(bank_index);
    int watchdog_number = 0;
    SUPPRESS_UNUSED_WARNING(watchdog_number);
    _blink_main_main_self_t* blink_main_self[1];
    SUPPRESS_UNUSED_WARNING(blink_main_self);
    // ***** Start initializing Blink of class Blink
    blink_main_self[0] = new__blink_main();
    blink_main_self[0]->base.environment = &envs[blink_main];
    bank_index = 0; SUPPRESS_UNUSED_WARNING(bank_index);
    envs[blink_main].startup_reactions[startup_reaction_count[blink_main]++] = &blink_main_self[0]->_lf__reaction_0;
    SUPPRESS_UNUSED_WARNING(_lf_watchdog_count);
    { // For scoping
        static bool _initial = false;
        blink_main_self[0]->led_on = _initial;
    } // End scoping.
    // Initiaizing timer Blink.t.
    blink_main_self[0]->_lf__t.offset = 0;
    blink_main_self[0]->_lf__t.period = MSEC(250);
    // Associate timer with the environment of its parent
    envs[blink_main].timer_triggers[timer_triggers_count[blink_main]++] = &blink_main_self[0]->_lf__t;
    blink_main_self[0]->_lf__t.mode = NULL;
    
    blink_main_self[0]->_lf__reaction_0.deadline = NEVER;
    blink_main_self[0]->_lf__reaction_1.deadline = NEVER;
    //***** End initializing Blink
    // **** Start deferred initialize for Blink
    {
    
        // Total number of outputs (single ports and multiport channels)
        // produced by reaction_0 of Blink.
        blink_main_self[0]->_lf__reaction_0.num_outputs = 0;
        {
            int count = 0; SUPPRESS_UNUSED_WARNING(count);
        }
        
        // ** End initialization for reaction 0 of Blink
        // Total number of outputs (single ports and multiport channels)
        // produced by reaction_1 of Blink.
        blink_main_self[0]->_lf__reaction_1.num_outputs = 0;
        {
            int count = 0; SUPPRESS_UNUSED_WARNING(count);
        }
        
        // ** End initialization for reaction 1 of Blink
    
    }
    // **** End of deferred initialize for Blink
    // **** Start non-nested deferred initialize for Blink
    
    
    
    // **** End of non-nested deferred initialize for Blink
    // Connect inputs and outputs for reactor Blink.

    
    // Set reaction priorities for ReactorInstance Blink
    {
        blink_main_self[0]->_lf__reaction_0.chain_id = 1;
        // index is the OR of level 0 and 
        // deadline 9223372036854775807 shifted left 16 bits.
        blink_main_self[0]->_lf__reaction_0.index = 0xffffffffffff0000LL;
        blink_main_self[0]->_lf__reaction_1.chain_id = 1;
        // index is the OR of level 1 and 
        // deadline 9223372036854775807 shifted left 16 bits.
        blink_main_self[0]->_lf__reaction_1.index = 0xffffffffffff0001LL;
    }
    

    #ifdef EXECUTABLE_PREAMBLE
    _lf_executable_preamble(&envs[0]);
    #endif
    #ifdef FEDERATED
    initialize_triggers_for_federate();
    #endif // FEDERATED
}
void logical_tag_complete(tag_t tag_to_send) {
#ifdef FEDERATED_CENTRALIZED
        _lf_logical_tag_complete(tag_to_send);
#endif // FEDERATED_CENTRALIZED

}
#ifndef FEDERATED
void terminate_execution(environment_t* env) {}
#endif
