#ifndef _FLAG_SORT_H_
#define _FLAG_SORT_H_

typedef enum {
    RED,
    WHITE,
    BLUE
} Color;

/* Intercambia los elementos en las posiciones i y j del arreglo */
void swap(Color a[], unsigned int i, unsigned int j);

/* Ordena el arreglo según el orden: RED, WHITE, BLUE */
void flag_sort(Color a[], unsigned int length);

#endif // _FLAG_SORT_H_
