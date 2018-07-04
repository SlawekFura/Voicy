#pragma once
#include <string>
#include "StringToEnumConverter.h"
#include <functional>
#include <set>

class IState
{
public:
	using Operation = std::function<void(std::set<std::string>&, std::string)>;
	using Perform = std::function< void(int) >;
	virtual void handleInput(std::string) = 0;
	virtual std::string getState() = 0;
	virtual ~IState() = default;
};