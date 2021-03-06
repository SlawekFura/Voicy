#include "ActionState.h"
#include "BaseState.h"
#include "StateMachine.h"
//#include "SaveState.h"
//#include "EraseState.h"
#include "ShoppingState.h"
#include <iostream>

extern StateMachine* s_stateMachine;

ActionState::ActionState()
{
	std::cout << "ActionState\n" << std::endl;
}

void ActionState::handleInput(std::string p_command)
{
    if (p_command == "ZAKUPY")
    {
        s_stateMachine->changeState(new ShoppingState());
    }
	//if (p_command == "ZAPISZ")
	//{
	//	s_stateMachine->changeState(new SaveState);
	//}
	else if (p_command == "POWIEDZ")
	{
	}
	//else if (p_command == "USUN")
	//{
	//	s_stateMachine->changeState(new EraseState);
	//}
	else if (p_command == "RESET")
	{
		s_stateMachine->changeState(new BaseState);
	}
	else
	{
		std::cout << "ActionState default input handler" << std::endl;
	}
}
