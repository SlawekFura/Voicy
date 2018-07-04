#pragma once
#include "IState.h"

class KryshaState : public IState
{
public:
	KryshaState();
	void handleInput(std::string) override;
	std::string getState() override { return "KryshaState"; };
	~KryshaState() {};
};

