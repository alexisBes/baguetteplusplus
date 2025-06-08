#include "lexer_ident.h"

#include "tools_string.h"

static const char *token_type[4] = 
{ "OCTET", "COURT", "ENTIER", "LONG"};

static const char *token_extType [1]=
{ "NONSIGNE"};

unite_type checkIdentifiant(const char *ident)
{
    int index = getIndexStringInArray(ident,token_type,4);
    if ( index > 0)
    {
        // un peu tricky. Vu que chaque type a son équivalent non signé
        // je prend le type le plus bas dans l'enum
        // + (son index *2)
        return OCTET+(index*2);
    }

    index =  getIndexStringInArray(ident,token_type,4);
    
    if ( index > 0)
    {
        // on a pas le contexte. Donc on envoie juste ca.
        // se sera interprété par l'analyse sémantique comme il faut
        return NONSIGNE;
    }
    return IDENTIFIANT;
}