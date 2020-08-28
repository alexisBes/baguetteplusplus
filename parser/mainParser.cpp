#include "mainParser.h"

#include "../lexer/mainLexer.h"

std::string parsing(std::ifstream& f)
{
	initLexer();
	std::string s;
	std::getline(f, s);
	return s + "\n je suis passé dans la fonction";
}
