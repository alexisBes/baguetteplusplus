#ifndef CONSTANTE_LEXER_H
#define CONSTANTE_LEXER_H


#define BPP_OPERATEUR_SIZE 13
#define BPP_OPERATEUR_TABLEAU                                                     \
    {                                                                             \
        "<>", "=", "<=", ">=", "^", "*", "<-", ":", "/", "MOD", "NON", "OU", "ET" \
    }

#define BPP_DIFFERENT_KW_TYPE 7

#define BPP_DEFINITION_NB 2
#define BPP_DEFINITION_TABLEAU "CONST", "VAR"

#define BPP_TYPE_NB 4
#define BPP_TYPE_TABLEAU                          \
    {                                             \
        "ENTIER", "REEL", "CHARACTERE", "BOOLEEN" \
    }

#define BPP_TANTQUE_NB 2
#define BPP_TANTQUE_TABLEAU "TANTQUE", "FTANT"

#define BPP_JUSQUE_NB 2
#define BPP_JUSQUE_TABLEAU "JUSQUE", "FJUSQUE"

#define BPP_POUR_NB 6
#define BPP_POUR_TABLEAU "POUR", "DE", "A", "PAS", "FAIRE", "FPOUR"

#define BPP_SI_NB 4
#define BPP_SI_TABLEAU "SI", "ALORS", "SINON", "FSI"

#define BPP_SELON_NB 4
#define BPP_SELON_TABLEAU "SELON", "QUE", "VAUT", "FAIRE"

#define BPP_MOTCLE_NB BPP_DEFINITION_NB + BPP_TANTQUE_NB + BPP_JUSQUE_NB + BPP_POUR_NB + BPP_SI_NB + BPP_SELON_NB
#define BPP_MOTCLE_TABLEAU                                                                 \
    {                                                                                      \
        BPP_DEFINITION_TABLEAU, BPP_TANTQUE_TABLEAU, BPP_JUSQUE_TABLEAU, BPP_POUR_TABLEAU, \
            BPP_SI_TABLEAU, BPP_SELON_TABLEAU                                              \
    }

#define COMMENTAIRE '!'

#define FIN_INSTRUTION ';'

#endif