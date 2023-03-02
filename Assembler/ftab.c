#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FNAME       8
#define MAX_FTAB        4
#define INV_VAL         (-0x7fffffff)

typedef struct ftab {
    char    fname[MAX_FNAME + 1];
    int     port;
    char    in_out;
}Ftab;

char    LBUF[128], * OPerand;

void ins_FTAB(), see_FTAB(), put_obj_ftab();

int     FCNT;
Ftab    FTAB[MAX_FTAB];
FILE* Ofp;

void ins_FTAB() {
    char* pn, * io, * fn;
    int     port;

    if (!(pn = strtok(OPerand, ",")) || !(io = strtok(NULL, ",")) || !(fn = strtok(NULL, " \t\n\r")))
        fprintf(stderr, "\n%s --> FILE operand is not valid ...\n", LBUF), exit(31);

    see_FTAB(fn);

    if ((port = str2int(pn)) == INV_VAL || port < 0)
        fprintf(stderr, "\n%s --> Port type('I' or 'O') is not defined ...\n", LBUF), exit(31);

    if (strcmp(io, "I") && strcmp(io, "O"))
        fprintf(stderr, "\n%s --> Port type('I' or 'O') is not defined ...\n", LBUF), exit(31);

    strcpy(FTAB[FCNT].fname, fn);
    FTAB[FCNT].port = port;
    FTAB[FCNT++].in_out = *io;
}

void see_FTAB(char* fname) {
    int     i;
    for (i = 0; i < FCNT; i++)
        if (!strcmp(FTAB[i].fname, fname))
            fprintf(stderr, "File name '%s' is duplicated ..\n", fname);
}

void put_obj_ftab() {
    int     i;
    for (i = 0; i < FCNT; i++)
        fprintf(Ofp, "F:%s:%c:%.6X\n", FTAB[i].fname, FTAB[i].in_out, FTAB[i].port);
}