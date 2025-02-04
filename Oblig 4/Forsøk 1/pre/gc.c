#include <assert.h>
#include <stdlib.h>
#include "gc.h"
//denne koden er tatt fra CHATUIT som du kan finne fram i CHATLOGS folderen


/*
 *      This reference counting garbage collector works by simply storing a
 *      reference count next to the allocated memory in the following way:
 *
 *          [reference count][allocated memory]
 *
 *      When it gets a call to gc_malloc it simply allocates the give size plus
 *      sizeof(int), and whenever it gets a call to gc_register or gc_free it
 *      shifts the address over by the size of an int to inspect the reference
 *      count.
 *
 */

// Allocates a contiguous piece of garbage-collected memory of a certain size
void *gc_malloc(size_t size) {
    void *allocated = malloc(size + sizeof(int));
    if (allocated == NULL) {
        return NULL; // Handle malloc failure
    }

    *(int *)allocated = 1; // Initialize reference count to 1

    return (char *)allocated + sizeof(int); // Return a pointer to the memory area, skipping the reference count
}

// Registers use of a certain piece of memory. IE takes a pointer to an
// already-allocated piece of memory and increments the reference counter for
// this memory.
void gc_register(void *address) {
    if (address == NULL) {
        return; // Handle null pointer
    }

    int *reference_count = (int *)((char *)address - sizeof(int)); // Get the address of the reference count
    assert(*reference_count > 0); // Ensure it's valid to increment

    (*reference_count)++; // Increment the reference count
}

// Unregisters use of the memory pointed to by ptr. If the reference counter is
// zero at this point the memory can be safely freed, otherwise it must be kept
// intact.
void gc_free(void *address) {
    if (address == NULL) {
        return; // Handle null pointer
    }

    int *reference_count = (int *)((char *)address - sizeof(int)); // Get the address of the reference count
    assert(*reference_count > 0); // Ensure it's valid to decrement

    (*reference_count)--; // Decrement the reference count

    if (*reference_count == 0) {
        free(reference_count); // Free the block if reference count reaches zero
    }
}