#include "tools_string.h"
#include <CUnit/CUnit.h>

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