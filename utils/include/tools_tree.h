#ifndef TREE_UTILS_H
#define TREE_UTILS_H

#include "bpp_types.h"

typedef struct s_Tree Tree;
/**
 * Structure enumére comportant un noeud de l'arbre
 */
struct s_Tree
{
    Tree *lNode; /** Le noeud gauche enfant */
    Tree *rNode; /** le noeud droit enfant */
    unite_instruction *content; /** le contenue du noeud. pensé pour etre une unité instruction */
};

/**
 * @name createTree
 * @brief Permet d'initialiser un arbre binaire
 * @param content le contenue du noeud. La mémoire est copié. Pensez a bien libérer le contenue apres la fonction
 *  @return un pointeur vers la racine de l'arbre
 */
Tree *createTree(unite_instruction *content);


/**
 * @name clearTree
 * @brief Permet de supprimer et libérer la mémoire de l'arbre
 * @param tree le pointeur vers la racine de l'arbre.
 */
void clearTree(Tree *tree);

/**
 * @name addItem
 * @brief Permet d'ajouter un noeud enfant a l'arbre binaire
 * @param tree le pointeur vers l'element parent du future noeud.
 * @param content le contenue vers le noeud. La mémoire est copié. Pensez a bien libérer le contenue apres la fonction.
 * @param isLeft 1 si le noeud doit se trouver sur l'enfant gauche. 0 sinon 
 */
char addItem(Tree *tree,unite_instruction *content,const char isLeft);


/**
 * @name addParent
 * @brief Permet de remplacer le noeud courant par le contenue et déplacer le noeud courant vers un enfant
 * @param tree le pointeur vers l'element courant du noeud.
 * @param content le contenue vers le noeud. La mémoire est copié. Pensez a bien libérer le contenue apres la fonction.
 * @param isLeft 1 si le noeud doit se trouver sur l'enfant gauche. 0 sinon 
 */
char addParent(Tree *tree, unite_instruction *content, const char isLeft);


/**
 * @name printTree
 * @brief Permet d'afficher un arbre
 * @param tree le pointeur vers l'arbre a afficher.
 */
void printTree(Tree *tree);
#endif