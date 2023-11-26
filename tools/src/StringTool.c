#include "StringTool.h"
#include <stddef.h>

int countCharInString(const char * s, const long int length, const char c )
{
    if(length <= 0 || s == NULL || c == NULL)
        return -1;
    long int count= 0;
    for (long int i = 0; i < length; i++)
    {
        char cur = s[i];
        if (cur == '\0')
         return count;
        
        if (cur == c)
            count++;
    }
    
    return count;
}