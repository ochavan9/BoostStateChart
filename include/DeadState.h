#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "BabyState.h"
#include "Event.h"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

//State needs to know which state machine it belongs to
class DeadState : public bsc::simple_state<DeadState, StateMachine> {
    public:
    DeadState() { std::cout << "Entering Dead State" << std::endl; }
    ~DeadState() { std::cout << "Destroying Dead State" << std::endl; }
    
    //Automated Event Handler to handle the EventMoveToBabyState and transit statemachine to Baby State
    typedef bsc::transition<EventMoveToBabyState, BabyState> reactions;
};

#endif //DEADSTATE_H