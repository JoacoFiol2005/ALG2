// strfuncs.c
#include <stdlib.h>
#include <stdbool.h>
#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char *string_filter(const char *str, char c) {
    size_t len = string_length(str);
    size_t new_len = 0;

    for (size_t i = 0; i < len; i++) {
        if (str[i] != c) {
            new_len++;
        }
    }

    char *filtered = malloc((new_len + 1) * sizeof(char));
    if (filtered == NULL) {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (str[i] != c) {
            filtered[j++] = str[i];
        }
    }
    filtered[j] = '\0';
    return filtered;
}

bool string_is_symmetric(const char *str) {
    size_t len = string_length(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}
