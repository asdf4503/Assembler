#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "optab.h"
#include "dctab.h"

#define MAX_DNUM        8

int     LOC, LDaddr, GOaddr, PGsize;
char    LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;
unsigned char OBJC[MAX_DNUM * 4 + 1];
char* null_LNO = "";
char* null_LBL = "";
char* null_OPR = "";

void Pass_2(char* sfile) {
    FILE* fp;
    Optab* op;
    Dctab* dp;
    int     len;
    int     i;

    fp = fopen(sfile, "r");
    printf("\n");
    put_list_head();
    read_line(fp);
    if (!LABEL)      LABEL = "ASMBLY";
    put_obj_head(sfile, LABEL, LDaddr, PGsize);
    put_obj_ftab();
    if (!LNO)        LNO = null_LNO;
    if (!OPerand)    OPerand = null_OPR;
    LOC = LDaddr;
    put_list();
    while ((i = read_line(fp)) >= 0) {
        if (!strcmp(OPcode, "END"))
            break;
        if (!strcmp(OPcode, "FILE")) {
            if (!LNO)        LNO = null_LNO;
            if (!LABEL)      LABEL = null_LBL;
            if (!OPerand)    OPerand = null_OPR;
            if (i == 0)      printf("\n");
            put_list();
            continue;
        }

        if (op = see_OPTAB(OPcode)) {
            len = asm_mnemonic(op);
            put_obj_text(LOC, OBJC);
        }
        else {
            dp = see_DCTAB(OPcode);
            len = asm_space(dp);
            put_obj_data(LOC, OBJC);
        }
        if (!OPerand)
            OPerand = null_OPR;
        if (!LNO)
            LNO = null_LNO;
        if (!LABEL)
            LABEL = null_LBL;
        if (i == 0)      printf("\n");
        put_list();
        LOC += len;
    }
    if (!OPerand)
        OPerand = null_OPR;
    LABEL = null_LBL;
    put_obj_end(GOaddr);
    if (!LNO) LNO = null_LNO;
    put_list();
    printf("\n");
    fclose(fp);
}