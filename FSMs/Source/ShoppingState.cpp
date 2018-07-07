#include "ShoppingState.h"
#include "StateMachine.h"
#include "SaveState.h"
#include "BaseState.h"
#include <stdio.h>

extern StateMachine* s_stateMachine;

static void clearShoppingFileIndicators(std::fstream& m_file)
{
	m_file.clear();
	m_file.seekg(0, std::ios_base::beg);
}

ShoppingState::ShoppingState(Operation p_operation)
	: m_operation(p_operation)
{
	std::cout << "ShoppingState" << std::endl;
	m_shoppingList.open("../Voicy/Resources/ShoppingList.txt");
	if (!m_shoppingList.is_open())
	{
		std::cout << "Could not open ../Voicy/Resources/ShoppingList.txt" << std::endl;
		s_stateMachine->changeState(new BaseState);
		return;
	}
	std::cout << "Successfully opened ShoppingList.txt" << std::endl;
	std::string l_line;
	fillShoppingSet();
}

void ShoppingState::handleInput(std::string p_command)
{
	if (p_command == "WROC")
	{
		s_stateMachine->changeState(new SaveState);
	}
	else if (p_command == "POKAZ")
	{
		std::string l_line;
		std::cout << "List of shopping items:" << std::endl;
		while (getline(m_shoppingList, l_line))
		{
			std::cout << "\t" <<l_line << std::endl;
		}
		
		std::cout << "List of set items:" << std::endl;
		for (auto line : m_shoppingSet)
		{
			std::cout << "\t" << line << std::endl;
		}
		clearShoppingFileIndicators(m_shoppingList);
	}
	//else if (p_command == "WYCZYSC")
	//{
	//	reopenCleanFileInOut();
	//	m_shoppingSet.clear();
	//}
	else if (p_command == "NITZ")
	{
		s_stateMachine->changeState(new BaseState);
	}
    else if (p_command == "USUN")
	{
		s_stateMachine->changeState(new BaseState);
	}
    else if (p_command == "ZAPISZ")
	{
		s_stateMachine->changeState(new BaseState);
	}
	//else if (isCommandInAvailableShoppingList(p_command))
	//{
	//	m_operation(m_shoppingSet, p_command);
	//}
	else
	{
		std::cout << "ShoppingState.cpp default handleInput" << std::endl;
	}
}

ShoppingState::~ShoppingState()
{
	std::cout << "~ShoppingState()" << std::endl;
	reopenCleanFileInOut();
	writeShoppingSetIntoFile();
	m_shoppingList.close();
}

void ShoppingState::fillShoppingSet()
{
	std::string l_line;
	while (getline(m_shoppingList, l_line))
	{
		m_shoppingSet.emplace(l_line);
	}
	clearShoppingFileIndicators(m_shoppingList);
}

void ShoppingState::writeShoppingSetIntoFile()
{
	for (auto line : m_shoppingSet)
	{
		std::cout << "Line to write to file:" << line << std::endl;
		m_shoppingList << line << std::endl;
	}
}

bool ShoppingState::isCommandInAvailableShoppingList(std::string p_command)
{
	std::cout << "is in s_availableShoppingList:" << int(s_availableShoppingList.find(p_command) != s_availableShoppingList.end()) << std::endl;
	return s_availableShoppingList.find(p_command) != s_availableShoppingList.end();
}

void ShoppingState::reopenCleanFileInOut()
{
	m_shoppingList.close();
	m_shoppingList.open(FILEPATH,
		std::fstream::in | std::fstream::out | std::fstream::trunc);
}



