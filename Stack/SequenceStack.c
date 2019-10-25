#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//栈的大小
#define STACK_INIT_SIZE 2  //基本容量
#define STACKINCREMENT 100  //增量

typedef struct SqStack{
    DataType *base; //指向栈底
    DataType *top;  //指向栈顶
    int StackSize;  //栈的大小
}SqStack;
/*
栈分为
**顺序栈**用地址连续的储存空间依次存放从栈底到栈顶的数据元素
**链栈**用线性链表存放基础元素,优点是无需限制栈的容量
*/
//构造空栈S
void InitStack(SqStack &S);
//销毁栈S
void DestroyStack(SqStack &S);
//清空栈S
void ClearStack(SqStack &S);
//判断栈是否为空
bool StackEmpty(SqStack &S);
//返回栈长度
unsigned int StackLength(SqStack &S);
//返回栈顶元素于e
//两种指针用法，调用方法也不同
// GetTop(myStack,&top);
// GetTop2(myStack,top);
void GetTop(SqStack S,DataType *e);
void GetTop2(SqStack S,DataType &e);
//将e入栈
void Push(SqStack &S,DataType e);
//删除栈顶元素，并用e返回其值
void Pop(SqStack &S,DataType &e);
//从栈底到栈顶依次队S的每个元素调用函数visit()
void StackTraverse(SqStack S,void(*visit)(DataType e));//函数指针，详见README.md
//输出函数
void print_Stack(SqStack S);
void testfunc(DataType e);
int main()
{
    SqStack myStack;
    InitStack(myStack);
    Push(myStack,5);
    Push(myStack,4);
    Push(myStack,8);
    Push(myStack,2);
    DataType del;
    Pop(myStack,del);
    printf("Delete:%d\n",del);
    DataType top;
    GetTop2(myStack,top);
    printf("top:%d\n",top);
    printf("Stack Length:%d\n",StackLength(myStack));
    //ClearStack(myStack);
    //DestroyStack(myStack);
    printf("Stack Empyt:%d\n",StackEmpty(myStack));
    //输出栈里所有元素
    print_Stack(myStack);
    StackTraverse(myStack,testfunc);
}
void print_Stack(SqStack S)
{
    DataType *p = S.base;
    int counter=0;
    while(p != S.top) //栈顶是不存东西的
    {
        printf("%d:%d\n",counter,*p);
        p++;
        counter++;
    }
}
//构造空栈S
void InitStack(SqStack &S)
{
    
    S.base = (DataType *)malloc(STACK_INIT_SIZE * sizeof(DataType));//在这里申请内存
    if(!S.base) exit(0);
    S.StackSize = STACK_INIT_SIZE;
    S.top = S.base;
}
//将e入栈
void Push(SqStack &S,DataType e)
{
    //判断栈是否满 
    if(S.top - S.base >= S.StackSize)
    {
        S.base = (DataType *)realloc(S.base , (S.StackSize + STACKINCREMENT)*sizeof(DataType));//realloc，详情见README.md
        if(!S.base) exit(0);//申请失败
        S.top = S.base + S.StackSize;
        S.StackSize += STACKINCREMENT;
    }
    * S.top++= e;
}
//返回栈顶元素于e
void GetTop(SqStack S,DataType *e)
{
    *e = *(S.top-1);
}
void GetTop2(SqStack S,DataType &e)
{
    e = *(S.top-1);
}
//清空栈S
void ClearStack(SqStack &S)
{
    S.top = S.base;
}
//销毁栈S
void DestroyStack(SqStack &S)
{
    free(S.base);
}
//判断栈是否为空
bool StackEmpty(SqStack &S)
{
    return S.base == S.top;
}
//返回栈长度
unsigned int StackLength(SqStack &S)
{
    return S.top - S.base;
}
//删除栈顶元素，并用e返回其值
void Pop(SqStack &S,DataType &e)
{
    e = *--S.top;
}
//从栈底到栈顶依次队S的每个元素调用函数visit()
void StackTraverse(SqStack S,void(*visit)(DataType e))
{
    for(DataType *i=S.base;i<S.top;i++)
    {
        visit(*i);
    }
}
void testfunc(DataType e)
{
    printf("test printf%d\n",e);
}