#ifndef BABYSTATE_H
#define BABYSTATE_H

#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "TeenState.h"
#include "Event.h"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

// Starting state needs to know which state machine it belongs to
class BabyState : public bsc::simple_state<BabyState, StateMachine> {
    public:
    BabyState() { std::cout << "Entering Baby State" << std::endl; }
    ~BabyState() { std::cout << "Destroying Baby State" << std::endl; }

    //Automated Event Handler to handle the EventMoveToTeenState and transit statemachine to TeenState
    typedef bsc::transition<EventMoveToTeenState, TeenState> reactions;
};

#endif //BABYSTATE_H