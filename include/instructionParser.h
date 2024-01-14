#ifndef INSTRCUTION_PARSER_H
#define INSTRCUTION_PARSER_H
#include "storage.h"

int checkDeclarationInstruction(Node *ligne, Node *allVariable);

int checkPourInstruction(Node *ligne, Node *allVariables);

int checkTantQueInstruction(Node *ligne, Node *allVariables);

int checkJusqueInstruction(Node *ligne, Node *allVariables);

int checkSiInstruction(Node *ligne, Node *allVariables);

int checkSelonInstruction(Node *ligne, Node *allVariables);

int checkSampleInstruction(Node *ligne, Node *allVariables);
#endif