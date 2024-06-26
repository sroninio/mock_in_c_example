#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_map.h"


void addElem(struct MyMap * map ,char * key, void * elem)
{
    int i = 0;
    for (i = 0; i < NUM_ENTRIES; i++)
    {
        if (map->entries[i].valid == 0) {break;}
    }

    strcpy(map->entries[i].key, key);
    map->entries[i].elem = elem;
    map->entries[i].valid = 1;
}


void removeElem(struct MyMap * map ,char * key)
{
    int i = 0;
    for (i = 0; i < NUM_ENTRIES; i++)
    {
        if (strcmp(map->entries[i].key, key) == 0) {break;}
    }

    map->entries[i].valid = 0;
}

void * getElem(struct MyMap * map ,char * key)
{
    int i = 0;
    for (i = 0; i < NUM_ENTRIES; i++)
    {
        if ((map->entries[i].valid == 1) && (strcmp(map->entries[i].key, key) == 0)) {break;}
    }
    if (i == NUM_ENTRIES) {return NULL;}
    return map->entries[i].elem;
}



