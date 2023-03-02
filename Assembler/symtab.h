#define MAX_SYM         100
#define MAX_SLEN        (8+1)
#define INV_VAL         (-0x7fffffff)
#define RND_OPR         0x7fffff

typedef struct symtab {
    char    symbol[MAX_SLEN];
    int     value;
} Symtab;

extern  int     SYMCNT;
extern  Symtab  SYMTAB[];
extern  int     ins_SYMTAB(int value, char* sym);
extern  int     see_SYMTAB(char* sym);