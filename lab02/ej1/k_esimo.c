#include <stdbool.h>
#include "k_esimo.h"

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */

int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
} 

static int quick_sort_rec(int a[], unsigned int izq, unsigned int der, unsigned int k) {
    int an, b, c , rqs= 0;
    unsigned int pivot;
    bool ret_k = false;
    bool b2 = false;
    bool b3 = false;
    if (der >= izq) {
        pivot = partition(a, izq, der);
        if (pivot == k){
            an=a[pivot];
            ret_k = true;
        } else if ( pivot < k){
            b=quick_sort_rec(a, izq, pivot -1, k);
            b2 = true;
        } else {
            c=quick_sort_rec(a, pivot+1, der, k);
            b3 = true;
        }
    }
    if (ret_k){
        rqs=an;
    }if (b2){
        rqs=b;
    }if (b3){
        rqs=c;
    }
    return rqs;
}

int quick_sort(int a[], unsigned int length, unsigned int k) {
    int rq=0;
    rq=quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, k);
    return rq;
}


int k_esimo(int a[], int length, int k) {
    bool bandera = true;
    int i = 0;
    int r = 0;
    while (i<(length-1) && !bandera){
        if (a[i] < a[i+1]){
            bandera=false;
        }
        i++;
    }

    if (!bandera){
        r=quick_sort (a, length , k);
    } 
    else {
        r=a[k];
    }
   return r;
}

