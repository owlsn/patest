#include "triangle.h"
double area_triangle(double edge){
    return edge * edge * sqrt(3) / 4;
}
shape *init_triangle(double edge){
    shape *t = (shape *)malloc(sizeof(shape) + sizeof(pri) + sizeof(pub));
    t->attr = (pri *)malloc(sizeof(pri));
    t->fun = (pub *)malloc(sizeof(pub));
    strcpy(t->attr->type, "triangle");
    t->attr->length = edge;
    t->fun->area = area_triangle;
    return t;
}
