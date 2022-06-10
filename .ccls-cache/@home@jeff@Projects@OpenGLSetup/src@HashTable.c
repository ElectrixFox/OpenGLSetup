#include "HashTable.h"

int Hash(char* key, HashTable hashTable)
{
    int hKey = strlen(key);

    return hKey;
}

int AddAsset(void* asset, char* key, HashTable hashTable)
{
    int hKey = Hash(key, hashTable);
    memcpy(hashTable.assetTable[hKey], asset, hashTable.typesize);

    return 1;
}

void* GetAsset(char* key, HashTable hashTable)
{
    void* asset = malloc(sizeof(hashTable.typesize));
    int hKey = Hash(key, hashTable);
    memcpy(asset, hashTable.assetTable[hKey], hashTable.typesize);

    return asset;
}
