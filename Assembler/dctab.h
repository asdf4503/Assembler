#define MAX_DLEN        8
#define MAX_DCTAB       (sizeof(DCTAB) / sizeof(struct dctab))

typedef struct dctab {
    char    directive[MAX_DLEN];
    char    type;

#define DC_CNST         0
#define DC_RESV         1
    char unit;
#define DC_DW           4
#define DC_WD           2
#define DC_BT           1
} Dctab;

extern Dctab    DCTAB[];
extern Dctab* see_DCTAB(char* dcc);