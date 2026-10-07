//
// Created by Tomasz Dyda on 06/10/2026.
//

#include "collection.h"

#include <stdlib.h>
#include <string.h>

void collection_init(Collection *collection, size_t element_size) {
    collection->data = NULL;
    collection->count = 0;
    collection->capacity = 0;
    collection->element_size = element_size;
}
void collection_add(Collection *collection, void *value) {
    void *temp = realloc(collection->data, (collection->capacity + 1) * collection->element_size);

    if (temp == NULL) {
        return;
    }

    collection->data = temp;

    memcpy(
        (char*)collection->data + collection->capacity * collection->element_size,
        value,
        collection->element_size
    );

    collection->capacity++;
    collection->count++;
}
void collection_remove_at(Collection *collection, size_t index) {
    memmove(
        (char*)collection->data + index * collection->element_size,
        (char*)collection->data + (index + 1) * collection->element_size,
        (collection->count - index - 1) * collection->element_size
    );

    void* temp = realloc(collection->data, (collection->capacity - 1) * collection->element_size);
    if (temp == NULL) {
        return;
    }
    collection->data = temp;
    collection->count--;
    collection->capacity--;
}
void collection_free(Collection *collection) {
    free(collection->data);
    collection->data = NULL;
}