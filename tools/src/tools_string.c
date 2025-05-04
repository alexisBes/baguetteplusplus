#include "tools_string.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

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

char isCharExistInArray(const char c, const char *array, const int length)
{
    if (length <= 0 || array == NULL)
    {
        return -1;
    }

    for (int i = 0; i < length; i++)
    {
        if(c == array[i])
            return 1;
    }
    return 0;
}

char* copyString(char* ori){
    char * cpStr = "";
    if (ori==NULL)
    {
        return cpStr;
    }
    
    int size = strlen(ori);
    cpStr = malloc(sizeof(char) * size);

    strcpy(cpStr, ori);
    return cpStr;
}