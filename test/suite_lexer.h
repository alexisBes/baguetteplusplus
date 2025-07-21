#ifndef SUITE_LEXER_H
#define SUITE_LEXER_H

int Init_Lexer();
int Clean_Lexer();

void test_RetrieveIdent();
void test_RetrieveMathOperation();
void test_RetrieveType();
void test_RetrieveOperation();

#endif