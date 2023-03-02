#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symtab.h"

int SYMCNT = 1;

Symtab SYMTAB[MAX_SYM] = { "RND", RND_OPR, };

int ins_SYMTAB(int value, char* sym) {
    if (see_SYMTAB(sym) != INV_VAL)
        return 0;

    strcpy(SYMTAB[SYMCNT].symbol, sym);
    SYMTAB[SYMCNT].value = value;
    SYMCNT++;
    return 1;
}

int see_SYMTAB(char* sym) {
    int i;

    for (i = 0; i < SYMCNT; i++) {
        if (!strcmp(SYMTAB[i].symbol, sym))
            return(SYMTAB[i].value);
    }
    return INV_VAL;
}