#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_DNUM        8

int     LOC;
char    LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;
unsigned char OBJC[MAX_DNUM * 4 + 1];

void put_list_head() {
    printf(" LNO  Location   Label    Opcode   Operand         Object Code\n");
    printf(" ---  --------   -----    ------   -----------     -----------\n");
}

void put_list() {
    int i;

    printf("%4s  %.7X        %-8s %-8s %-16s", LNO, LOC, LABEL, OPcode, OPerand), fflush(stdout);

    for (i = 0; i < OBJC[0]; i++)
        printf("%.2X", OBJC[i + 1]);
    printf("\n");
    OBJC[0] = 0;
}