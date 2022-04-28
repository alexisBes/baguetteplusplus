#pragma once
#include <vector>
#include <string>

enum class VariableType
{
	ALPHANUMERIQUE, NOMBRE, ENTIER, BOOLEEN
};


struct Variable{
	Variable(std::string name, VariableType type):name(name), type(type) {};
	std::string name;
	VariableType type;
} ;

std::vector<Variable> allVariable;