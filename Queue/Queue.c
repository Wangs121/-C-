#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct QNode
{
    DataType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct 
{
    QueuePtr front; //队列头
    QueuePtr rear;  //队列尾
}LinkQueue;

//构造一个空队列Q
void InitQueue(LinkQueue &Q);
// 销毁队列
void DestroyQueue(LinkQueue &Q);
//清空队列
void ClearQueue(LinkQueue &Q);
//判断队列是否为空
bool QueueEmpty(LinkQueue &Q);
//队列的长度
int QueueLength(LinkQueue Q);
// //返回头元素
// void GetHead(Q,&e);
//插入e到Q末尾
void EnQueue(LinkQueue &Q,DataType e);
//删除头元素
void DeQueue(LinkQueue &Q,DataType &e);
//对Q遍历visit函数
void QueueTraverse(LinkQueue Q,void(*visit)(DataType e));

void print_queue(LinkQueue &Q);
void test_function(DataType e);
int main()
{
    LinkQueue myQueue;
    InitQueue(myQueue);
    EnQueue(myQueue,1);
    EnQueue(myQueue,2);
    DataType del = 0;
    DeQueue(myQueue,del);
    printf("Delete : %d\n",del);
    EnQueue(myQueue,3);
    printf("Queue Length : %d\n",QueueLength(myQueue));
    printf("Queue Empty ? : %d\n",QueueEmpty(myQueue));
    ClearQueue(myQueue);
    QueueTraverse(myQueue,test_function);
    //EnQueue(myQueue,3);
    print_queue(myQueue);
    //DestroyQueue(myQueue);
}
void print_queue(LinkQueue &Q)
{
    int counter = 0;
    QueuePtr i = Q.front;
    while(i!= Q.rear)
    {
        printf("%d : %d\n",counter++,i->data);
        i = i->next;
    }
}
void InitQueue(LinkQueue &Q)
{
    QueuePtr h;
    h = (QueuePtr)malloc(sizeof(QNode));
    if(!h)  exit(0);
    Q.front = h;
    Q.rear = h;
    Q.rear->next = NULL;
}

bool QueueEmpty(LinkQueue &Q)
{
    if(Q.front == Q.rear)   return true;
    return false;
}

void EnQueue(LinkQueue &Q,DataType e)
{
    
    Q.rear->data = e;
    Q.rear->next = (QueuePtr)malloc(sizeof(QNode));
    Q.rear = Q.rear->next;
    Q.rear->next = NULL;
}
void DeQueue(LinkQueue &Q,DataType &e)
{
    if(Q.front == Q.rear)   exit(0);
    QueuePtr p = Q.front;
    Q.front = Q.front->next;
    e = p->data;
    free(p);
}
int QueueLength(LinkQueue Q)
{
    int counter=0;
    while(Q.front != Q.rear)    //直接使用Q.front，不会对原队列造成影响
    {
        Q.front = Q.front->next;
        counter++;
    }
    return counter;
}
void ClearQueue(LinkQueue &Q)
{
    // //思路：采用一个指针组存放队列地址，再逐个释放内存
    // int length = QueueLength(Q);
    // int i = 0;
    // QueuePtr p = Q.front;
    // QueuePtr arr[length] = {};
    // for(i=0;i<length;i++)
    // {
    //     arr[i] = p;
    //     p = p->next;
    // }
    // Q.rear = Q.front;
    // for(i=1;i<length;i++)
    // {
    //     free(arr[i]);
    // }
    //书本上的思路（更简洁）：从queue头开始删除
    while(Q.front->next)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}

void DestroyQueue(LinkQueue &Q)
{
    // //同ClearQueue
    // int length = QueueLength(Q);
    // int i = 0;
    // QueuePtr p = Q.front;
    // QueuePtr arr[length] = {};
    // for(i=0;i<length;i++)
    // {
    //     arr[i] = p;
    //     p = p->next;
    // }
    // Q.rear = NULL;
    // Q.front = NULL;
    // for(i=0;i<length;i++)
    // {
    //     free(arr[i]);
    // }
    //书本上的思路（更简洁）：从queue头开始删除，但需要Q.rere->next = NULL;
    //要对队列FIFO认识深刻一点，处理元素是从开头开始的！
    while(Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}
void test_function(DataType e)
{
    printf("%d\n",e);
}

void QueueTraverse(LinkQueue Q,void(*visit)(DataType e))
{
    QueuePtr p = Q.front;
    while(p != Q.rear)
    {
        visit(p->data);
        p = p->next;
    }
}