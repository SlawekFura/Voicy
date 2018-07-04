#include "StateMachine.h"
#include "IState.h"
#include "BaseState.h"
#include <iostream>

extern StateMachine s_stateMachine;

StateMachine::StateMachine()
{
	m_currentState = new BaseState();
	std::cout<<"StateMachine created!\n"<<std::endl;
}

void StateMachine::handleInput(std::string p_input)
{
	m_currentState->handleInput(p_input);
}

void StateMachine::changeState(IState * p_newState)
{
	delete m_currentState;
	m_currentState = p_newState;
}

std::string StateMachine::getState()
{ 
	return m_currentState->getState();
}
