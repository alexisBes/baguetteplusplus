#ifndef STRING_TOOLS
#define STRING_TOOLS
#include "Types.h"

int countCharInString(const char* s, const int length, const char c);

bool isCharExistInArray(const char c, const char* array, const int length);

char* concatanateString(char *ori, char* concat, const int totalLength);

char* concatanateChar(char *ori, char concat);

char* copyString(char* ori);

bool isIdenticalStr(const char * str1, const char * str2);

bool isIdenticalStr_misc(const void * str1, const void * str2);
#endif

