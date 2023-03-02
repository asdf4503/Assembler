#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "dctab.h"

#define INV_VAL         (-0x7fffffff)
#define MAX_DNUM        8

char LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;
unsigned char   OBJC[MAX_DNUM * 4 + 1];

int asm_space(Dctab* dp) {
    int len;

    if (!OPerand) fprintf(stderr, "%s --> Operand is not defined ...\n", LBUF), exit(10);

    if (dp->type == DC_RESV) {
        /*if((!isdigit(OPerand[0]) && OPerand[strlen(OPerand) - 1] != 'h') || (len = str2int(OPerand)) == INV_VAL)
                fprintf(stderr, "%s --> Operand number '%s' is not valid ...\n", LBUF, OPerand), exit(11);*/
        len = str2int(OPerand) * dp->unit;
        OBJC[0] = 0;

        return(len);
    }
    if (dp->unit == 1 && OPerand[0] == '\"')
        len = cal_dc_oprnd_string(OPerand, OBJC);
    else    len = cal_dc_oprnd(OPerand, dp->unit, OBJC);

    return (len);
}