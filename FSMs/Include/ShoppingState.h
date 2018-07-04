#pragma once
#include "IState.h"
#include <iostream>
#include <fstream>
#include <set>

#define FILEPATH "../Voicy/Resources/ShoppingList.txt"
class ShoppingState : public IState
{
public:
	ShoppingState(Operation p_operation);
	void handleInput(std::string) override;
	std::string getState() override { return "ShoppingState"; };

private:
	void fillShoppingSet();
	void writeShoppingSetIntoFile();
	bool isCommandInAvailableShoppingList(std::string);
	void reopenCleanFileInOut();

	std::set<std::string> m_shoppingSet;
	~ShoppingState();
	Operation m_operation;
	std::fstream m_shoppingList;

};

