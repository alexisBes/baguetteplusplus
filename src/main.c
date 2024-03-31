// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdlib.h>
#include "FileUtils.h"
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
        
        long int length = fileSize(fileBaguette);
        char *input = malloc(sizeof(char) * (length +2));
        
        readEntireFile(fileBaguette,input);

        fclose(fileBaguette);

        LexerData lexerData;
        short int tokenizeRsult = tokenizeDocument(input, length, &lexerData);
        //free(input);
        printLexer(&lexerData);

        if(tokenizeRsult != 0)
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