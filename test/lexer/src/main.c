#include "stdio.h"
#include "lexer_main.h"
#include "string.h"
#include "stdlib.h"

unite_type getOneResult(FILE *fileResult, char **param);
char check_result(const unite_type computed, const unite_type exected,
                  const char *param_Computed, const char *param_Expected);

int main(int argc, char *argv[])
{
    printf("Initialisation du lexer...\n");

    if (argc < 2)
    {
        fprintf(stderr, "Impossible d'initialiser le test.");
        return 1;
    }

    initLexer(argv[1]);
    FILE *fileResult = fopen(argv[2], "r");
    char *param_expected = NULL;
    char *param = NULL;
    int result = 0, total = 0;
    while (!feof(fileResult))
    {
        unite_type type_expected = getOneResult(fileResult, &param_expected);
        unite_type type = UNITE_LEXICAL_COUNT;
        getNextToken(&type, &param);
        total++;
        result += check_result(type, type_expected, param, param_expected);
        if (param != NULL)
        {
            free(param);
            param = NULL;
        }
        if(param_expected != NULL)
        {
            free(param_expected);
            param = NULL;
        }

        getc(fileResult); // fin de test, on supprime le retour a la ligne (s'il existe)
    }
    closeLexer();
    fclose(fileResult);
    if (result == total)
    {
        printf("\033[0;32m INFO \033[0m %d test furent correctement joue.\n", total);
        return 0;
    }
    else
    {
        printf("\033[0;31m ERREUR \033[0m %d tests ont echoue.\n", total - result);
        return 1;
    }
}

unite_type getOneResult(FILE *fileResult, char **param)
{
    int res = 0;
    char c = '0';
    do
    {
        res *= 10;
        res += c - '0';
        c = getc(fileResult);
    } while (c != ';');
    unite_type unite = (unite_type)res;
    char tmp[255];
    memset(&tmp, 0, sizeof(char) * 255);
    int i = 0;
    c = '\0';
    while (c != ';')
    {
        c = tmp[i] = getc(fileResult);
        i++;
    }
    tmp[i - 1] = '\0';
    *param = malloc(sizeof(char) * i);
    memcpy(*param, tmp, sizeof(char) * i);
    return unite;
}

char check_result(const unite_type computed, const unite_type expected,
                  const char *param_Computed, const char *param_Expected)
{
    char result = 1;
    if (computed != expected)
    {
        printf("\033[0;31m ERREUR \033[0m le lexer s'attendait a recevoir un token de type %d et %d fut calculée.\n", expected, computed);
        result = 0;
    }
    if (param_Computed != NULL && strcmp(param_Computed, param_Expected) != 0)
    {
        printf("\033[0;31m ERREUR \033[0m le lexer s'attendait a recevoir ce parametre \"%s\", \"%s\" fut calculée.\n", param_Expected, param_Computed);
        result = 0;
    }
    if(result ==1)printf("\033[0;32m INFO \033[0m %d correctement trouvé.\n", expected);
    return result;
}