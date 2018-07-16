#pragma once
#include "IState.h"
#include <iostream>
#include "ShoppingState.h"
#include "StateMachine.h"
#include "ActionState.h"

extern StateMachine* s_stateMachine;

template <typename T>
class SaveState : public IState
{
    std::shared_ptr<T> m_resource;
public:
	SaveState(const std::shared_ptr<T>&);
    ~SaveState();
	void handleInput(std::string) override;
	std::string getState() override { return "SaveState"; };
};

template <typename T>
SaveState<T>::SaveState(const std::shared_ptr<T>& p_resource) : m_resource(p_resource)
{ 
    std::cout << __FUNCTION__ << " use_count = " << m_resource.use_count() << std::endl;
    std::cout << "SaveState" << std::endl;
}


template <typename T>
void SaveState<T>::handleInput(std::string p_command)
{
    std::cout << __FUNCTION__ << " use_count = " << m_resource.use_count() << std::endl;
    if (p_command == "WROC")
    {
        s_stateMachine->changeState(new ShoppingState(m_resource));
    }
    else if (m_resource->isCommandProcessible(p_command))
    {
        m_resource->add(p_command);
    }
    else
    {
        std::cout << "SaveState.cpp default handleInput" << std::endl;
    }
}

template <typename T>
SaveState<T>::~SaveState()
{}

