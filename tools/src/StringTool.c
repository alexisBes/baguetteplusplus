#include "StringTool.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int countCharInString(const char *s, const int length, const char c)
{
    if (length <= 0 || s == NULL)
        return -1;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        char cur = s[i];
        if (cur == '\0')
            return count;

        if (cur == c)
            count++;
    }

    return count;
}

short int isCharExistInArray(const char c, const char *array, const int length)
{
    if (length <= 0)
        return 0;

    for (int i = 0; i < length; i++)
    {
        if(c == array[i])
            return 1;
    }
    return 0;
}

char* concatanateString(char *ori, char* concat, const int totalLength)
{
    char * newString = (char *) malloc(sizeof(char)* totalLength);
    strcpy(newString, ori);
    strcat(newString, concat);
    return newString;
}


char* concatanateChar(char *ori, const char concat)
{
    int length = strlen(ori);
    char * newString = (char *) malloc(sizeof(char)* (length +1));
    strcpy(newString, ori);
    newString[length] = concat;
    newString[length+1] = '\0';

    return newString;
}

char* copyString(char* ori){
    int size = strlen(ori);
    char * cpStr = malloc(sizeof(char) * size);

    strcpy(cpStr, ori);
    return cpStr;
}