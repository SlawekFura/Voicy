#pragma once
#include "IState.h"
class SaveState : public IState
{
public:
	SaveState();
	void handleInput(std::string) override;
	std::string getState() override { return "SaveState"; };
};

