#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"
#define FIXTRING_MAX 100

unsigned int fstring_length(fixstring s) {
    int contador = 0;
   while (contador < FIXSTRING_MAX && s[contador] != '/0' ){
    contador ++;
    }
    return contador; 
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool bandera = true;
    for (int i = 0; i < FIXSTRING_MAX; i++) {
        if (s1[i] != s2[i]) {
            bandera = false;
        }
        if (s1[i]== '/0'){
        bandera = true;
    }
}
    return bandera; 
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool bandera_menor = false;
    bool bandera = true; 
    for (int i = 0; i < FIXTRING_MAX && bandera && bandera_menor; i++){
        if (s1[i] > s2[i]){
            bandera = false;
        } else if (s1[i] <= s2[i]){
            bandera_menor = true;
        }
        if (s1[i] == '\0') { 
            return true;
        }
    }
    return bandera;
}

