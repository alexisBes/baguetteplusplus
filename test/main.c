#include "ListUtils.h"
#include "StringTool.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("[ ERROR ] Impossible de lancer les tests, il manque des arguments.\n");
        exit(-1);
    }
    int type = atoi(argv[1]);
    short int  result = 0!=0;
    if (type % 2 == 0)
    {
        if(argc < 5) 
        {
            printf("[ ERROR ] Impossible de lancer les tests, il manque des arguments %d.\n   ECHEC   \n", argc);
            exit(-1);
        }
        // test string utils
        printf(" Lancement du test sur stringutils \n");
        if (type == 2)
        {
            /* test countCharInString */
            printf(" test de countChar in string \n");

            char * testingString = argv[2];
            char testChar = argv[3][0];
            int nbExpected =atoi(argv[4]);
            int nbComputed = countCharInString(testingString, strlen(testingString), testChar);
            result =  nbExpected == nbComputed;
        }
        else if (type == 4)
        {
            /* test isCharExistInArray */
            printf(" test de isCharExistInArray in array \n");
            const char * testingString = argv[2];
            const char testChar = argv[3][0];
            int expectedResult = atoi(argv[4]);
            int computedResult = isCharExistInArray(testChar, testingString, strlen(testingString));
            result =  expectedResult == computedResult;
        }
        else if (type == 6)
        {
            /* test concatanateString */
            printf(" test de concatanateString \n");
            char * testingString = argv[2];
            char* testChar = argv[3];
            char* expectedResult = argv[4];
            char* computedResult = concatanateString(testingString, testChar, strlen(testingString) + strlen(testChar) +1);
            result = strcmp(expectedResult, computedResult) == 0;
        }
        else if (type == 8)
        {
            /* test concatanateChar */
            printf(" test de concatanateChar \n");
            char * testingString = argv[2];
            char testChar = argv[3][0];
            char* expectedResult = argv[4];
            char* computedResult = concatanateChar(testingString, testChar);
            result = strcmp(expectedResult, computedResult) == 0;
        }
    }
    else
    {
                // test string utils
        if (type == 3)
        {
            /* code */
        }
        else if (type == 5)
        {
            /* code */
        }
        else if (type == 7)
        {
            /* code */
        }
        else if (type == 9)
        {
            /* code */
        }
        else if (type == 11)
        {
            /* code */
        }
        else if (type == 13)
        {
            /* code */
        }
    }
    if(result)
        printf("SUCCES \n");
    else
        printf("ECHEC \n");
}