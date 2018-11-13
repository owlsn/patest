//shape基类，pri指向基类私有属性,pub指向基类公共操作方法
#ifndef SHAPE_BASE
#define SHAPE_BASE
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct shape{
    struct pri *attr;
    struct pub *fun;
} shape;

typedef struct pri{
    char type[10];
    double length;
} pri;

typedef struct pub{
    double (*area)(double length);
} pub;
//获取面积的公共方法，传入不同的对象获取面积
double shape_area(shape *shape);
#endif