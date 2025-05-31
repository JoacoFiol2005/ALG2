#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

//ej 1 Insertion Sort
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

//ej 2 Quick Sort I
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

//ej 3 Quick Sort II: Partition
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i = izq + 1;
    unsigned int j = der;
    int pivot = a[izq];

    printf("Antes de partition: izq=%u der=%u\n", izq, der);
    array_dump(a, der + 1);  

    while (i <= j) {
        if (goes_before(a[i], pivot)) {
            i++;
        } else if (goes_before(pivot, a[j])) {
            j--;
        } else {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, izq, j);

    printf("Después de partition: pivot=%d en pos=%u\n", pivot, j);
    array_dump(a, der + 1);  

    return j;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    int pivot = partition ( a , der , izq);
    if ( der > izq ) {
        quick_sort_rec (a , izq , (pivot-1));
        quick_sort_rec (a , pivot + 1 , der );
    }
}

void quick_sort(int a[], unsigned int length) {
    if (length > 0) {
        quick_sort_rec(a, 0, length - 1);
    }
}
