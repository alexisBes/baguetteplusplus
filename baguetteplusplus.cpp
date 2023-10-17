// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "storage.h"
#include "mainLexer.h"
#include "mainParser.h"

int main(int argc, char* argv[])
{
	std::string firstLine = "";
	if (argc > 1)
	{
		std::ifstream fileBaguette;
		fileBaguette.open(argv[1]);
		if(fileBaguette.good())
		{
			DocContext* docContext = (DocContext*) malloc(sizeof(DocContext));
			sortDocument(fileBaguette, docContext);
			parsing(fileBaguette, docContext);



			delete docContext;
		}
		fileBaguette.close();
	}
	return 0;
}