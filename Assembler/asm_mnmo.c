#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "optab.h"

#define MAX_DNUM        8

char    LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;
unsigned char   OBJC[MAX_DNUM * 4 + 1];

int asm_mnemonic(Optab* op) {
    unsigned char* obp = OBJC;
    unsigned int obc;
    obc = (op->opcode << 24);

    if (op->n_operand) {
        if (!OPerand) fprintf(stderr, "%s --> Operand is not defined ...\n", LBUF), exit(10);
        if (!strcmp(op->mnemonic, "DMPR"))       obc |= cal_nm_dmpr(OPerand);
        else                                    obc |= cal_nm_oprnd(OPerand);
    }

    OBJC[0] = 4;
    OBJC[1] = obc >> 24;
    OBJC[2] = obc >> 16;
    OBJC[3] = obc >> 8;
    OBJC[4] = obc >> 0;

    return(OBJC[0]);
}