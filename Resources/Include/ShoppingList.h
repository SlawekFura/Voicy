#pragma once
#include "IResource.h"

class ShoppingList : public IResource<std::set<std::string>>
{
    std::set<std::string> m_shoppingList;

public:
    ShoppingList();
    ~ShoppingList();
    ShoppingList(const std::set<std::string>& p_shoppingList) : m_shoppingList(p_shoppingList)
    {}
    void add(std::string) override;
    void erase(std::string) override;
    void clear() override;
    void show() override;
    std::set<std::string> getResource() override { return m_shoppingList; };
    bool isCommandProcessible(std::string) override;
};
