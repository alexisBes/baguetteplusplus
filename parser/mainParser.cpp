#include "mainParser.h"

#include "../lexer/mainLexer.h"

std::string parsing(std::ifstream& f)
{
	sortDocument(f);
	return "\n je suis passe dans la fonction";
}
