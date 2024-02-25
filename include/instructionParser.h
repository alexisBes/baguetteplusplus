#ifndef INSTRCUTION_PARSER_H
#define INSTRCUTION_PARSER_H
#include "storage.h"

int checkDeclarationInstruction(Node *ligne, Node *allVariable, int numLigne);

int checkPourInstruction(Node *ligne, Node *allVariables, int numLigne);

int checkTantQueInstruction(Node *ligne, Node *allVariables, int numLigne);

int checkJusqueInstruction(Node *ligne, Node *allVariables, int numLigne);

int checkSiInstruction(Node *ligne, Node *allVariables, int numLigne);

int checkSelonInstruction(Node *ligne, Node *allVariables, int numLigne);

int checkSampleInstruction(Node *ligne, Node *allVariables, int numLigne);
#endif