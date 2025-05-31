#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


void swap ( int *a, int *b){
    int  aux = *a;
    *a = *b;
    *b = aux;
} 

int main(void){
    int x = 6, y = 4; 
    printf("x = %d y y = %d\n", x , y);
    swap ( &x , &y);
    printf("x = %d y y = %d\n", x , y);
}