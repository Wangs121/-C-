#include <stdio.h>
#include <stdlib.h>
typedef int dataType;

//单链表指针结构体
typedef struct LNode{
    dataType data;
    struct LNode *next;
}LNode, *LinkList;
//状态枚举
typedef enum {
    OK=1,
    Error=0
}Status;

//查找L中第i个元素,并返回其值到e
Status GetElem(LinkList L,unsigned int i, dataType *e)
{
    LinkList p = L;
    unsigned int j=0;
    while ( j++<i && p != NULL) p = p->next;
    if(j!=i+1) return Error;
    *e = p->data;
    return OK;
}
//在L链表内第i个之前插入一个值为e的节点
Status ListInsert(LinkList &L,unsigned int i, dataType e)
{
    if(i==0)//在第0个位置插入
    {
        LinkList temp = L;
        L = (LinkList)malloc(sizeof(LNode));
        L->data = e;
        L->next = temp;
        return OK;
    }
    LinkList p = L;
    unsigned int j=0;
    i-=1;
    while(j++<i && p->next != NULL) p = p->next;
    if(j!=i+1)  return Error;
    //此时p指向i前一个节点
    LinkList temp = p->next;//储存下一个节点
    p->next = (LinkList)malloc(sizeof(LNode));
    p->next->next = temp;
    p->next->data = e;

    return OK;
}

//删除L链表的第i个元素，并通过e返回其值
Status ListDelete(LinkList L,unsigned int i,dataType *e)
{
    if(!i)//删除0节点思路：同插入第0个方法，第0个数据换为第一个，删除第一个，
    {
        *e = L->data;
        LinkList temp = L->next;
        L->data = temp->data;
        L->next = temp->next;
        free(temp);
        return OK;
    }
    LinkList p = L;
    unsigned int j=0;
    i-=1;
    while (j<i && p->next != NULL)    
    {
        p=p->next;
        j++;
    }
    //printf("No.%d\n",j);
    if(j<i) return Error;
    //找到第i-1个节点
    LinkList temp =p->next;
    *e = temp->data;
    p->next = temp->next;
    free(temp);
    return OK;
}
//以L为头，顺序输入n个元素的值，创建列表
Status CreateList_For(LinkList &L,unsigned int n)//参数为&L，此时可以改变头指针
{
    LinkList p = (LinkList)malloc(sizeof(LNode));
    L = p;
    while(--n)
    {
        scanf("%d",&p->data);
        //printf("Add:%d\n",p->data);
        p->next = (LinkList)malloc(sizeof(LNode));
        p=p->next;
    }
    scanf("%d",&p->data);
    //printf("Add:%d\n",p->data);
    p->next = NULL;
    return OK;
}
//以L为头，逆序入n个元素的值，创建列表
Status CreateList_Rev(LinkList &L,unsigned int n)
{
    LinkList p = (LinkList)malloc(sizeof(LNode));
    scanf("%d",&p->data);//尾节点
    p->next = NULL;
    L=p;
    while(--n)
    {
        L = (LinkList)malloc(sizeof(LNode));//L一直作为头指针，申请新的内存
        scanf("%d",&L->data);
        L->next = p;//使L指向p之后用p连接L
        p = L;
    }
    return OK;
}
//将两非递减排列链表合并为非递减链表至Lc
Status MergeList(LinkList La, LinkList Lb,LinkList &Lc)//此处使用La，非&La，因此可直接将La作为一个可使用指针，Lb同
{
    LinkList p =(LinkList)malloc(sizeof(LNode));
    Lc = p;
    while(La!=NULL && Lb != NULL)
    {
        if(La->data < Lb->data) 
        {
            printf("min:%d\n",La->data);
            p->data = La->data;
            La = La->next;  
        }
        else 
        {
            printf("min:%d\n",Lb->data);
            p->data = Lb->data;
            Lb = Lb->next;
        }
        p->next=(LinkList)malloc(sizeof(LNode));
        p = p->next;
    }
    if(La == NULL)
        while (1)
        {
            printf("min:%d\n",Lb->data);
            p->data = Lb->data;
            Lb = Lb->next;
            if(Lb==NULL)    break;
            p ->next = (LinkList)malloc(sizeof(LNode));
            p = p->next;
        }
    else 
        while (1)
        {
            p->data = La->data;
            printf("min:%d\n",La->data);
            La = La->next;
            if(La == NULL) break;
            p ->next = (LinkList)malloc(sizeof(LNode));
            p = p->next;
        }
    p->next = NULL;
    return OK;
}

int main()
{
    LinkList Head;
    //printf("&HEAD:%d\n",&Head);
    CreateList_For(Head,3);
    int res=0;
    //ListInsert(Head,3,5); 
    printf("DeleteSuccess:%d\n",ListDelete(Head,2,&res));
    // printf("Delete:%d\n",res); 
    //MergeList(Ha,Hb,Head);
    //输出指针
    
    int i=0;
    LinkList p=Head;
    printf("Your List:\n");
    while(p->next != NULL)
    {
        printf("%d: %d\n",i++,p->data);
        p=p->next;
    }
    printf("%d: %d\n",i++,p->data);
}
