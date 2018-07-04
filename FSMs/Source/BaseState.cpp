#include <iostream>
#include "BaseState.h"
#include "StateMachine.h"
#include "ActionState.h"

extern StateMachine* s_stateMachine;

BaseState::BaseState() 
{
	std::cout << "BaseState" << std::endl;
};

void BaseState::handleInput(std::string p_command)
{
	if (p_command == "KRYSIA")
	{
		s_stateMachine->changeState(new ActionState);
	}
	else if (p_command == "NIC")
	{
		s_stateMachine->changeState(new BaseState);
	}
	else
	{
		std::cout << "BaseState.cpp default handleInput" << std::endl;
	}
}


