#ifndef TEENSTATE_H
#define TEENSTATE_H

#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "AdultState.h"
#include "Event.h"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

//State needs to know which state machine it belongs to
class TeenState : public bsc::simple_state<TeenState, StateMachine> {
    public:
    TeenState() { std::cout << "Entering TeenState" << std::endl; }
    ~TeenState() { std::cout << "Destroying Teen State" << std::endl; }
    
    //Automated Event Handler to handle the EventMoveToAdultState and transit statemachine to Adult State
    typedef bsc::transition<EventMoveToAdultState, AdultState> reactions;
};

#endif //TEENSTATE_H