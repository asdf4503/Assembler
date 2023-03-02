#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INV_VAL         (-0x7fffffff)

char    LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;

int cnv_one_term(char* term) {
    int val;
    if (isdigit(term[0]) || term[strlen(term) - 1] == 'h') {
        if ((val = str2int(term)) == INV_VAL)
            fprintf(stderr, "%s --> Operand number '%s' is not valid ...\n", LBUF, term), exit(11);
    }
    else if (term[0] == '\'') {
        if ((val = asc2int(term)) == INV_VAL)
            fprintf(stderr, "%s --> Operand number '%s' is not valid ...\n", LBUF, term), exit(11);
    }
    else {
        if ((val = see_SYMTAB(term)) == INV_VAL)
            fprintf(stderr, "%s --> Operand number '%s' is not defined ...\n", LBUF, term), exit(12);
    }
    return(val);
}