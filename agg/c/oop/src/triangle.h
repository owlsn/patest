#include "shape.h"
#ifndef TRIANGLE
#define TRIANGLE
typedef struct triangle{
    struct shape *t;
} triangle;

double area_triangle(double edge);

shape *init_triangle(double edge);
#endif