
#include <stdio.h>
#include "suite_lexer.h"
#include "suite_semer.h"
#include "CUnit/Basic.h"

static int Test_Lexer(CU_pSuite suite);

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
    CU_pSuite pSuite = NULL;
   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

       /* add a suite to the registry */
   pSuite = CU_add_suite("Lexer",Init_Lexer, Clean_Lexer);
   if (NULL == pSuite)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   Test_Lexer(pSuite);


       /* add a suite to the registry */
   pSuite = CU_add_suite("Semer",Init_Lexer, Clean_Lexer);
   if (NULL == pSuite)
   {
      CU_cleanup_registry();
      return CU_get_error();
   } 
   int result = (NULL == CU_add_test(pSuite, "Test de création de valeur signé",test_nouveauSymbole));
   result = result || (NULL == CU_add_test(pSuite, "Test avec des valeurs signé",test_nouveauSymbole_NonSigne));
   if (result)
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

int Test_Lexer(CU_pSuite suite)
{
     int result = 0;
   result = (NULL == CU_add_test(suite, "Test de récupération d'identifiant et nombre ",test_RetrieveIdent));
   result = result || (NULL == CU_add_test(suite, "Test de récupération des opération mathématique",test_RetrieveMathOperation));
   result = result || (NULL == CU_add_test(suite, "Test de récupération des types", test_RetrieveType));
   result = result || (NULL == CU_add_test(suite, "Test d'ajout de recupération des operation générique", test_RetrieveOperation));
   if (result)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   return result;
}
