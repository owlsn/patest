#include "path.h"
struct Pathslist *init_paths()
{
    struct Pathslist *init = (struct Pathslist *)malloc(sizeof(struct Pathslist));
    init->num = 0;
    init->start = NULL;
    return init;
}
struct Paths *cp_path(struct Stack *stack)
{
    struct Paths *path = (struct Paths *)malloc(sizeof(struct Paths));
    path->num = 0;
    int node;
    struct PathsNode *head = (struct PathsNode *)malloc(sizeof(struct PathsNode));
    node = pop(stack);
    head->data = node;
    head->next = NULL;
    struct Stack *temp = init_stack();
    while (stack->length)
    {
        struct PathsNode *new = (struct PathsNode *)malloc(sizeof(struct PathsNode));
        node = pop(stack);
        path->num++;
        push(temp, node);
        new->data = node;
        new->next = head->next;
        head->next = new;
    }

    struct PathsNode *t = head, *p = head;
    while(t->next != NULL){
        t = t->next;
    }
    head = head->next;
    p->next = NULL;
    t->next = p;

    while (temp->length)
    {
        node = pop(temp);
        push(stack, node);
    }
    free(temp);
    path->head = head;
    path->next = NULL;
    return path;
}

void add_path(struct Pathslist *paths, struct Stack *stack)
{
    struct Paths *path = (struct Paths *)malloc(sizeof(struct Paths));
    path = cp_path(stack);
    struct PathsNode *t = path->head;
    if (paths->num)
    {
        paths->tail->next = path;
        paths->tail = path;
    }
    else
    {
        paths->start = path;
        paths->tail = path;
    }
    paths->num++;
}

//深度优先遍历整个图，记录start到end的所有路径，即问题的解
//stack记录遍历的情况，当寻找到了对应的路径之后，将stack中的值存入paths[]中
//paths[]总存储的是最终的所有的路径情况
void DFS(int (*graph)[MAXNODE], int n, int start, int end, int *pathsNum, struct Pathslist *list)
{
    if(start == end){
        return;
    }
    int c_position[MAXNODE] = {0};
    int in_stack[MAXNODE] = {0};
    struct Stack *stack = init_stack();
    push(stack, start);
    in_stack[start] = 1;
    int top_e, node, flag;
    while (stack->length)
    {
        flag = 1;
        top_e = top(stack);
        int position = (c_position[top_e]) ? c_position[top_e] + 1 : 0;
        for (int i = position; i < n; i++)
        {
            if(graph[top_e][i] && !in_stack[i]){
                if (i == end)
                {
                    push(stack, i);
                    add_path(list, stack);
                    continue;
                }
                else{
                    flag = 0;
                    //遍历其他节点
                    push(stack, i);
                    in_stack[i] = 1;
                    c_position[top_e] = i;
                }
                break;
            }
        }
        if(flag){
            node = pop(stack);
            in_stack[node] = 0;
            c_position[node] = 0;
        }
    }
    free(stack);
}