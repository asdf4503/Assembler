#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dctab.h"

#define INV_VAL         (-0x7fffffff)

char    LBUF[128], * OPerand;

int len_space(Dctab* dp) {
    int len;
    if (!OPerand) fprintf(stderr, "%s --> Operand is not defined ...\n", LBUF), exit(10);

    if (dp->type == DC_RESV) {
        if ((!isdigit(OPerand[0]) && OPerand[strlen(OPerand) - 1] != 'h') || (len = str2int(OPerand)) == INV_VAL)
            fprintf(stderr, "%s --> Operand number '%s' is not valid ...\n", LBUF, OPerand), exit(11);
        len *= dp->unit;
        return(len);
    }
    if (dp->unit == 1 && OPerand[0] == '\"')
        len = len_dc_oprnd_string(OPerand);
    else
        len = len_dc_oprnd(OPerand, dp->unit);
    return len;
}