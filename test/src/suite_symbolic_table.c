#include "suite_symbo_table.h"
#include "symbo_table_main.h"
#include <CUnit/CUnit.h>

int Init_Symbo_Table()
{
    return 0;
}

int Clean_Symbo_Table()
{
    cleanTable();
    return 0;
}

void checkResult(const char *nameVar, const unite_semantique *expectedResult)
{
    char expected = isSymbolExist(nameVar);
    CU_ASSERT(expected == 1);
    const unite_semantique *unitSem = getSymbol(nameVar);
    if (unitSem != NULL)
    {
        CU_ASSERT(unitSem->taille == expectedResult->taille);
        CU_ASSERT(unitSem->type == expectedResult->type);
        CU_ASSERT_STRING_EQUAL(unitSem->name, expectedResult->name);
    }
    else
    {
        CU_FAIL();
    }
}

void test_nouveauSymbole()
{

    char expected = isSymbolExist("TRUCMuch");
    CU_ASSERT(expected == 0);
    const unite_semantique *unitSem = getSymbol("TRUCMuch");
    CU_ASSERT(unitSem == NULL);

    CU_ASSERT_EQUAL(add_symbol(OCTET, "toto"),1);
    CU_ASSERT_EQUAL(add_symbol(ENTIER, "TATA"),1);
    CU_ASSERT_EQUAL(add_symbol(COURT, "TEST"),1);
    CU_ASSERT_EQUAL(add_symbol(LONG, "JOJO"),1);

    unite_semantique expectedUnit;
    expectedUnit.name = "toto";
    expectedUnit.taille = 1;
    expectedUnit.type = OCTET;

    expected = isSymbolExist("toto");
    CU_ASSERT(expected == 1);
    checkResult("toto", &expectedUnit);

    expectedUnit.name = "TATA";
    expectedUnit.taille = 4;
    expectedUnit.type = ENTIER;
    expected = isSymbolExist("TATA");
    CU_ASSERT(expected == 1);
    checkResult("TATA", &expectedUnit);

    expectedUnit.name = "TEST";
    expectedUnit.taille = 2;
    expectedUnit.type = COURT;
    expected = isSymbolExist("TEST");
    CU_ASSERT(expected == 1);
    checkResult("TEST", &expectedUnit);

    expectedUnit.name = "JOJO";
    expectedUnit.taille = 8;
    expectedUnit.type = LONG;
    expected = isSymbolExist("JOJO");
    CU_ASSERT(expected == 1);
    checkResult("JOJO", &expectedUnit);

    expected = isSymbolExist("TRUCMuch");
    CU_ASSERT(expected == 0);
    const unite_semantique *unitSem_notFound = getSymbol("TRUCMuch");
    CU_ASSERT(unitSem_notFound == NULL);

    expected = isSymbolExist("ToTo");
    CU_ASSERT(expected == 0);
    const unite_semantique *unitSem_notFound_2 = getSymbol("ToTo");
    CU_ASSERT(unitSem_notFound == NULL);
}

void test_nouveauSymbole_NonSigne()
{
    CU_ASSERT_EQUAL(add_symbol(OCTET_Nos, "U_toto"),1);
    CU_ASSERT_EQUAL(add_symbol(ENTIER_Nos, "U_TATA"),1);
    CU_ASSERT_EQUAL(add_symbol(COURT_Nos, "U_TEST"),1);
    CU_ASSERT_EQUAL(add_symbol(LONG_Nos, "U_JOJO"),1);

    unite_semantique expectedUnit;
    expectedUnit.name = "U_toto";
    expectedUnit.taille = 1;
    expectedUnit.type = OCTET_Nos;

    char expected = isSymbolExist("U_toto");
    CU_ASSERT(expected == 1);
    checkResult("U_toto", &expectedUnit);

    expectedUnit.name = "U_TATA";
    expectedUnit.taille = 4;
    expectedUnit.type = ENTIER_Nos;
    expected = isSymbolExist("U_TATA");
    CU_ASSERT(expected == 1);
    checkResult("U_TATA", &expectedUnit);

    expectedUnit.name = "U_TEST";
    expectedUnit.taille = 2;
    expectedUnit.type = COURT_Nos;
    expected = isSymbolExist("U_TEST");
    CU_ASSERT(expected == 1);
    checkResult("U_TEST", &expectedUnit);

    expectedUnit.name = "U_JOJO";
    expectedUnit.taille = 8;
    expectedUnit.type = LONG_Nos;
    expected = isSymbolExist("U_JOJO");
    CU_ASSERT(expected == 1);
    checkResult("U_JOJO", &expectedUnit);

    CU_ASSERT_EQUAL(add_symbol(LONG, "U_toto"),0);
    CU_ASSERT_EQUAL(add_symbol(COURT, "toto"),0);
}
