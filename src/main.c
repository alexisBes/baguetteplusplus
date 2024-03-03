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
            printf("Impossible d'ouvrir le fichier  %s. Veuillez vérifier que le fichier existe.\n", argv[1]);
            exit(-1);
        }
        printf("Lancement de la compilation de %s \n", argv[1]);
        
        // get length of file:
        fseek(fileBaguette ,0L, SEEK_END);
        long int length = ftell(fileBaguette); 

        rewind(fileBaguette);
        char *input = malloc(sizeof(char) * (length +2));
        fgets(input,length, fileBaguette);

        fclose(fileBaguette);

        TOKEN_LIST lexerData;
        short int tokenizeRsult = tokenizeDocument(input, length, &lexerData);
        free(input);


        if(tokenizeDocument != 0)
        {
            eraseLexerData(&lexerData);
            printf("Une erreur est survenue durant l'analyse. Vérifier les logs.");
            return -1;
        }

        //short int parsingResult = parsing(&lexerData);

        eraseLexerData(&lexerData);
    }
    return 0;
}