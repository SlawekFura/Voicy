#include <iostream>
#include "ShoppingList.h"
#include "StringToEnumConverter.h"

void ShoppingList::erase(std::string p_command)
{
    m_shoppingList.erase(p_command);
}

void ShoppingList::add(std::string p_product)
{
    m_shoppingList.emplace(p_product);
}

void ShoppingList::clear()
{
    m_shoppingList.clear();
}

void ShoppingList::show()
{
    std::cout << "List of set items:" << std::endl;
    for (auto line : m_shoppingList)
    {
    	std::cout << "\t" << line << std::endl;
    }
}
 
bool ShoppingList::isCommandProcessible(std::string p_command)
{
    std::cout << "is in s_availableShoppingList:"
        << int(s_availableShoppingList.find(p_command) != s_availableShoppingList.end())
        << std::endl;
	return s_availableShoppingList.find(p_command) != s_availableShoppingList.end();
}

ShoppingList::ShoppingList(){}

ShoppingList::~ShoppingList(){}
