
#include <stdio.h>
#include "suite_toolsString.h"
#include "suite_toolsTree.h"
#include "CUnit/Basic.h"


/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;
   CU_pSuite pSuite_Tree = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_ToolsString", Init_ToolsString, Clean_ToolsString);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   int result = 0;
   result= (NULL == CU_add_test(pSuite, "Test de CountCharInString", test_CountCharInString));
   result = result || (NULL == CU_add_test(pSuite, "Test de CountCharInString KO", test_CountCharInString_KO));
   result = result || (NULL == CU_add_test(pSuite, "Test de test_isCharExistInArray", test_isCharExistInArray));
   result = result || (NULL == CU_add_test(pSuite, "Test de test_isCharExistInArray KO", test_isCharExistInArray_KO));
   if (result)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

      /* add a suite to the registry */
      pSuite_Tree = CU_add_suite("Suite_ToolsTree", Init_ToolsTree, Clean_ToolsTree);
      if (NULL == pSuite_Tree) {
         CU_cleanup_registry();
         return CU_get_error();
      }
   
      int restul_Tree= 0;
      restul_Tree= (NULL == CU_add_test(pSuite_Tree, "Test de CreateTree", test_CreateTree));
      if (restul_Tree)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

      /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

