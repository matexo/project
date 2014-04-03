#ifndef LIFEGAME_H
#define LIFEGAME_H

#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"
#include "population.h"
#include "inout.h"
#include "rules.h"
#include "image.h"

void life(char namein[] , char nameout[] , int hei , int wit , int n , int f , char core[]);

#endif
