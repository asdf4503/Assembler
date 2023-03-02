#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DNUM        8
char LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;

int cal_dc_oprnd(char* oprnd, int unit, unsigned char obj[]) {
    char    buf[128], * exp;
    char* op = (char*)(obj + 1);
    short* sp = (short*)(obj + 1);
    int* ip = (int*)(obj + 1);
    int     n = 0, v, len = 0;

    strcpy(buf, oprnd);
    exp = strtok(buf, ",");
    do {
        /*if(++n > MAX_DNUM)
                fprintf(stderr, "%s --> Operand '%s' is not valid ...\n", LBUF, oprnd), exit(11);*/

        v = cal_one_expr(exp);
        switch (unit) {
        case 4: *op = v >> 24; op++; len++;
            *op = v >> 16; op++; len++;
        case 2: *op = v >> 8; op++; len++;
        case 1: *op = v;       op++; len++;
        }
    } while (exp = strtok(NULL, ","));
    obj[0] = len;
    return(len);
}

int cal_dc_oprnd_string(char* oprnd, unsigned char obj[]) {
    int i;

    for (i = 1; oprnd[i] != '\"'; i++)
        obj[i] = oprnd[i];
    obj[i] = '\0'; obj[0] = i;
    return(i);
}