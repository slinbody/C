#include<stdio.h>
#include<time.h>
#define max_size 10


struct queue {
    int array[max_size];
    int front;//先加一再拿資料
    int rear; //先放資料再加一
};

typedef struct queue Queue;
void Queue_Init(Queue *Q);
void test(int *x);
void Queue_Add(Queue *Q,int data);
int Queue_Remove(Queue *Q);
void Queue_Show(Queue *Q);


int main()
{
Queue Q;
Queue_Init(&Q);
int i;

srand(time(NULL));
//for(i=0;i<12;i++)
    Queue_Add(&Q,((rand()+1)%100));
    Queue_Add(&Q,((rand()+1)%100));
    Queue_Remove(&Q);
    Queue_Remove(&Q);
    Queue_Remove(&Q);
//    Queue_Add(&Q,((rand()+1)%100));

//    Queue_Add(&Q,((rand()+1)%100));

return 0;
}

void Queue_Show(Queue *Q)
{
    int i;
    for(i=0;i<max_size;i++)
    {
        printf("Queue[%d] = %2d, ",i,Q->array[i]);
        if(i==4)
            printf("\n");
    }
    printf("\n==== rear is %d, front is %d ====\n\n",Q->rear,Q->front);
}

int Queue_Remove(Queue *Q)
{
    int value;
    Q->front++;
    Q->front=Q->front%max_size;
    if(Q->front == Q-> rear)
    {
        printf("Queue is Empty\n");
//        Q->front--;
        Q->front = (Q->front + max_size -1 ) % max_size;
        return 0;
    }
    else
    {
        value = Q->array[Q->front];
        Q->array[Q->front]=0;
        Queue_Show(Q);
        return value;
    }
}

void Queue_Add(Queue *Q,int data)
{
    if(Q->rear==Q->front)
        printf("Queue is FULL!\n");
    else
    {
        Q->array[Q->rear]=data;
        Q->rear=(Q->rear+1)%max_size;
    }
    Queue_Show(Q);
}

void Queue_Init(Queue *Q)
{
    int i;
    for(i=0;i<max_size;i++)
        Q->array[i]=0;

    Q->front=max_size-1;
    Q->rear=0;
    Queue_Show(Q);
}

void test(int *x)
{
    printf("%d\n",*x);
}
