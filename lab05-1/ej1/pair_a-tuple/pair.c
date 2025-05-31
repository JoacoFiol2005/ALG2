#include "pair.h"

pair_t new( int x , int y){
    pair_t p;
    p.fst = x;
    p.snd = y;
    return p;
}

void destroy (pair_t p){
    return p;
}

int first (pair_t p){
    return p.fst;
}

int second (pair_t p){
    return p.snd;
}

pair_t swapped (pair_t p){
    return new(p.fst , p.snd);
}