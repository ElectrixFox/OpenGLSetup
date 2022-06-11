#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdio>
#include <cstdlib>

#include <string.h>

typedef struct
{
    void** assetTable;

    char typesize;
    int size;
} HashTable;

int Hash(char* key, HashTable hashTable);

int AddAsset(void* asset, char* key, HashTable hashTable);
void* GetAsset(char* key, HashTable hashTable);


#endif 
