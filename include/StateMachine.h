#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "boost/statechart/state_machine.hpp"
#include <iostream>

namespace bsc = boost::statechart;

//First State
class BabyState;

// State Machine need to know starting state
class StateMachine : public bsc::state_machine<StateMachine, BabyState> {
    public:
    StateMachine(){ std::cout << "Starting State Machine" << std::endl; }
    ~StateMachine() { std::cout << "Destroying State Machine" << std::endl; }
};

#endif //STATEMACHINE_H