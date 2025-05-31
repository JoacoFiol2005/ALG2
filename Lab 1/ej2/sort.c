#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int array[], unsigned int left, unsigned int right) {
    assert(left >= right);
    unsigned int pivot = partition(array, left, right);
    if (pivot > 0) { 
        quick_sort_rec(array, left, pivot - 1);
    }
    quick_sort_rec(array, pivot + 1, right);
}

void quick_sort(int array[], unsigned int length) {
    if (length > 0) {
        quick_sort_rec(array, 0, length - 1);
    }
}