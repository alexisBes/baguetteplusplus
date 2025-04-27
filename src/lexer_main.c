#include "lexer_main.h"
#include "stdlib.h"
#include "tools_string.h"

#define _BPP_OPERATEUR_ "-*/+ ;<\n"
#define _BPP_OPERATEUR_SIZE sizeof(_BPP_OPERATEUR_)

void recuperationNombre(char* out_param,int *out_index);
void recuperationIdentifiant(char* out_param,int *out_index);
uniteLexical recupOperateur(const char current);

FILE *fileBaguette = NULL;

void initLexer(const char *path)
{
    fileBaguette = fopen(path, "r");
    if (fileBaguette==NULL)
    {
        perror("Erreur a l'ouverture du fichier");
        exit(-1);
    }
}

void getNextToken(uniteLexical *out_TypeLexique, char **param)
{
    if (fileBaguette == NULL)
    {
        printf("Veuillez renseignez un fichier.\n");
        return;
    }
    char currentChar= fgetc(fileBaguette);
    
    // le caracter est un chiffre
    if(currentChar >='0' && currentChar <= '9')
    {
        // alors c'est forcement un nombre
        char *number = malloc(2*sizeof(char));
        int index =0;
        number[index]=currentChar;
        index++;
        recuperationNombre(number,&index);
        number[index]='\0';
        *out_TypeLexique=NOMBRE;
        *param = malloc(index* sizeof(char));
        strncpy(*param,number, index);
        free(number);
        return;
    }
    else
    {
        uniteLexical operateur = recupOperateur(currentChar);
        if(operateur != UNITE_LEXICAL_COUNT)
        {
            *out_TypeLexique= operateur;
            return;
        }
        
        // si ce n'est pas un operateur, c'est un identifiant 
        if((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
        {
            char *ident = malloc(2*sizeof(char));
            int index =0;
            ident[index]=currentChar;
            index++;
            recuperationIdentifiant(ident,&index);
            *out_TypeLexique= IDENTIFIANT;
            *param = malloc(index* sizeof(char));
            strncpy(*param,ident, index);
            free(ident);
            return;
        }
    }
    *out_TypeLexique= UNITE_LEXICAL_COUNT;// impossible de trouver une valeur
    return; 
}

void closeLexer()
{
    fclose(fileBaguette);
}

void recuperationNombre(char* out_param,int *out_index)
{
    char currentChar = '\0';
    int index = *out_index;
    do
    {
        currentChar = fgetc(fileBaguette);
        out_param =  realloc(out_param, sizeof(char)*(index +1));
        if(isCharExistInArray(currentChar, _BPP_OPERATEUR_, _BPP_OPERATEUR_SIZE))
        {
            out_param[index] = '\0';
            fseek(fileBaguette,-1, SEEK_CUR);
            *out_index=index;
            return;
        }
        if(currentChar <'0' && currentChar > '9')
        {
            fprintf(stderr,"Erreur, token invalid.\n");
            free(out_param);
            return;
        }

        out_param[index]=currentChar;
        index++;

    } while (!feof(fileBaguette));
    
}

void recuperationIdentifiant(char *out_param, int *out_index)
{
    char currentChar = '\0';
    int index = *out_index;
    do
    {
        currentChar = fgetc(fileBaguette);
        out_param =  realloc(out_param, sizeof(char)*( index +1));
        if(isCharExistInArray(currentChar, _BPP_OPERATEUR_, _BPP_OPERATEUR_SIZE))
        {
            out_param[index] = '\0';
            *out_index=index;
            fseek(fileBaguette,-1, SEEK_CUR);
            return;
        }
        out_param[index]=currentChar;
        index++;

    } while (!feof(fileBaguette));
    
}

uniteLexical recupOperateur(const char current)
{
    uniteLexical returnLexique = UNITE_LEXICAL_COUNT;
    if (!isCharExistInArray(current,_BPP_OPERATEUR_,_BPP_OPERATEUR_SIZE))
    {
        return returnLexique;
    }

        //sinon c'est peut etre un opérateur
        if(current == '+') return ADDITION; 
        if(current == '*') return MULTIPLICATION;
        if(current == '-') return SOUSTRACTION;
        if(current == '/') return DIVISION;

        // < peut etre multiple (< ou <-)
        if(current == '<')
        {
            char c = fgetc(fileBaguette);
            if(c == '-') return AFFECTATION;
            else {
                fseek(fileBaguette,-1, SEEK_CUR);
                return UNITE_LEXICAL_COUNT;
            }
        }
        // sinon c'est peut etre une fin d'instruction
        if(current == ';') { return FIN_INSTRUCTION;}
    printf("tu n'est pas censé allez jusque ici.\n");
    exit(EXIT_FAILURE);
}