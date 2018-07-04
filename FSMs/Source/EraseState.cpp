#include "EraseState.h"
#include <iostream>
#include "ShoppingState.h"
#include "StateMachine.h"
#include "ActionState.h"


extern StateMachine* s_stateMachine;

EraseState::EraseState()
{ 
	std::cout << "EraseState" << std::endl;
}

void EraseState::handleInput(std::string p_command)
{
	if (p_command == "WROC")
	{
		s_stateMachine->changeState(new ActionState);
	}
	if (p_command == "ZAKUPY")
	{
		ShoppingState::Operation l_operation = [](std::set<std::string>& p_shoppingList, std::string p_command)
		{
			p_shoppingList.erase(p_command);
		};
		s_stateMachine->changeState(new ShoppingState(std::move(l_operation)));
	}
	else
	{
		std::cout << "EraseState.cpp default handleInput" << std::endl;
	}
}

