#ifndef ELDERSTATE_H
#define ELDERSTATE_H

#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "BabyState.h"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

//Event to Move from Elder State to Baby State
class EventMoveToBabyState : public bsc::event<EventMoveToBabyState> {};

//State needs to know which state machine it belongs to
class ElderState : public bsc::simple_state<ElderState, StateMachine> {
    public:
    ElderState() { std::cout << "Entering Elder State" << std::endl; }
    ~ElderState() { std::cout << "Destroying Elder State" << std::endl; }
    
    //Automated Event Handler to handle the EventMoveToBabyState and transit statemachine to Baby State
    typedef bsc::transition<EventMoveToBabyState, BabyState> reactions;
};

#endif //ELDERSTATE_H