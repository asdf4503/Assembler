#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char    LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;

int read_line(FILE* fp) {
    static  char buf[128];
    char* cp;
    int     count = 0;

    LNO = NULL, LABEL = NULL, OPcode = NULL, OPerand = NULL;
    do {
        if (!fgets(buf, sizeof(buf), fp)) return -1;
        strcpy(LBUF, buf); LBUF[strlen(LBUF) - 1] = 0;
        if (cp = strstr(buf, "//")) *cp = 0;
        if (cp = strstr(buf, "\n")) count++;
    } while (!(cp = strtok(buf, " \t\n\r")));

    if (isdigit(*cp)) {
        LNO = cp;
        cp = strtok(NULL, " \t\n\r");
    }
    if (strcmp(cp, "END") && strcmp(cp, "START") && strcmp(cp, "FILE") && !see_OPTAB(cp) && !see_DCTAB(cp)) {
        LABEL = cp;
        cp = strtok(NULL, " \t\n\r");
    }
    OPcode = cp;
    OPerand = strtok(NULL, " \t\n\r");
    if (count >= 2) return 0;
    return 1;
}