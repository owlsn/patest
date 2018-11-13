#include "shape.h"
#ifndef CIRCLE
#define CIRCLE
#define PI 3.14159
//circle,square,triangle类，继承shape基类，包含指向shape类的指针
typedef struct circle{
    struct shape *c;
} circle;

//计算面积的方法，实现多态
double area_circle(double diametet);

//初始化方法，初始化circle，square和triangle对象
shape *init_circle(double diametet);
#endif