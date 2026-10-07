//
// Created by Tomasz Dyda on 06/10/2026.
//

#ifndef COLLECTIONS_COLLECTION_H
#define COLLECTIONS_COLLECTION_H
#include <stddef.h>

typedef struct {
    void* data;
    size_t count;
    size_t capacity;
    size_t element_size;
} Collection;

void collection_init(Collection* collection, size_t element_size);
void collection_add(Collection* collection, void* data);
void collection_remove_at(Collection* collection, size_t index);
void collection_free(Collection* collection);
#endif //COLLECTIONS_COLLECTION_H
