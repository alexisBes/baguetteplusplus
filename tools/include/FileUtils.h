#ifndef FILE_UTILS_H
#define FILE_UTILS_H
#include <stdio.h>

void readEntireFile(FILE* file, char* str);

long int fileSize(FILE* file);

#endif