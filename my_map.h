#define MAX_STR (100)
#define NUM_ENTRIES (100)

struct MyMapEntry
{
    char key[MAX_STR];
    void * elem;
    int valid;
};

struct MyMap
{
    struct MyMapEntry entries[NUM_ENTRIES];
};

void addElem(struct MyMap * map ,char * key, void * elem);
void removeElem(struct MyMap * map ,char * key);
void * getElem(struct MyMap * map ,char * key);
