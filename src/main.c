// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdlib.h>
#include <stdio.h>
#include "mainLexer.h"
#include "mainParser.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		FILE *fileBaguette = fopen(argv[1], "r");
		
		if (fileBaguette==NULL)
		{
			printf("Enabe to open file %s\n", argv[1]);
			exit(-1);
		}
		
		// get length of file:
		fseek(fileBaguette ,0L, SEEK_END);
		long int length = ftell(fileBaguette); 

		rewind(fileBaguette);
		char *input = malloc(sizeof(char) * (length +2));
		fgets(input,length, fileBaguette);

		fclose(fileBaguette);

		LexerData lexerData;
		tokenizeDocument(input, length, &lexerData);
		//parsing(fileBaguette,  docContext);

		free(input);
	}
	return 0;
}