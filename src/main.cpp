#include "StateMachine.h"
#include "BabyState.h"
#include "TeenState.h"
#include "AdultState.h"
#include "ElderState.h"

int main() {
	StateMachine sm;
	sm.initiate();
	//Trigger an event
	sm.process_event(EventMoveToTeenState());
	sm.process_event(EventMoveToAdultState());
	sm.process_event(EventMoveToElderState());
	sm.process_event(EventMoveToBabyState());
	return 0;
}