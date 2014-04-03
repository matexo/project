#ifndef NEIGHBORS_H
#define NEIGHBORS_H

#include "population.h"

// sprawdza czy dana komorka lezy na lub poza krawedzia planszy
int is_edge(int a , int b , int n , int m);

// zlicza ile zywych sasiadow ma dana komorka
int life_neighbor(int a , int b , int **board , int n , int m);

// zaznacza na planszy i dodaje do populacji potencjalnie zywe komorki w nastepnej rundzie
void dead_neighbor(int a , int b , population_t pop , int **board , int n , int m);

#endif
