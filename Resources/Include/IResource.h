#pragma once
#include <string>
#include <set>
#include <memory>

union Asset
{
    std::set<std::string> shoppingList;
};

template<typename T>
class IResource
{
public:
    virtual void add(std::string) = 0;
    virtual void erase(std::string) = 0;
    virtual void clear() = 0;
    virtual void show() = 0;
    virtual T getResource() = 0;
    virtual bool isCommandProcessible(std::string) = 0;
    virtual ~IResource(){};
};
