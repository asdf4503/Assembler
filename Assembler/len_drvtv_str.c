#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DNUM        8

char LBUF[128];

int len_dc_oprnd_string(char* oprnd) {
    int i, len = 0;

    for (i = 1; oprnd[i] != '\"' && i <= MAX_DNUM; i++)
        len++;
    if (oprnd[i] != '\"' || !oprnd[i] || oprnd[i + 1])
        fprintf(stderr, "%s --> Operand '%s' is not valid ...\n", LBUF, oprnd), exit(11);

    return (len + 1);
}