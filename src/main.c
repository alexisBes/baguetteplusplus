// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "stdlib.h"
#include "lexer_main.h"
#include "parser_main.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        initLexer(argv[1]);
        printf("Lancement de la compilation de %s \n", argv[1]);

        parsing();
        closeLexer();
    }
    return 0;
}