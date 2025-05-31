#include "flag_sort.h"
#include "assert.h"

void flag_sort ( Color a[], unsigned int length){
    unsigned int i = 0 , j = 0;
    unsigned int k = length - 1;
    assert (0 <= i <= j <= k < length);
    while (j <= k){
        if (a[j] == RED ){
            swap (a,i,j);
            i = i + 1;
            j = j + 1;
        }
        else if (a[j] == BLUE){
            swap (a,j,k);
            k = k - 1;
        }
        else {
            j++;
        }
    }
}
