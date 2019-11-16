#include "boost/statechart/event.hpp"
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"
#include <iostream>

namespace bsc = boost::statechart;

class StateMachine;

// Starting state needs to know which state machine it belongs to
class BabyState : public bsc::simple_state<BabyState, StateMachine> {
    public:
    BabyState() { std::cout << "NULL State ==> Baby State" << std::endl; }
    ~BabyState() { std::cout << "Baby State ==> NULL State" << std::endl; }
};