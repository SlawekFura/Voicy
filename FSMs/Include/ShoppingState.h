#pragma once
#include "IState.h"
#include <iostream>
#include <fstream>
#include <set>
#include <memory>
#include "ShoppingList.h"

#define FILEPATH "../../Voicy/Resources/ShoppingList.txt"
class ShoppingState : public IState
{
	void fillShoppingSet();
	void writeShoppingSetIntoFile();
	void reopenCleanFileInOut();

	std::shared_ptr<ShoppingList> m_shoppingListPtr;
	~ShoppingState();
	Operation m_operation;
	std::fstream m_shoppingList;
	std::function<void()> m_doubtedActivity;

public:
	ShoppingState(const std::shared_ptr<ShoppingList>&);
	ShoppingState();
	void handleInput(std::string) override;
	std::string getState() override { return "ShoppingState"; };

};

