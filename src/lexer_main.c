#include "lexer_main.h"
#include "stdlib.h"
#include "tools_string.h"
#include "lexer_ident.h"

#define _BPP_OPERATEUR_ "-*/+ ;<"
#define _BPP_OPERATEUR_SIZE sizeof(_BPP_OPERATEUR_)

#define _BPP_TRASH " \r\t\n"
#define _BPP_TRASH_SIZE sizeof(_BPP_TRASH)
/**
 * @brief pointeur vers le fichier sources.
 */
FILE *fileBaguette = NULL;

/*****
 * @brief Logique de récupération d'un entier naturel non signée. /!\ fait avancer le stream de fileBaguette
 * @param out_param le nombre stocké en chaine de cractere
 * @param out_index la taille du nombre récupére (ne prend pas en compte le \0)
 */
void recuperationNombre(char **out_param,const char c);

/*****
 * @brief Logique de récupération d'un identifiant.  /!\ fait avancer le stream de fileBaguette
 * @param out_param l'identifiant stocké en chaine de caractere
 * @param out_index la taille de l'identifiant récupére (ne prend pas en compte le \0)
 */
void recuperationIdentifiant(char **out_param, const char c);

/*****
 * @brief Logique de récupération d'un opérateur.  /!\ fait avancer le stream de fileBaguette
 * @param current le caractère en cours d'analyse par le lexer
 * @return le type d'opérateur récupérer
 */
unite_type recupOperateur(const char current);

void initLexer(const char *path)
{
    fileBaguette = fopen(path, "r");
    if (fileBaguette == NULL)
    {
        perror("Erreur a l'ouverture du fichier");
        exit(-1);
    }
}

void getNextToken(unite_type *out_TypeLexique, char **param)
{
    if (fileBaguette == NULL)
    {
        printf("Veuillez renseignez un fichier.\n");
        return;
    }
    char currentChar = fgetc(fileBaguette);
    *param == NULL;
    // si le premier caracteres est a ingorer, on bouclejusqu'a avoir autre chose
    while (!feof(fileBaguette) && isCharExistInArray(currentChar, _BPP_TRASH, _BPP_TRASH_SIZE))
    {
        currentChar = fgetc(fileBaguette);
    }

    // si on est a la fin du fichier, on arrete tout.
    if (feof(fileBaguette))
    {
        *out_TypeLexique = UNITE_LEXICAL_COUNT;
        return;
    }

    // le caracter est un chiffre
    if (currentChar >= '0' && currentChar <= '9')
    {
        // alors c'est forcement un nombre
        recuperationNombre(param , currentChar);
        *out_TypeLexique = NOMBRE;
        return;
    }
    else
    {
        unite_type operateur = recupOperateur(currentChar);
        if (operateur != UNITE_LEXICAL_COUNT)
        {
            *out_TypeLexique = operateur;
            return;
        }

        // si ce n'est pas un operateur, c'est un identifiant
        if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
        {
            char *ident = NULL;
            recuperationIdentifiant(&ident, currentChar);
            *out_TypeLexique = checkIdentifiant(ident);
            if (*out_TypeLexique == IDENTIFIANT)
            {
                *param = copyString(ident);
            }
            else
            {
                *param = NULL;
            }
            free(ident);
            return;
        }
    }
    *out_TypeLexique = UNITE_LEXICAL_COUNT; // impossible de trouver une valeur
    return;
}

void closeLexer()
{
    fclose(fileBaguette);
}

void recuperationNombre(char **out_param,const char c)
{

    char *number = malloc(2 * sizeof(char));
    int index = 0;
    number[index] = c;
    index++;
    char currentChar =c;
    do
    {
        currentChar = fgetc(fileBaguette);
        number = realloc(number, sizeof(char) * (index + 1));
        if (isCharExistInArray(currentChar, _BPP_OPERATEUR_, _BPP_OPERATEUR_SIZE) || isCharExistInArray(currentChar, _BPP_TRASH, _BPP_TRASH_SIZE))
        {
            number[index] = '\0';
            *out_param = copyString(number);
            fseek(fileBaguette, -1, SEEK_CUR);
            free(number);
            return;
        }
        if (currentChar < '0' && currentChar > '9')
        {
            fprintf(stderr, "Erreur, token invalid.\n");
            free(number);
            out_param = NULL;
            return;
        }

        number[index] = currentChar;
        index++;

    } while (!feof(fileBaguette));
}

void recuperationIdentifiant(char **out_param, const char c)
{
    int index = 0;
    char *tempString = malloc(2 * sizeof(char));

    tempString[index] = c;
    index++;
    char currentChar = '\0';
    do
    {
        currentChar = fgetc(fileBaguette);
        tempString = realloc(tempString, sizeof(char) * (index + 1));
        if (isCharExistInArray(currentChar, _BPP_OPERATEUR_, _BPP_OPERATEUR_SIZE) || isCharExistInArray(currentChar, _BPP_TRASH, _BPP_TRASH_SIZE))
        {
            tempString[index] = '\0';
            fseek(fileBaguette, -1, SEEK_CUR);
            *out_param = copyString(tempString);
            free(tempString);
            return;
        }
        tempString[index] = currentChar;
        index++;

    } while (!feof(fileBaguette));
}

unite_type recupOperateur(const char current)
{
    unite_type returnLexique = UNITE_LEXICAL_COUNT;
    if (!isCharExistInArray(current, _BPP_OPERATEUR_, _BPP_OPERATEUR_SIZE))
    {
        return returnLexique;
    }

    // sinon c'est peut etre un opérateur
    if (current == '+')
        return ADDITION;
    if (current == '*')
        return MULTIPLICATION;
    if (current == '-')
        return SOUSTRACTION;
    if (current == '/')
        return DIVISION;

    // < peut etre multiple (< ou <-)
    if (current == '<')
    {
        char c = fgetc(fileBaguette);
        if (c == '-')
            return AFFECTATION;
        else
        {
            fseek(fileBaguette, -1, SEEK_CUR);
            return UNITE_LEXICAL_COUNT;
        }
    }
    // sinon c'est peut etre une fin d'instruction
    if (current == ';')
    {
        return FIN_INSTRUCTION;
    }
    printf("tu n'est pas censé allez jusque ici, %c-%d.\n", current, current);
    exit(EXIT_FAILURE);
}