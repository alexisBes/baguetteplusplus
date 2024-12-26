#include "token_utils.h"
#include "StringTool.h"
#include "enum.h"

#define _BPP_MATH_INSTRUCTION_ "+-/*"
#define _BPP_AFFECTATION_INSTRUCTION_ "<-"

int handleNumber(char *token);

int checkTypeToken(char *token)
{
    size_t length_token = strlen(token);
    if (isIdenticalStr(token, _BPP_AFFECTATION_INSTRUCTION_))
        return OPERATEUR;

    if (token >= '0' && token <= '9')
    {
        if (isNumeric(token))
        {
            return NOMBRE;
        }
        else
        {
            printf("[ERREUR] une variable ne peut pas commencer par un caractere non alphabétique.\n");
            return INSTRUCTION_BASIQUE_COUNT;
        }
    }
    unsigned char isMathInstruction = isCharExistInArray(token[0], _BPP_MATH_INSTRUCTION_, 5);
    if (isMathInstruction && length_token == 1)
    {
        return INSTRUCTION_MATH;
    }
    else
    {
        if (isMathInstruction)
        {
            printf("[ERREUR] une variable ne peut pas commencer par un des caracteres suivant : %s\n", _BPP_MATH_INSTRUCTION_);
            return INSTRUCTION_BASIQUE_COUNT;
        }

        // TODO: chack variable has been defined
        return VARIABLE;
    }
}