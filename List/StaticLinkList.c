#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100	//总元素数为MAXSIZE-1

typedef int dataType;

typedef struct {
    dataType data;
    int cur;
}component,SLinkList[MAXSIZE];
//规则：
//0位置没有数据
//队列尾的cur为0
//此种链表用于不设有指针的高级语言

//返回第1个值为e的元素的位序
int LocateElement(SLinkList L, dataType e);
//将一维数组space中各成分初始化为一个备用链表，0位序为头指针
void InitSpace(SLinkList Space);
//申请新节点,若有新节点，返回其下标，否则返回0
int Mallco_L(SLinkList Space);
//将下表为k的节点回收到备用链表
void Free_L(SLinkList Space, int k);
int main()
{
	SLinkList L;//备用节点
	//debug用
	// L[0].cur = 2;
	// L[2].cur = 1;
	// L[1].cur = 3;
	// L[3].cur = 0;
	// L[2].data = 1;
	// L[1].data = 2;
	// L[3].data = 3;
	// int n = 2;
	//printf("First %d:%d\n",n,LocateElement(L,n));	
	InitSpace(L);
	//链表的使用
	int Head = Mallco_L(L);
	L[Head].cur =Mallco_L(L);
	L[L[Head].cur].cur = 0;
	L[L[Head].cur].data = 1;
	//打印出此链表全部元素
	int i = 0,j=Head;	
	while(L[j].cur != 0)
	{
		j = L[j].cur;
		printf("%d:%d\n",i++,L[j].data);
	}
}
//返回第1个值为e的元素的位序
int LocateElement(SLinkList L,dataType e)
{
	int i = L[0].cur;
	while(i && L[i].data != e)
	{
		i = L[i].cur;
	}
	return i;
}

void InitSpace(SLinkList Space)
{
	int i=0,j=MAXSIZE-1;
	while(i<j)
	{
		Space[i].cur = i+1;
		i++;
	}
	Space[j].cur = 0;
}

int Mallco_L(SLinkList Space)
{
	int i=Space[0].cur;
	// if(Space[0].cur != 0)
	// {
	// 	Space[0].cur = Space[i].cur;
	// 	return i;
	// }
	//return 0;
	//书上的更简洁的方法
	if(Space[0].cur)	Space[0].cur = Space[i].cur;
	return i;
}
void Free_L(SLinkList Space, int k)
{
	// int i =Space[0].cur;
	// while(Space[i].cur != 0)	i =Space[i].cur;
	// Space[i].cur = k;
	// Space[k].cur = 0;
	//书上插入到表头复杂度更低
	Space[k].cur = Space[0].cur;
	Space[0].cur = k;
}