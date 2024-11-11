// baguetteplusplus.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "stdlib.h"
#include "parser_main.h"

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

        parsing(fileBaguette);
    }
    return 0;
}