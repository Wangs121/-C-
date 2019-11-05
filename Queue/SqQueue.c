#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
#define MAX_SIZE 3
//在插入、删除等操作之后SqQueue.front不一定在0的位置，这里需要特殊处理
//SqQueue.front == SqQueue.rear 不一定是空队列
//队列满可用一个变量做标志或队列头指针在尾指针的下一位
//此处使用后者,且实际容量为MAX_SIZE-1
typedef struct 
{
    DataType *base; //初始化首地址
    DataType front; //队列头
    DataType rear;  //队列尾
}SqQueue;

//构造一个空队列Q
void InitQueue(SqQueue &Q);
//队列的长度
int QueueLength(SqQueue Q);
//插入e到Q末尾
void EnQueue(SqQueue &Q,DataType e);
//删除头元素
void DeQueue(SqQueue &Q,DataType &e);

void print_queue(SqQueue Q);
int main()
{
    SqQueue myQueue;
    InitQueue(myQueue);
    EnQueue(myQueue,1);
    EnQueue(myQueue,2);
    DataType i=0;
    DeQueue(myQueue,i);
    EnQueue(myQueue,3);
    printf("Queue Length : %d\n",QueueLength(myQueue));
    print_queue(myQueue);
}
void print_queue(SqQueue Q)
{
    DataType i = Q.front;
    while(i!=Q.rear)
    {
        printf("%d\n",Q.base[i]);
        i =(i+1)%MAX_SIZE;
    }
}
void InitQueue(SqQueue &Q)
{
    Q.base = (DataType*)malloc(MAX_SIZE * sizeof(DataType));
    if(!Q.base)  exit(0);
    Q.front = 0;
    Q.rear = 0;
}
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAX_SIZE)%MAX_SIZE;
}
void EnQueue(SqQueue &Q,DataType e)
{
    if((Q.rear+1)%MAX_SIZE ==Q.front)  exit(1);
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAX_SIZE;
}
void DeQueue(SqQueue &Q,DataType &e)
{
    e = Q.front;
    Q.front = (Q.front+1)%MAX_SIZE;
}