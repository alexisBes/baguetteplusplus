#include "parser_main.h"

#include <stdlib.h>
#include "lexer_main.h"
#include "tools_string.h"
#include "tools_tree.h"
#include "token_utils.h"

typedef Tree Tree_Instruction;

void handleInstruction(const char* idToken,FILE *codeFile);
char handle_Identifier(const char* idToken);
void handle_Mathematical(FILE *codeFile, Tree_Instruction *instructionTree);


void parsing(FILE *codeFile)
{

    char * firstToken =NULL;
    unsigned char isEndInstruction = getNextToken(codeFile,firstToken);
    if(isEndInstruction)
    {
        fprintf(stderr,"[ERREUR] Pas de caractere a lire \n");
        exit(1);
    }
    // Ici on ajoutera la vérification du type (declaration, boucle,etc...)
    if(firstToken)
    {
        // si c'est une instruction
        handleInstruction(firstToken,codeFile);
        free(firstToken);
    }
}

void handleInstruction(const char* idToken,FILE *codeFile)
{
    char* instructionToken = NULL;
    if(getNextToken(codeFile,instructionToken))
    {
        fprintf(stderr, "[WARNING] Instruction vide.\n");
        return;
    }
    unsigned char isValid_S = handle_Identifier(idToken);
    if (instructionToken == "<-" && isValid_S)
    {
        Tree_Instruction *instructionTree = createTree(instructionToken);
        addItem(instructionTree,idToken,1);
        handle_Mathematical(codeFile, instructionTree);
    }
}

void handle_Mathematical(FILE* codeFile, Tree_Instruction *instructionTree)
{
    char* allTokens[3] = {"","",""};
    
}