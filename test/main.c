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
    long valueTest = strtol(argv[1], NULL, 16 );
    long typeTest = valueTest > 4;
    long value = valueTest & 0b1111;
    short int  result = 0;
    if (typeTest & 0b0001 == 0b0001)
    {
        if(argc < 5) 
        {
            printf("[ ERROR ] Impossible de lancer les tests, il manque des arguments %d.\n   ECHEC   \n", argc);
            exit(-1);
        }
        // test string utils
        printf(" Lancement du test sur superstrings \n");
        if (value == 0b0001)
        {
            /* test countCharInString */

            char * testingString = argv[2];
            char testChar = argv[3][0];
            int nbExpected =atoi(argv[4]);
            int nbComputed = countCharInString(testingString, strlen(testingString), testChar);
            result =  nbExpected == nbComputed;
            printf("test countChar : ");
        }
        else if (value == 0b0010)
        {
            /* test isCharExistInArray */
            const char * testingString = argv[2];
            const char testChar = argv[3][0];
            int expectedResult = atoi(argv[4]);
            int computedResult = isCharExistInArray(testChar, testingString, strlen(testingString));
            result =  expectedResult == computedResult;
            printf("test isCharExistInArray : ");
        }
        else if (value == 0b0011)
        {
            /* test concatanateString */
            char * testingString = argv[2];
            char* testChar = argv[3];
            char* expectedResult = argv[4];
            char* computedResult = concatanateString(testingString, testChar, strlen(testingString) + strlen(testChar) +1);
            result = strcmp(expectedResult, computedResult) == 0;
            printf("test concatanateString : ");
        }
        else if (value == 0b0100)
        {
            /* test concatanateChar */
            char * testingString = argv[2];
            char testChar = argv[3][0];
            char* expectedResult = argv[4];
            char* computedResult = concatanateChar(testingString, testChar);
            result = strcmp(expectedResult, computedResult) == 0;
            printf("test concatanateChar : ");
        }
    }
    if(typeTest & 0b0010 == 0b0010)
    {
        // test list utils utils
        if (value == 0b001)
        {
            /* code */
        }
        else if (value == 0b0010)
        {
            /* code */
        }
        else if (typeTest == 0b0011)
        {
            /* code */
        }
        else if (typeTest == 0b0100)
        {
            /* code */
        }
        else if (typeTest == 0b0101)
        {
            /* code */
        }
        else if (typeTest == 0b0110)
        {
            /* code */
        }
    }
    if(result)
        printf("SUCCES \n");
    else
        printf("ECHEC \n");
}