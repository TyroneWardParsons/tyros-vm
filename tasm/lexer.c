/* TASM */
/* lexer.h */
#include "lexer.h"

void tasm_lex(FILE* fp) 
{
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
}
