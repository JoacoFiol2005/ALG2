#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int array[], unsigned int i) {
    int key = array[i];
    int j = i - 1;

    while (j >= 0 && !goes_before(array[j], key)) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = key;
    array_dump(array, i + 1);  
}

    void insertion_sort(int array[], unsigned int length) {
        for (unsigned int i = 1; i < length; i++) {
            insert(array, i);
            assert(array_is_sorted(array, i + 1)); 
        }
    }