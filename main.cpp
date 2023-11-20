// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "storage.h"
#include "mainLexer.h"
#include "mainParser.h"

int main(int argc, char *argv[])
{
	std::string firstLine = "";
	if (argc > 1)
	{
		std::ifstream fileBaguette;
		// get length of file:
		fileBaguette.seekg(0, fileBaguette.end);
		int length = fileBaguette.tellg();
		fileBaguette.seekg(0, fileBaguette.beg);
		char *input = new char[length];
		fileBaguette.open(argv[1]);
		if (fileBaguette.good())
		{
			fileBaguette.read (input,length);
		}
		fileBaguette.close();
		DocContext *docContext = new DocContext();
		tokenizeDocument(input, length, docContext);
		//parsing(fileBaguette,  docContext);

		delete[] input;
		delete docContext;
	}
	return 0;
}