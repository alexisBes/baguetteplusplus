#ifndef STRING_TOOLS
#define STRING_TOOLS

#include "string.h"

int countCharInString(const char* s, const int length, const char c);

char isCharExistInArray(const char c, const char* array, const int length);

char* concatanateString(char *ori, char* concat, const int totalLength);

char* concatanateChar(char *ori, char concat);

char* copyString(char* ori);

char isIdenticalStr(const char * str1, const char * str2);

char isIdenticalStr_misc(const void * str1, const void * str2);

char isNumeric(const char* str1);
#endif

