#ifndef BABYSTATE_H
#define BABYSTATE_H

#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include <iostream>
#include "TeenState.h"
namespace bsc = boost::statechart;

class StateMachine;

//Event to Move from Baby State to TeenState
class EventMoveToTeenState : public bsc::event<EventMoveToTeenState> {};

// Starting state needs to know which state machine it belongs to
class BabyState : public bsc::simple_state<BabyState, StateMachine> {
    public:
    BabyState() { std::cout << "Entering Baby State" << std::endl; }
    ~BabyState() { std::cout << "Destroying Baby State" << std::endl; }

    //Automated Event Handler to handle the EventMoveToTeenState and transit statemachine to TeenState
    typedef bsc::transition<EventMoveToTeenState, TeenState> reactions;
};

#endif //BABYSTATE_H