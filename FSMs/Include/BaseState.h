#pragma once
#include "IState.h"

class BaseState : public IState
{
public:
	BaseState();
	void handleInput(std::string) override;
	std::string getState() override { return "BaseState"; };

};

