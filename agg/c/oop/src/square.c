#include "square.h"

double area_square(double sidelen){
    return sidelen * sidelen;
} 

shape *init_square(double sidelen){
    shape *s = (shape *)malloc(sizeof(shape) + sizeof(pri) + sizeof(pub));
    s->attr = (pri *)malloc(sizeof(pri));
    s->fun = (pub *)malloc(sizeof(pub));
    strcpy(s->attr->type, "square");
    s->attr->length = sidelen;
    s->fun->area = area_square;
    return s;
}