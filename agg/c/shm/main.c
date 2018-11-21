#include <stdlib.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define SIZE 50
#define SHM_FLAG 0666 | IPC_CREAT
#define SEM_FLAG 0666

#define SEM_FULL 0
#define SEM_EMPTY 1
#define SEM_MUTEX 2

typedef struct area{
    int size;
    int left;
    int head;
    int tail;
    struct node *list;
} area;

typedef struct node{
    int written;
    int len;
    char str[10];
} node;

char get_rand(){
    char letter;
    srand((unsigned)(getpid() + time(NULL)));  
    letter = (char)((rand() % 26) + 'A');  
    return letter;
}

//P操作
void P(int sem_id, int key){
    struct sembuf *bf;
    bf->sem_num = key;
    bf->sem_op = 1;
    bf->sem_flg = SEM_UNDO;
    if(semop(sem_id, bf, 1) < 0){
        perror("P failed\n");
        exit(1);
    }
};
//V操作
void V(int sem_id, int key){
    struct sembuf *bf;
    bf->sem_num = key;
    bf->sem_op = -1;
    bf->sem_flg = SEM_UNDO;
    if(semop(sem_id, bf, 1) < 0){
        perror("V failed\n");
        exit(1);
    }
};
area *shm;
void dt(int sig){
    printf("ctrl + c\n");
    shmdt(shm);
}

int main(){
    signal(SIGINT, dt);
    pid_t parent, child;
    //初始化共享存储区
    int shm_id = shmget(IPC_PRIVATE, SIZE * sizeof(node) + sizeof(area), SHM_FLAG);
    if(shm_id < 0){
        perror("shmget failed\n");
        exit(1);
    }
    shm = shmat(shm_id, NULL, 0);
    if(shm < 0){
        perror("shmat failed");
        exit(1);
    }
    node *li = (node *)malloc(SIZE * sizeof(node));
    shm->list = li;
    shm->size = shm->left = SIZE;
    shm->head = shm->tail = 0;
    
    //初始化和设置信号量
    int sem_id = -1;
    if((sem_id = semget(IPC_PRIVATE, 3, SEM_FLAG)) < 0){
        perror("semget failed\n");
        exit(1);
    }
    if (semctl(sem_id, SEM_FULL, SETVAL, 0) < 0 || semctl(sem_id, SEM_EMPTY, SETVAL, 10) < 0 || semctl(sem_id, SEM_MUTEX, SETVAL, 1) < 0)
    {
        perror("semctl failed\n");
        exit(1);
    }

    //fork parent
    //fork shanghai
    //fork beijing

    parent = fork();
    if(parent < 0){
        perror("fork parent failed\n");
        exit(1);
    }
    //fork出的父进程
    else if(parent == 0){
        shm = shmat(shm_id, NULL, 0);
        if(shm < 0){
            perror("parent shmat failed");
            exit(1);
        }
        printf("shm->left:%d\n", shm->left);
        while (shm->left > 0)
        {
            P(sem_id, SEM_EMPTY);
            P(sem_id, SEM_MUTEX);
            shm->list[shm->tail].len = 1;
            shm->list[shm->tail].str[0] = get_rand();
            shm->tail = (shm->tail + 1) % SIZE;
            shm->left--;
            shm->size++;
            printf("parent:%d,,size:%d\n", shm->tail, shm->size);

            V(sem_id, SEM_MUTEX);
            V(sem_id, SEM_FULL);
            sleep(1);
        }
        shmdt(shm);
        exit(0);
    }
    else{
        child = fork();
        if(child < 0){
            perror("fork child failed\n");
            exit(1);
        }
        else if(child == 0){
            char temp;
            shm = shmat(shm_id, NULL, 0);
            if(shm < 0){
                perror("child shmat failed");
                exit(1);
            }
            printf("shm->size:%d\n", shm->size);
            while(shm->size > 0){
                P(sem_id, SEM_FULL);
                P(sem_id, SEM_MUTEX);
                
                temp = shm->list[shm->head].str[0];
                shm->head = (shm->head + 1) % SIZE;
                shm->left++;
                shm->size--;
                printf("child:%d, %c,size:%d\n", shm->tail, temp, shm->size);

                V(sem_id, SEM_MUTEX);
                V(sem_id, SEM_EMPTY);
                sleep(3);
            }
            shmdt(shm);
            exit(0);
        }
    }

    //wait
    pid_t rt;
    int status;
    while ((rt = waitpid(-1, &status, 0)) != -1)
    {
        printf("pid=%d process return %d\n", rt, status);
    }
    shmdt(shm);
    //释放存储区
    printf("finished !\n");
    return 0;
}
