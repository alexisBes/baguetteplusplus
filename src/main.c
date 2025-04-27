// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine a cet endroit.
//

#include "stdlib.h"
#include "lexer_main.h"
#include "parser_main.h"
#include "generateur_main.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        initLexer(argv[1]);
        printf("Lancement de la compilation de %s \n", argv[1]);

        Tree* arbreInstruction  =NULL;
        // analyse syntaxique.
        parsing(&arbreInstruction);

        // Ajout de la partie lecture semantique 
        //quand on aura une table des symboles
        
        // generateur de code
        generate( arbreInstruction);

        // fermeture des fichiers
        closeLexer();
    }
    return 0;
}