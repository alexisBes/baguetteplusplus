#include "lexer_main.h"
#include "stdlib.h"
#include "tools_string.h"

#define _BPP_OPERATEUR_ "-*/+ ;\n"
#define _BPP_OPERATEUR_SIZE sizeof(_BPP_OPERATEUR_)

void recuperationNombre(char* out_param,int *out_index);
void recuperationIdentifiant(char* out_param,int *out_index);

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

void getNextToken(uniteLexical *out_TypeLexique, char *param)
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
        param = malloc(index* sizeof(char));
        strncpy(param,number, index);
        free(number);
        return;
    }
    else
    {   
        //sinon c'est peut etre un opérateur
        if(currentChar == '+') { *out_TypeLexique= ADDITION;return;} 
        if(currentChar == '*') { *out_TypeLexique= MULTIPLICATION;return;}
        if(currentChar == '-') {*out_TypeLexique= SOUSTRACTION;return ;}
        if(currentChar == '/') { *out_TypeLexique= DIVISION;return;}
        
        // sinon c'est peut etre une fin d'instruction
        if(currentChar == ';') { *out_TypeLexique= DIVISION;return;}
        
        // si ce n'est pas un operateur, c'est un identifiant 
        if((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
        {
            char *ident = malloc(2*sizeof(char));
            int index =0;
            ident[index]=currentChar;
            index++;
            recuperationIdentifiant(param,&index);
            *out_TypeLexique= IDENTIFIANT;
            param = malloc(index* sizeof(char));
            strncpy(param,ident, index);
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
    do
    {
        currentChar = fgetc(fileBaguette);
        if(isCharExistInArray(currentChar, _BPP_OPERATEUR_, _BPP_OPERATEUR_SIZE))
        {
            out_param =  realloc(out_param, sizeof(char)*(*out_index+1));
            out_param[*out_index] = '\0';
            fseek(fileBaguette,-1, SEEK_CUR);
            return;
        }
        if(currentChar <'0' && currentChar > '9')
        {
            fprintf(stderr,"Erreur, token invalid.\n");
            return;
        }

        out_param[*out_index]=currentChar;
        *out_index++;

    } while (!feof(fileBaguette));
    
}

void recuperationIdentifiant(char *out_param, int *out_index)
{
    char currentChar = '\0';
    do
    {
        currentChar = fgetc(fileBaguette);
        if(isCharExistInArray(currentChar, _BPP_OPERATEUR_, _BPP_OPERATEUR_SIZE))
        {
            out_param =  realloc(out_param, sizeof(char)*(*out_index+1));
            out_param[*out_index] = '\0';
            fseek(fileBaguette,-1, SEEK_CUR);
            return;
        }
        out_param[*out_index]=currentChar;
        *out_index++;

    } while (!feof(fileBaguette));
    
}