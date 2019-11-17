#ifndef ADULTSTATE_H
#define ADULTSTATE_H

#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "ElderState.h"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

//Event to Move from Adult State to Elder State
class EventMoveToElderState : public bsc::event<EventMoveToElderState> {};

//State needs to know which state machine it belongs to
class AdultState : public bsc::simple_state<AdultState, StateMachine> {
    public:
    AdultState() { std::cout << "Entering Adult State" << std::endl; }
    ~AdultState() { std::cout << "Destroying Adult State" << std::endl; }
    
    //Automated Event Handler to handle the EventMoveToElderState and transit statemachine to Elder State
    typedef bsc::transition<EventMoveToElderState, ElderState> reactions;
};

#endif //ADULTSTATE_H