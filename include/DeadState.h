#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "BabyState.h"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

//Event to Move from Dead State to Baby State
class EventMoveToBabyState : public bsc::event<EventMoveToBabyState> {};

//State needs to know which state machine it belongs to
class DeadState : public bsc::simple_state<DeadState, StateMachine> {
    public:
    DeadState() { std::cout << "Entering Dead State" << std::endl; }
    ~DeadState() { std::cout << "Destroying Dead State" << std::endl; }
    
    //Automated Event Handler to handle the EventMoveToBabyState and transit statemachine to Baby State
    typedef bsc::transition<EventMoveToBabyState, BabyState> reactions;
};

#endif //DEADSTATE_H