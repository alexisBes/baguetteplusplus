#include "bppFile.h"

long int readSourceCode(FILE *file, char *str)
{
    long int index =0;
    short int isCommentaire = 0;
    while (!feof(file))
    {
        char c = getc(file);
        if(c == '!')
        {
            isCommentaire=!isCommentaire;
        }
        if(c == '\n' && isCommentaire == 1)
        {
            isCommentaire=0;
        }
        if(!isCommentaire) 
        {
            str[index] = c;
            index++;
        }
    }
    str[index] = '\0';
    return index;
}

long int readSizeFile(FILE *file)
{
    return fileSize(file);
}
