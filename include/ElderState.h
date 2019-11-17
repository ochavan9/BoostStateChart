#ifndef ELDERSTATE_H
#define ELDERSTATE_H

#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "DeadState.h"
#include "Event.h"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

//State needs to know which state machine it belongs to
class ElderState : public bsc::simple_state<ElderState, StateMachine> {
    public:
    ElderState() { std::cout << "Entering Elder State" << std::endl; }
    ~ElderState() { std::cout << "Destroying Elder State" << std::endl; }
    
    //Automated Event Handler to handle the EventMoveToDeadtate and transit statemachine to Dead State
    typedef bsc::transition<EventMoveToDeadState, DeadState> reactions;
};

#endif //ELDERSTATE_H