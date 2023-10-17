// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "mainParser.h"

int main(int argc, char* argv[])
{
	std::string firstLine = "";
	if (argc > 1)
	{
		std::ifstream fileBaguette;
		fileBaguette.open(argv[1]);
		if(fileBaguette.good())
		firstLine = parsing(fileBaguette);
		fileBaguette.close();
	}
	return 0;
}