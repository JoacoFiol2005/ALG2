#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    if (c == NULL) {
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }
    c->count = 0; // Initialize the count to zero
    return c;
}

void counter_inc(counter c) {
    if (c == NULL) {
        exit(EXIT_FAILURE); // Handle null pointer access
    }
    c->count++; // Increment the count
}

bool counter_is_init(counter c) {
    if (c == NULL) {
        return false; // Return false if the counter is not initialized
    }
    return c->count > 0; // Return true if count is greater than zero
}

void counter_dec(counter c) {
    if (c == NULL) {
        exit(EXIT_FAILURE); // Handle null pointer access
    }
    if (c->count > 0) {
        c->count--; // Decrement the count only if it's greater than zero
    } else {
        exit(EXIT_FAILURE); // Handle underflow condition
    }
}

counter counter_copy(counter c) {
    if (c == NULL) {
        exit(EXIT_FAILURE); // Handle null pointer access
    }
    counter new_counter = malloc(sizeof(struct _counter));
    if (new_counter == NULL) {
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }
    new_counter->count = c->count; // Copy the count value
    return new_counter;
}

void counter_destroy(counter c) {
    if (c == NULL) {
        return; // No action needed for null pointer
    }
    free(c); // Free the allocated memory for the counter
    c = NULL; // Set to NULL to avoid dangling pointer
}
