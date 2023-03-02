#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dctab.h"

Dctab DCTAB[] = {
        "DD", DC_CNST, DC_DW,   "DW", DC_CNST, DC_WD,   "DB", DC_CNST, DC_BT,
        "RD", DC_RESV, DC_DW,   "RW", DC_RESV, DC_WD,   "RB", DC_RESV, DC_BT
};

Dctab* see_DCTAB(char* dcc) {
    int i;
    for (i = 0; i < MAX_DCTAB; i++) {
        if (!strcmp(DCTAB[i].directive, dcc))
            return (&DCTAB[i]);
    }
    return NULL;
}