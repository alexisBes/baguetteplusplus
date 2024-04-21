#ifndef STRING_TOOLS
#define STRING_TOOLS

int countCharInString(const char* s, const int length, const char c);

short int isCharExistInArray(const char c, const char* array, const int length);

char* concatanateString(char *ori, char* concat, const int totalLength);

char* concatanateChar(char *ori, char concat);

char* copyString(char* ori);
#endif

