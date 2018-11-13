#include "circle.h"
//计算面积的方法，实现多态
double area_circle(double diametet){
    return PI * pow((diametet / 2), 2);
}

//初始化方法，初始化circle，square和triangle对象
shape *init_circle(double diametet){
    shape *c = (shape *)malloc(sizeof(shape) + sizeof(pri) + sizeof(pub));
    c->attr = (pri *)malloc(sizeof(pri));
    c->fun = (pub *)malloc(sizeof(pub));
    strcpy(c->attr->type, "circle");
    c->attr->length = diametet;
    c->fun->area = area_circle;
    return c;
}