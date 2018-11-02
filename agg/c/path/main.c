#include <stdio.h>
#include"path.h"
#include"check.h"

int main()
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
    int result[MAXNODE] = {0};
    int pathsNum = 0;
    struct Pathslist *list = init_paths();
    DFS(graph, MAXNODE, 15, 0, &pathsNum, list);
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