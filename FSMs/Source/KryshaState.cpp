#include "KryshaState.h"
#include "ActionState.h"
#include "StateMachine.h"
#include "BaseState.h"
#include <iostream>

extern StateMachine* s_stateMachine;

KryshaState::KryshaState()
{
	std::cout << "KryshaState" << std::endl;
};

void KryshaState::handleInput(std::string p_command)
{
	if (p_command == "WYKONAJ")
	{
		s_stateMachine->changeState(new ActionState);
	}
	else if (p_command == "NIC")
	{
		s_stateMachine->changeState(new BaseState);
	}
	else
	{
		std::cout << "KryshaState default input handler" << std::endl;
	}
}
