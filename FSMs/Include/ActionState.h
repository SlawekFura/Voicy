#pragma once
#include "IState.h"
class ActionState : public IState
{
public:
	ActionState();
	~ActionState() {};
	void handleInput(std::string) override;
	std::string getState() override {return "ActionState";};

};

