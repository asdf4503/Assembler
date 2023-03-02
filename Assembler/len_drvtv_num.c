#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DNUM        8

char LBUF[128];

int len_dc_oprnd(char* oprnd, int unit) {
    char    buf[128], * exp;
    int     n = 0, len = 0;

    strcpy(buf, oprnd);
    exp = strtok(buf, ",");
    do {
        if (++n > MAX_DNUM)
            fprintf(stderr, "%s --> Operand '%s' is not valid ...\n", LBUF, oprnd), exit(11);

        len += unit;
    } while (exp = strtok(NULL, ","));

    return(len);
}