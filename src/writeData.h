typedef struct spEntryNew {
    unsigned int crc;

    unsigned short room;
    unsigned short interaction_index;

    unsigned short cueindex;
    unsigned short subcue;

    unsigned short byguybrush;
    unsigned short unk1;

    char en[256];
    char fr[256];
    char it[256];
    char de[256];
    char es[256];
    char sk[256];

    char file[32];
} spEntryNew;

typedef struct uiEntryNew {
    char file[256];

    char en[256];
    char fr[256];
    char it[256];
    char de[256];
    char es[256];
    char sk[256];

} uiEntryNew;

int initialBufferUI(uiEntryNew *p_block);
int initialBufferSP(spEntryNew *p_block);
int writeData(char *f_read);
