#include "StringTool.h"
#include <stddef.h>

int countCharInString(const char *s, const int length, const char c)
{
    if (length <= 0 || s == NULL || c == NULL)
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