#ifndef IMAGE_H
#define IMAGE_H

#include <allegro.h>
#include "population.h"

// tworzy obraz 8 razy wiekszy niz rzeczywista plansza w celu zwiekszenia jakosci
void make_image(population_t pop , int n , int m , char name[]);

#endif
