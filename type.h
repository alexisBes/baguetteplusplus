#pragma once
#include <vector>
#include <string>

enum class VariableType
{
	ALPHANUMERIQUE, NOMBRE, ENTIER, BOOLEEN, CHAINEDECARACTERE, VariableType_COUNT
};


typedef struct Variable{
	Variable(std::string name, std::string type):name(name), type(VariableType::NOMBRE)
	{
		if (type == "ALPHANUMERIQUE")
			this->type = VariableType::ALPHANUMERIQUE;
		if (type == "NOMBRE")
			this->type = VariableType::NOMBRE;
		if (type == "ENTIER")
			this->type = VariableType::ENTIER;
		if (type == "BOOLEEN")
			this->type = VariableType::BOOLEEN;
		if (type == "CHAINEDECARACTERE")
			this->type = VariableType::CHAINEDECARACTERE;
	};
	std::string name;
	VariableType type;
} VARIABLE;