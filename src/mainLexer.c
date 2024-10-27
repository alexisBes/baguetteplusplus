#include "mainLexer.h"
#include "stdlib.h"
#include "StringTool.h"

#define SIZE_DELIM 1
#define SIZE_OPERATEUR 11

unsigned char getNextToken(FILE *codeFile ,char *out_token){
    const char delimiteur[] = "\t \n";
    const char operateur[] = "=-<>:^;+/*";

    unsigned char isEndInstruction = 0, isEndToken = 0;
    int sizeToken = 0;
    out_token = malloc(sizeof(char));
    while (!isEndToken && !feof(codeFile))
    {
        char c = getc(codeFile);
        out_token  =realloc(out_token, sizeof(char) * (sizeToken +1));
        out_token[sizeToken] = c;
        if(isCharExistInArray(c, delimiteur, SIZE_DELIM))
        {
            out_token[sizeToken] = '\0';
            break;
        }
        if(';' == c)
        {
            out_token[sizeToken] = '\0';
            isEndInstruction = 1;
            break;
        }
        if (isCharExistInArray(c, operateur, SIZE_OPERATEUR))
        {   
            out_token[sizeToken] = '\0';
            fseek(codeFile,-1,SEEK_CUR);
            break;
        }
        
        sizeToken++;
    }
    
    return isEndInstruction;
}