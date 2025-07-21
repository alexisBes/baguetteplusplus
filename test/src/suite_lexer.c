#include "suite_lexer.h"
#include "lexer_main.h"
#include <CUnit/CUnit.h>
#include "stdlib.h"
#include "stdio.h"

int Init_Lexer()
{
    return 0;
}

int Clean_Lexer()
{
    remove("./TEST.bpp");
    return 0;
}

static void InitForEachTest(const char *content)
{
    FILE *file = fopen("TEST.bpp", "w");

    if (fputs(content, file) == EOF)
    {
        perror("Failed to write to file");
        fclose(file);
        exit(1);
    }
    fclose(file);
    initLexer("TEST.bpp");
}

static void verif_Unite(const unite_type expected_type, const char *expected_param)
{
    char *param = NULL;
    unite_type unite;
    getNextToken(&unite, &param);
    CU_ASSERT_EQUAL(unite, expected_type);
    if (param != NULL)
    {
        if(expected_param ==NULL)
        {
            free(param);
            CU_FAIL();
        }
        CU_ASSERT_STRING_EQUAL(param, expected_param);

        free(param);
    }
    else
    {
        if (expected_param != NULL)
            CU_FAIL()
    }
}

#define CONTENT_RETRIEVE_IDENT "TOto TaTa\tTiTI\netrusque\r\ntruc \
45678 12345\t78964\n12345689\r\n4523145 \
; + - * / "

void test_RetrieveIdent()
{
    InitForEachTest(CONTENT_RETRIEVE_IDENT);
    char *param = NULL;
    unite_type unite;
    // TEST DE RÉCUPÉRATION DES IDENTIFIANTS
    verif_Unite(IDENTIFIANT, "TOto");

    // test apres un espace
    verif_Unite(IDENTIFIANT, "TaTa");

    // test apres une tabulation
    verif_Unite(IDENTIFIANT, "TiTI");

    // test apres un retour a la ligne
    verif_Unite(IDENTIFIANT, "etrusque");

    // test apres un retour a la ligne windows
    verif_Unite(IDENTIFIANT, "truc");

    // TEST DE RÉCUPÉRATION DES NOMBRE
    verif_Unite(NOMBRE, "45678");

    // test apres un espace
    verif_Unite(NOMBRE, "12345");

    // test apres une tabulation
    verif_Unite(NOMBRE, "78964");

    // test apres un retour a la ligne
    verif_Unite(NOMBRE, "12345689");

    // test apres un retour a la ligne windows
    verif_Unite(NOMBRE, "4523145");

    do
    {
        getNextToken(&unite, &param);
        CU_ASSERT_NOT_EQUAL(unite, IDENTIFIANT);
        CU_ASSERT_NOT_EQUAL(unite, NOMBRE);

        CU_ASSERT_EQUAL(param, NULL);
    } while (unite != UNITE_LEXICAL_COUNT);
    closeLexer();
}

#define CONTENT_RETRIEVE_MATH "+ /\t*\n-\r\n/ \
TOO la can OCTET 12345 "
void test_RetrieveMathOperation()
{
    InitForEachTest(CONTENT_RETRIEVE_MATH);
    verif_Unite(ADDITION, NULL);
    verif_Unite(DIVISION, NULL);
    verif_Unite(MULTIPLICATION, NULL);
    verif_Unite(SOUSTRACTION, NULL);
    verif_Unite(DIVISION, NULL);

    char *param = NULL;
    unite_type unite;
    do
    {
        getNextToken(&unite, &param);
        CU_ASSERT_TRUE(unite < ADDITION || unite >DIVISION );

        if(param != NULL)
        {
            free(param);
            param = NULL;
        }
    } while (unite != UNITE_LEXICAL_COUNT);

    closeLexer();
}
#define CONTENT_RETRIEVE_TYPE "OCTET COURT\tLONG\nENTIER\r\nNONSIGNE \
TOO la can 12345 "
void test_RetrieveType()
{
    InitForEachTest(CONTENT_RETRIEVE_TYPE);
    verif_Unite(OCTET, NULL);
    verif_Unite(COURT, NULL);
    verif_Unite(LONG, NULL);
    verif_Unite(ENTIER, NULL);
    verif_Unite(NONSIGNE, NULL);

    char *param = NULL;
    unite_type unite;
    do
    {
        getNextToken(&unite, &param);
        CU_ASSERT(unite< NONSIGNE || LONG_Nos < unite);
        if(param != NULL)
        {
            free(param);
            param = NULL;
        }
    } while (unite != UNITE_LEXICAL_COUNT);

    closeLexer();
}

#define CONTENT_RETRIEVE_OPERATION "<- <-\t<-\n<-\r\n<- \
TOO la can 12345 "
void test_RetrieveOperation()
{
    InitForEachTest(CONTENT_RETRIEVE_OPERATION);
    verif_Unite(AFFECTATION, NULL);
    verif_Unite(AFFECTATION, NULL);
    verif_Unite(AFFECTATION, NULL);
    verif_Unite(AFFECTATION, NULL);
    verif_Unite(AFFECTATION, NULL);

    char *param = NULL;
    unite_type unite;
    do
    {
        getNextToken(&unite, &param);
        CU_ASSERT_NOT_EQUAL(unite, AFFECTATION);
        if(param != NULL)
        {
            free(param);
            param = NULL;
        }
    } while (unite != UNITE_LEXICAL_COUNT);

    closeLexer();

}
