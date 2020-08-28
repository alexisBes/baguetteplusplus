// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <iostream>
#include "parser/mainParser.h"

int main(int argc, char* argv[])
{
	std::string firstLine = "";
	if (argc > 1)
	{
		std::ifstream fileBaguette;
		fileBaguette.open(argv[1]);
		firstLine = parsing(fileBaguette);
		fileBaguette.close();
	}
	std::ofstream testFile;
	testFile.open("coucou.txt");
	testFile << "coucou dans un fichier texte \n" << firstLine << std::endl;
	testFile.close();
	return 0;
}