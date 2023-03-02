#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"optab.h"
#include"dctab.h"
#include"symtab.h"

#define MAX_DNUM        8

int             LOC = 0, LDaddr, GOaddr, PGsize;
char            LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;
unsigned        char OBJC[MAX_DNUM * 4 + 1];

void Pass_1(char* sflie);

void TwoPassAssemble(char* sflie) {
    Pass_1(sflie);
    Pass_2(sflie);
}

int main(int ac, char* av[]) {
    TwoPassAssemble(av[1]);

    return 0;
}

void Pass_1(char* sfile) {
    FILE* fp;
    Optab* op;
    Dctab* dp;
    int     len;

    if (!(fp = fopen(sfile, "r")))
        fprintf(stderr, "FIile '%s' not found...\n", sfile), exit(1);
    read_line(fp);

    if (!OPcode || strcmp(OPcode, "START"))
        fprintf(stderr, "\n%s --> Start address is invalid ...\n", LBUF), exit(2);

    if (OPerand && (LOC = str2int(OPerand)) < 0)
        fprintf(stderr, "\n%s --> Start address is invalid ...\n", LBUF), exit(3);

    if (!LABEL) LABEL = "ASMBLY";
    ins_SYMTAB(LOC, LABEL);

    LDaddr = GOaddr = LOC;

    while (read_line(fp) >= 0) {
        if (!strcmp(OPcode, "END"))      break;

        if (!strcmp(OPcode, "FILE")) { ins_FTAB();  continue; }

        if (LABEL) {
            if (strlen(LABEL) > MAX_SYM)
                fprintf(stderr, "\n%s --> Symbol '%s' is too long ...\n", LBUF, LABEL), exit(4);

            if (!ins_SYMTAB(LOC, LABEL))
                fprintf(stderr, "\n%s --> Symbol '%s' is duplicated ...\n", LBUF, LABEL), exit(4);
        }
        if (op = see_OPTAB(OPcode))
            len = len_mnemonic(op);
        else if (dp = see_DCTAB(OPcode))
            len = len_space(dp);
        else fprintf(stderr, "\n%s --> Opcode '%s' is not valid ...\n", LBUF, OPcode), exit(4);

        LOC += len;
    }
    if (!OPcode)     fprintf(stderr, " --> 'END' opcode is not defined ...\n", LBUF, OPcode), exit(5);
    if (OPerand)     GOaddr = cal_nm_oprnd(OPerand);
    PGsize = LOC - LDaddr;
    fclose(fp);
}