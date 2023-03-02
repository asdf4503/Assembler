#define MAX_OLEN        8
#define MAX_OPTAB       (sizeof(OPTAB) / sizeof(struct optab))

typedef struct optab {
    char    mnemonic[MAX_OLEN];
    unsigned char   opcode;
    unsigned char   n_operand;
} Optab;

extern Optab OPTAB[];

extern Optab* see_OPTAB(char* opc);