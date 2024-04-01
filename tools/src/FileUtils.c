#include "FileUtils.h"

void readEntireFile(FILE *file, char *str)
{
    int index =0;
    while (!feof(file))
    {
        str[index] = getc(file);
        index++;
    }
    
}

long int fileSize(FILE *file)
{
    // get length of file:
    fseek(file ,0L, SEEK_END);
    long int length = ftell(file); 

    rewind(file);
    return length;
}
