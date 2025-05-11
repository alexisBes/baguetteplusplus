
#include <stdio.h>
#include "suite_toolsString.h"
#include "suite_toolsTree.h"
#include "CUnit/Basic.h"

int Test_ToolsString(CU_pSuite suite);
int Test_ToolsTree_Create(CU_pSuite suite);
int Test_ToolsTree(CU_pSuite suite);
/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;
   CU_pSuite pSuite_Tree_CreateDestruct = NULL;
   CU_pSuite pSuite_Tree = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("ToolsString", Init_ToolsString, Clean_ToolsString);
   if (NULL == pSuite)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   Test_ToolsString(pSuite);

   /* add a suite to the registry */
   pSuite_Tree_CreateDestruct = CU_add_suite("ToolsTree Creation & Destruction", 
      Init_ToolsTree_CreateDestruct,
      Clean_ToolsTree_CreateDestruct);
   if (NULL == pSuite_Tree_CreateDestruct)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   Test_ToolsTree_Create(pSuite_Tree_CreateDestruct);
   /* add a suite to the registry */
   pSuite_Tree = CU_add_suite("ToolsTree Others", 
      Init_ToolsTree,
      Clean_ToolsTree);
   if (NULL ==pSuite_Tree)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   Test_ToolsTree(pSuite_Tree);
   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

int Test_ToolsString(CU_pSuite suite)
{
   /* add the tests to the suite */
   int result = 0;
   result = (NULL == CU_add_test(suite, "CountCharInString", test_CountCharInString));
   result = result || (NULL == CU_add_test(suite, "CountCharInString KO", test_CountCharInString_KO));
   result = result || (NULL == CU_add_test(suite, "isCharExistInArray", test_isCharExistInArray));
   result = result || (NULL == CU_add_test(suite, "isCharExistInArray KO", test_isCharExistInArray_KO));
   result = result || (NULL == CU_add_test(suite, "copyString", test_copyString));
   result = result || (NULL == CU_add_test(suite, "copyString KO", test_copyString_KO));
   if (result)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   return result;
}
int Test_ToolsTree_Create(CU_pSuite suite)
{
   int result = 0;
   result = (NULL == CU_add_test(suite, "Test de CreateTree Structure", test_CreateTree_struct));
   result = result || (NULL == CU_add_test(suite, "Test de CreateTree const", test_CreateTree_const));
   result = result || (NULL == CU_add_test(suite, "Test de CreateTree pointer", test_CreateTree_pointer));
   if (result)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   return result;
}
int Test_ToolsTree(CU_pSuite suite)
{
   int result = 0;
   result = (NULL == CU_add_test(suite, "Test d'ajout d'item gauche ", test_AddItemG));
   result = result || (NULL == CU_add_test(suite, "Test d'ajout d'item droite ", test_AddItemD));
   result = result || (NULL == CU_add_test(suite, "Test d'ajout d'item gauche gauche ", test_AddItemGG));
   result = result || (NULL == CU_add_test(suite, "Test d'ajout d'item droite droite ", test_AddItemDD));
   if (result)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   return result;
}