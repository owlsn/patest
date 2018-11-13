#include <stdio.h>
#include "circle.h"
#include "triangle.h"
#include "square.h"

int main(int argc, char *argv[]){
    //测试
    double length = 10;
    shape *c = init_circle(length);
    shape *s = init_square(length);
    shape *t = init_triangle(length);
    double c_area = shape_area(c);
    double s_area = shape_area(s);
    double t_area = shape_area(t);
    printf("circle:%lg,\nsquare:%lg,\ntriangle:%lg\n", c_area, s_area, t_area);
    return 0;
}