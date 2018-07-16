#pragma once
#include "IState.h"
#include <memory>
#include "IResource.h"
#include <iostream>
#include "StateMachine.h"
#include "ActionState.h"
#include "ShoppingState.h"


extern StateMachine* s_stateMachine;

template <typename T>
class EraseState : public IState
{
    std::shared_ptr<T> m_resource;
public:
	EraseState(const std::shared_ptr<T>&);
	void handleInput(std::string) override;
	std::string getState() override { return "EraseState"; };
    ~EraseState();
};

template <typename T>
EraseState<T>::EraseState(const std::shared_ptr<T>& p_resource) : m_resource(p_resource)
{ 
    std::cout << __FUNCTION__ << " use_count = " << m_resource.use_count() << std::endl;
    std::cout << "EraseState" << std::endl;
}

template <typename T>
void EraseState<T>::handleInput(std::string p_command)
{
    std::cout << __FUNCTION__ << " use_count = " << m_resource.use_count() << std::endl;
    if (p_command == "WROC")
    {
        s_stateMachine->changeState(new ShoppingState(m_resource));
    }
    else if (m_resource->isCommandProcessible(p_command))
    {
        m_resource->erase(p_command);
    }
    else
    {
        std::cout << "EraseState.cpp default handleInput" << std::endl;
    }
}

template <typename T>
EraseState<T>::~EraseState()
{}

