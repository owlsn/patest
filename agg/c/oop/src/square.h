#include "shape.h"
#ifndef SQUARE
#define SQUARE
typedef struct square{
    struct shape *s;
} square;

double area_square(double sidelen);

shape *init_square(double sidelen);
#endif