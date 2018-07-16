#include "ShoppingState.h"
#include "StateMachine.h"
#include "SaveState.h"
#include "BaseState.h"
#include "EraseState.h"
#include <stdio.h>
#include "ShoppingList.h"
#include "Festival.h"

extern StateMachine* s_stateMachine;

static void clearShoppingFileIndicators(std::fstream& m_file)
{
	m_file.clear();
	m_file.seekg(0, std::ios_base::beg);
}

ShoppingState::ShoppingState(const std::shared_ptr<ShoppingList>& p_shoppingListPtr) : m_shoppingListPtr(p_shoppingListPtr), m_doubtedActivity([](){}) 
{
    m_shoppingList.open(FILEPATH);
	if (!m_shoppingList.is_open())
	{
		std::cout << "Could not open "<< FILEPATH << std::endl;
		s_stateMachine->changeState(new BaseState);
		return;
	}
	std::cout << "Successfully opened ShoppingList.txt" << std::endl;
}

ShoppingState::ShoppingState() : m_shoppingListPtr(std::make_shared<ShoppingList>())
{
    m_shoppingList.open(FILEPATH);
	if (!m_shoppingList.is_open())
	{
		std::cout << "Could not open "<< FILEPATH << std::endl;
		s_stateMachine->changeState(new BaseState);
		return;
	}
	std::cout << "Successfully opened ShoppingList.txt" << std::endl;
	fillShoppingSet();

}


void ShoppingState::handleInput(std::string p_command)
{
	if (p_command == "WROC")
	{
		s_stateMachine->changeState(new ActionState());
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
        m_shoppingListPtr->show();
		clearShoppingFileIndicators(m_shoppingList);
	}
	else if (p_command == "WYCZYSC")
	{
        Festival::instance()->sayText("Napewno?");
        m_doubtedActivity = [this]()
        {
            reopenCleanFileInOut();
		    m_shoppingListPtr->clear();
        };
	}
	else if (p_command == "NIC")
	{
		s_stateMachine->changeState(new BaseState);
	}
    else if (p_command == "USUN")
	{
        std::cout << __FUNCTION__ << " use_count = " << m_shoppingListPtr.use_count() << std::endl;
		s_stateMachine->changeState(new EraseState<ShoppingList>(m_shoppingListPtr));
	}
    else if (p_command == "ZAPISZ")
	{
        std::cout << __FUNCTION__ << " use_count = " << m_shoppingListPtr.use_count() << std::endl;
		s_stateMachine->changeState(new SaveState<ShoppingList>(m_shoppingListPtr));
	}
    else if (p_command == "TAK")
    {   
        std::cout << __FUNCTION__ << " przed zawolaniem " << std::endl;
        m_doubtedActivity();
        std::cout << __FUNCTION__ << " po zawolaniu " << std::endl;
        m_doubtedActivity = [](){};
    }
    else if (p_command == "NIE")
    {
        m_doubtedActivity = [](){};
    }
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

    //m_shoppingListPtr = std::make_shared<ShoppingList>();
	while (getline(m_shoppingList, l_line))
	{
		m_shoppingListPtr->add(l_line);
	}
	clearShoppingFileIndicators(m_shoppingList);
}

void ShoppingState::writeShoppingSetIntoFile()
{
	for (auto line : m_shoppingListPtr->getResource())
	{
		std::cout << "Line to write to file:" << line << std::endl;
		m_shoppingList << line << std::endl;
	}
}

void ShoppingState::reopenCleanFileInOut()
{
	m_shoppingList.close();
	m_shoppingList.open(FILEPATH,
		std::fstream::in | std::fstream::out | std::fstream::trunc);
}



