#ifndef CONSTANTE_LEXER_H
#define CONSTANTE_LEXER_H

#define BPP_OPERATEUR_SIZE 12
const char *bppOperateur[] = {"<>", "=", "<=", ">=", "^", "*","<-","/", "MOD","NON", "OU", "ET"};

#define BPP_MOTCLE 18
const char *bppMotsCle[] = { "CONST", "VAR", 
    "TANTQUE", "FTANT",
     "JUSQUE", "FJUSQUE", 
     "POUR", "DE","A", "PAS", "FAIRE", "FPOUR"
     "SI", "ALORS", "SINON", "FSI",
     "SELON", "QUE", "FAIRE"};

const char comment  ='!';

#endif