#include <stdio.h>
#include "config.h"
#ifdef USE_LIB
#include "extra/math.h"
#endif

#ifdef HAVE_POW
#include <math.h>
#endif

int main(int argc, char *argv[]) 
{
    //初始化图的状态
    int graph[MAXNODE][MAXNODE]; 
    int node[MAXNODE] = {0};
    for (int i = 0; i < MAXNODE; i++)
    {
        node[i] = (check_i(i)) ? 1 : 0;
    }
    for (int i = 15; i >= 0; i--)
    {
        for (int j = 15; j >= 0; j--)
        {
            //判断两种状态是否可以稳定转化，即判断两个点之间是否有有向边
            if (node[i] && node[j] && check_i_j(i, j))
            {
                graph[i][j] = 1;
            }
            else
            {
                graph[i][j] = 0;
            }
        }
    }
/**
 * main
 * */
#ifdef USE_LIB
    // printf("USE USE_LIB\n");
#else
    // printf("USE CMATH LIB\n");
#endif

#ifdef HAVE_POW
    double a = 2.0, b = 8.0;
    double res = (double)pow(a, b); 
    printf("use default pow function , res is :%lg\n", res);
#else
    double a = 2.0;
    int b = 8;
    double res = pw(a, b);
    printf("use lib pow function , res is %lg\n", res);
#endif

if(argc == 3){
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]); 
    double r = pw(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, r);
}
else{
    printf("%s Version %d.%d\n",
               argv[0],
               PATH_VERSION_MAJOR,
               PATH_VERSION_MINOR); 
    printf("Usage: %s base exponent \n", argv[0]);
}
return 0;
/**
 * 输出
 * */
    int result[MAXNODE] = {0};
    int pathsNum = 0;
    struct Pathslist *list = init_paths();
    // DFS(graph, MAXNODE, 15, 0, &pathsNum, list);
    if(list->num){
        struct Paths *temp;
        struct PathsNode *n;
        temp = list->start;
        while (temp != NULL)
        {
            printf("共%d个节点:", temp->num);
            n = temp->head;
            while(n != NULL){
                printf("%d", n->data);
                n = n->next;
                if(n != NULL){
                    printf("->");
                }
            }
            printf("\n");
            temp = temp->next;
        }
    }
    return 0;
}