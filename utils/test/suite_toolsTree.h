#ifndef SUITE_TOOLS_TREE_H
#define SUITE_TOOLS_TREE_H


// test sur la création et destruction
/**
 * Initialisation de la partie création d'arbre (vide)
 */
int Init_ToolsTree_CreateDestruct();
int Clean_ToolsTree_CreateDestruct();

void test_CreateTree_const();
void test_CreateTree_struct();
void test_CreateTree_pointer();

// test d'ajout et de récupération de valeur
/**
 * Initialisation de la partie ajout d'item initiialise un arbre
 */
int Init_ToolsTree();
int Clean_ToolsTree();
void test_AddItemG();
void test_AddItemD();
void test_AddItemGG();
void test_AddItemDD();



#endif