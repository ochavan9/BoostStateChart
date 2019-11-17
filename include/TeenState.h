#ifndef TEENSTATE_H
#define TEENSTATE_H

#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "BabyState.h"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

//Event to Move from Teen State to Baby State
class EventMoveToBabyState : public bsc::event<EventMoveToBabyState> {};

//State needs to know which state machine it belongs to
class TeenState : public bsc::simple_state<TeenState, StateMachine> {
    public:
    TeenState() { std::cout << "Entering TeenState" << std::endl; }
    ~TeenState() { std::cout << "Destroying Teen State" << std::endl; }
    
    //Automated Event Handler to handle the EventMoveToBabyState and transit statemachine to Baby State
    typedef bsc::transition<EventMoveToBabyState, BabyState> reactions;
};

#endif //TEENSTATE_H