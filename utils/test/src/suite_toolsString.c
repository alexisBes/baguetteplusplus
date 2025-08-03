#include "tools_string.h"
#include <CUnit/CUnit.h>
#include "stdlib.h"

int Init_ToolsString()
{
    return 0;
}

int Clean_ToolsString()
{
    return 0;
}

void test_CountCharInString()
{
    CU_ASSERT(countCharInString("toto",4,'t')==2);
    CU_ASSERT(countCharInString("toto",4,'T')==0);
    CU_ASSERT(countCharInString("toto",3,'o')==1);
}

void test_CountCharInString_KO()
{
    CU_ASSERT(countCharInString(NULL,0,'t')==-1);
    CU_ASSERT(countCharInString(NULL,9,'t')==-1);
    CU_ASSERT(countCharInString("TATA",8,'T')==2);
}

void test_isCharExistInArray()
{
    CU_ASSERT_TRUE(isCharExistInArray('t', "toto", 4));
    CU_ASSERT_FALSE(isCharExistInArray('T', "toto", 4));
    CU_ASSERT_FALSE(isCharExistInArray('b', "albert", 2));
}

void test_isCharExistInArray_KO()
{

    CU_ASSERT_EQUAL(isCharExistInArray('t', NULL, 4),-1);
    CU_ASSERT_EQUAL(isCharExistInArray('T', "toto", 0),-1);
    CU_ASSERT_FALSE_FATAL(isCharExistInArray('T', "toto", 15));
}

void test_getIndexStringInArray()
{
    const char *Dico[3] = {"toto","ToTo", "albert"};
    CU_ASSERT(getIndexStringInArray("toto", Dico, 3)==0);
    CU_ASSERT(getIndexStringInArray("ToTo", Dico, 3)==1);
    CU_ASSERT(getIndexStringInArray("albert", Dico, 3)==2);
}

void test_getIndexStringInArray_KO()
{
    const char *Dico[3] = {"toto","ToTo", "albert"};
    CU_ASSERT_EQUAL(getIndexStringInArray("t", NULL, 4),-1);
    CU_ASSERT_EQUAL(getIndexStringInArray(NULL,Dico, 4),-1);
    CU_ASSERT_EQUAL(getIndexStringInArray("T", Dico, 0),-1);
}

void test_copyString(){
    char* str = copyString("Joseph Joestar");
    CU_ASSERT(strcmp(str,"Joseph Joestar")==0);
    free(str);
}
void test_copyString_KO(){
    char* str = copyString(NULL);
    CU_ASSERT(str == NULL);

}