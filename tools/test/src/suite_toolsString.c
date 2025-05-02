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
}