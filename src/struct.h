typedef struct spEntry {
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

    char file[32];
} spEntry;

typedef struct uiEntry {
    char file[256];

    char en[256];
    char fr[256];
    char it[256];
    char de[256];
    char es[256];

} uiEntry;
