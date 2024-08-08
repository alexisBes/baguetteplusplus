#include "time.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "StringTool.h"
short int checkList(List *newNode, char *expectedValues[], int size, int toIgnore);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("[ ERROR ] Impossible de lancer les tests, il manque des arguments.\n");
        exit(-1);
    }
    long valueTest = strtol(argv[1], NULL, 16);
    long typeTest = valueTest >> 4;
    long value = valueTest & 0b1111;
    short int result = 0;
    if (typeTest == 0b0001)
    {
        if (argc < 5)
        {
            printf("[ ERROR ] Impossible de lancer les tests, il manque des arguments %d.\n   ECHEC   \n", argc);
            exit(-1);
        }
        // test string utils
        printf(" Lancement du test sur superstrings \n");
        if (value == 0b0001)
        {
            /* test countCharInString */

            char *testingString = argv[2];
            char testChar = argv[3][0];
            int nbExpected = atoi(argv[4]);
            int nbComputed = countCharInString(testingString, strlen(testingString), testChar);
            result = nbExpected == nbComputed;
            printf("test countChar : ");
        }
        else if (value == 0b0010)
        {
            /* test isCharExistInArray */
            const char *testingString = argv[2];
            const char testChar = argv[3][0];
            int expectedResult = atoi(argv[4]);
            int computedResult = isCharExistInArray(testChar, testingString, strlen(testingString));
            result = expectedResult == computedResult;
            printf("test isCharExistInArray : ");
        }
        else if (value == 0b0011)
        {
            /* test concatanateString */
            char *testingString = argv[2];
            char *testChar = argv[3];
            char *expectedResult = argv[4];
            char *computedResult = concatanateString(testingString, testChar, strlen(testingString) + strlen(testChar) + 1);
            result = strcmp(expectedResult, computedResult) == 0;
            printf("test concatanateString : ");
        }
        else if (value == 0b0100)
        {
            /* test concatanateChar */
            char *testingString = argv[2];
            char testChar = argv[3][0];
            char *expectedResult = argv[4];
            char *computedResult = concatanateChar(testingString, testChar);
            result = strcmp(expectedResult, computedResult) == 0;
            printf("test concatanateChar : ");
        } else if (value == 0b0101)
        {
            /* test isIdenticalStr */
            char *testingString = argv[2];
            result  = isIdenticalStr(testingString, testingString);
            printf("test copyString : ");
        }
        else if (value == 0b0110)
        {
            /* test concatanateChar */
            char *testingString = argv[2];
            char *expectedResult = argv[4];
            char* computedResult  = copyString(testingString);
            result = strcmp(expectedResult, computedResult) == 0;
            printf("test isIdenticalStr : ");
        }
        
        if (result)
            printf("SUCCES \n");
        else
            printf("ECHEC \n");
    }
    if (typeTest == 0b0010)
    {
        List *newNode = createNodeList(argv[2]);
        for (int i = 3; i < argc; i++)
        {
            addNode(newNode, argv[i]);
        }
        printf("test initList : ");
        if (argc - 2 == listSize(newNode))
        {
            printf("SUCCES\n");
        }
        else
        {
            printf("ECHEC\n");
        }


        List *found = findNodeInList(newNode, argv[3], isIdenticalStr_misc );

        printf("test find List : ");
        if(found != NULL && isIdenticalStr(found->content, argv[3]))
            printf("SUCCES ");
        else
            printf("ECHEC ");
        
        List *nFound = findNodeInList(newNode, argv[0], isIdenticalStr_misc );
        if(nFound == NULL)
            printf("SUCCES \n");
        else
            printf("ECHEC \n");

        printf("test ValueList : ");
        if (checkList(newNode, argv, argc, -1))
            printf("SUCCES \n");
        else
            printf("ECHEC \n");
        srand(time(NULL));
        printf("test removeList: ");
        int random = (rand() + 2) % argc + 1;
        removeNode(newNode, random);
        if (argc - 3 == listSize(newNode))
            printf("SUCCES \n");
        else
            printf("ECHEC \n");

        clearList(newNode);
        printf("test clearList: SUCCES");
    }
    if (typeTest == 0b0011)
    {
        printf("test creat tree : ");
        Tree *root = createTree(argv[2]);
        Tree* currentTree = root;
        bool lor = 1;
        for (int i = 3; i < argc; i++)
        {
            addItem(currentTree, argv[i],lor);
            if(lor == 0)
            {
                currentTree = currentTree->lNode;
            }
            lor = !lor;
        }
        printf("SUCCES \n");

        Tree *found = findItemInTree(root, argv[3], isIdenticalStr_misc );

        printf("test find tree : ");
        if(found != NULL && isIdenticalStr(found->content, argv[3]))
            printf("SUCCES ");
        else
            printf("ECHEC ");
        
        Tree *nFound = findItemInTree(root, argv[0], isIdenticalStr_misc );
        if(nFound == NULL)
            printf("SUCCES \n");
        else
            printf("ECHEC %s\n", (const char*)nFound->content);
        
        printf("test clear tree ");
        clearTree(root);
        printf("SUCCES \n");
    }
    
}

short int checkList(List *newNode, char *expectedValues[], int size, int toIgnore)
{
    short int isValid = 1;
    int ignored = 0;
    for (int i = 2; i < size; i++)
    {
        if (toIgnore == i)
        {
            ignored++;
        }
        else
        {
            const int goodIndex = i - 2 - ignored;
            if (strcmp(expectedValues[i], (char *)getNode(newNode, goodIndex)->content) != 0)
            {
                isValid = 0;
            }
        }
    }
    return isValid;
}