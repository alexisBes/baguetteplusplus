#include "parser_main.h"

#include <stdlib.h>
#include "lexer_main.h"
#include "StringTool.h"

/*********
 * Private function declaration
 */
void enterFunction(FILE* codeFile);
void parseMultipleVariable(const char* codeFile);

/*********
 * Public function definition
 */
void parsing(FILE *codeFile)
{

    char *token = malloc(sizeof(char));
    do
    {
        if (token != NULL) free(token);

        getNextToken(codeFile, token);
        if(feof(codeFile))
        {
            fprintf(stderr,"[ERROR] Unable to find start point");
            free(token);
            exit(EXIT_FAILURE);
        }
    } while(isIdenticalStr(token, "DEBUT"));
    enterFunction(codeFile);

}


/*********
 * Private function declaration
 */
void enterFunction(FILE* codeFile)
{
    char *nameFunction = NULL, *token = NULL;
    getNextToken(codeFile, nameFunction);
    getNextToken(codeFile, token);
    if(isIdenticalStr(token,"("))
    {
        long g = 0;
        //parseMultipleVariable();
    }
}

void parseMultipleVariable(const char * strVariableLine)
{
    //rien  pour le moment
}