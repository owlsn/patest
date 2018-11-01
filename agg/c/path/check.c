#include"check.h"
//检测状态i是否是符合要求的状态
int check_i(int i)
{
    int bit[4] = {0};
    //0表示m的位置,1表示d的位置,2表示r的位置,3表示c的位置
    bit[0] = (i & 0x08) >> 3;
    bit[1] = (i & 0x04) >> 2;
    bit[2] = (i & 0x02) >> 1;
    bit[3] = i & 0x01;
    //d和r不能共存
    if (bit[0] != bit[1] && bit[1] == bit[2])
    {
        return 0;
    }
    //r和c不能共存
    else if (bit[0] != bit[2] && bit[2] == bit[3])
    {
        return 0;
    }
    return 1;
}

//判断两点之间是否存在有向边，前提是两点都是稳定的
int check_i_j(int i, int j)
{
    int bit[4] = {0}, position = 0;
    //人在不同的地方
    if ((i & 8) != (j & 8))
    {
        int i_d = i & 0x04, j_d = j & 0x04,
            i_r = i & 0x02, j_r = j & 0x02,
            i_c = i & 0x01, j_c = j & 0x01;
        i_d == j_d &&position++;
        i_r == j_r &&position++;
        i_c == j_c &&position++;
        //d,r,c至少有两个所在的位置相同,不然i和j两点之间不存在边
        if (position >= 2)
        {
            return 1;
        }
    }
    return 0;
}