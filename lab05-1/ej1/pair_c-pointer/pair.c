#include "pair.h"
#include <stdlib.h>

pair_t pair_new(int x, int y){
    pair_t p = malloc(sizeof(struct s_pair_t));
    if (p == NULL) {
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }
    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p) {
    if (p == NULL) {
        exit(EXIT_FAILURE); // Handle null pointer access
    }
    return p->fst;
}

int pair_second(pair_t p) {
    if (p == NULL) {
        exit(EXIT_FAILURE); // Handle null pointer access
    }
    return p->snd;
}
pair_t pair_swapped(pair_t p) {
    if (p == NULL) {
        exit(EXIT_FAILURE); // Handle null pointer access
    }
    pair_t swapped = pair_new(p->snd, p->fst);
    return swapped;
}
pair_t pair_destroy(pair_t p) {
    if (p == NULL) {
        return NULL; // No action needed for null pointer
    }
    free(p);
    return NULL; // Return NULL to avoid dangling pointer
}
