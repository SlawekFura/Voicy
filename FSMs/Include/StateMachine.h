#pragma once
#include <StringToEnumConverter.h>

class IState;

class StateMachine
{
private:
	IState* m_currentState;
public:
	StateMachine();
	void handleInput(std::string);
	void changeState(IState*);
	std::string getState();
};

