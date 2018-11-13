#include "shape.h"
#include <stdlib.h>
//获取面积的公共方法，传入不同的对象获取面积
double shape_area(shape *shape){
    return shape->fun->area(shape->attr->length);
}