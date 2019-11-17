#ifndef EVENT_H
#define EVENT_H

#include "boost/statechart/event.hpp"

namespace bsc = boost::statechart;

//Event to Move to TeenState
class EventMoveToTeenState : public bsc::event<EventMoveToTeenState> {};

//Event to Move to Adult State
class EventMoveToAdultState : public bsc::event<EventMoveToAdultState> {};

//Event to Move to Elder State
class EventMoveToElderState : public bsc::event<EventMoveToElderState> {};

//Event to Move to Dead State
class EventMoveToDeadState : public bsc::event<EventMoveToDeadState> {};

//Event to Move to Baby State
class EventMoveToBabyState : public bsc::event<EventMoveToBabyState> {};

#endif //EVENT_H