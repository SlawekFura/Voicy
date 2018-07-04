#include "SaveState.h"
#include <iostream>
#include "ShoppingState.h"
#include "StateMachine.h"
#include "ActionState.h"


extern StateMachine* s_stateMachine;

SaveState::SaveState()
{ 
	std::cout << "SaveState" << std::endl;
}

void SaveState::handleInput(std::string p_command)
{
	if (p_command == "WROC")
	{
		s_stateMachine->changeState(new ActionState);
	}
	if (p_command == "ZAKUPY")
	{
		ShoppingState::Operation l_operation = [](std::set<std::string>& p_shoppingList, std::string p_command)
		{
			p_shoppingList.emplace(p_command);
		};
		s_stateMachine->changeState(new ShoppingState(std::move(l_operation)));
	}
	else
	{
		std::cout << "SaveState.cpp default handleInput" << std::endl;
	}
}

