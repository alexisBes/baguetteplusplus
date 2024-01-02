#include "ArrayUtils.h"
#include "string.h"
#include "stddef.h"

short int findInStringArray(const char *source[], const int size,const char* searching)
{
    for (int i = 0; i < size; i++)
    {
        if(strcmp(source[i], searching) == 0)
        {
            return i;
        }
    }
    return -1;
}