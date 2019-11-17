#ifndef ADULTSTATE_H
#define ADULTSTATE_H

#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include "ElderState.h"
#include "DeadState.h"
#include "Event.h"
#include <iostream>

namespace bsc = boost::statechart;
namespace bmpl = boost::mpl;

class StateMachine;

//State needs to know which state machine it belongs to
class AdultState : public bsc::simple_state<AdultState, StateMachine> {
    public:
    AdultState() { std::cout << "Entering Adult State" << std::endl; }
    ~AdultState() { std::cout << "Destroying Adult State" << std::endl; }

    //Multiple Event Handlers to handle events and transit to respective state
    typedef bmpl::list< 
        bsc::transition<EventMoveToElderState, ElderState>,
	    bsc::custom_reaction<EventMoveToDeadState>
	> reactions;

	bsc::result react(const EventMoveToDeadState& /*event*/) {
		return transit<DeadState>();
    }
};

#endif //ADULTSTATE_H