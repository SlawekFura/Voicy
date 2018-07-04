#pragma once
#include "IState.h"
class EraseState : public IState
{
public:
	EraseState();
	void handleInput(std::string) override;
	std::string getState() override { return "EraseState"; };

};

