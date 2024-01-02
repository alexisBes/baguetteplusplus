#ifndef CONSTANTE_LEXER_H
#define CONSTANTE_LEXER_H

#define BPP_OPERATEUR_SIZE 12
#define BPP_OPERATEUR_TABLEAU {"<>", "=", "<=", ">=", "^", "*","<-","/", "MOD","NON", "OU", "ET"}


#define BPP_MOTCLE 18
#define BPP_MOTCLE_TABLEAU { "CONST", "VAR", \
    "TANTQUE", "FTANT", \
     "JUSQUE", "FJUSQUE", \
     "POUR", "DE","A", "PAS", "FAIRE", "FPOUR" \
     "SI", "ALORS", "SINON", "FSI", \
     "SELON", "QUE", "FAIRE"}

#define  COMMENTAIRE  '!';

#define DELIM_CHAR_NB 10
#define DELIM_CHAR_TABLEAU "<- =/*+-\t";

#endif