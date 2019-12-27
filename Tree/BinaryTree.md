# 二叉树
## 二叉树的性质
* 在二叉树的第i层至多有2^(i-1)个节点
* 深度为k的二叉树至多有2^k-1个节点
* 对于任意一个二叉树，若其终端节点数为n0，度为2的节点数为n2，则n0 = n2 + 1
证明：	二叉树的总节点数n=n0 + n1 + n2
	  	总分支数B = n1+ 2*n2 ，且n=B + 1
		综上，n0 = n2 + 1
## 完全二叉树
* 具有n个节点的完全二叉树的深度为log2(n) + 1 
	（不大于log2(n) 的最大整数加一）
* 如果对一棵有n个节点的完全二叉树的节点按层序编号，则对任意节点，有
	1. 如果i=1，则节点i是二叉树的根，无双亲；如果i>1，则其双亲PARENT(i)是节点int(i/2)
	2. 如果2i>n，则节点i无左孩子，否则其左孩子是节点2i
	3. 如果2i+1>n，则节点i无右孩子，否则其右孩子RCHILD(i)是节点2i+1
## 二叉树的储存结构
* 顺序储存结构
```c
//顺序储存结构
#define MAX_TREE_SIZE
typedef TDataType SqBiTree[MAX_TREE_SIZE];	//0号单元储存节点
```
示意图：
![](%E4%BA%8C%E5%8F%89%E6%A0%91/bear_sketch@2x.png)
![](%E4%BA%8C%E5%8F%89%E6%A0%91/bear_sketch@2x.png)
* 链式储存结构
![](%E4%BA%8C%E5%8F%89%E6%A0%91/bear_sketch@2x.png)

## 遍历二叉树
* 先序遍历
	1. 访问根节点
	2. 先序遍历左子树
	3. 先序遍历右子树
* 中序遍历
	1. 中序遍历左子树
	2. 访问根节点
	3.  中序遍历右子树
* 后序遍历
	1. 后序遍历左子树
	2. 后序遍历右子树
	3. 访问根节点
可以使用递归实现遍历，也可使用栈

## 线索二叉树
* 前驱
* 后继
二叉树节点中序序列：abc
则b的前驱为a，后继为c
利用二叉树的n个节点存在的n+1个空链域存放节点的前驱后继信息
使用两个标志域：LTag与RTag，若左、右节点存在则LTag、RTag=1，否则为0表示前驱、后继。
![](%E4%BA%8C%E5%8F%89%E6%A0%91/%E7%85%A7%E7%89%87%202019%E5%B9%B411%E6%9C%8824%E6%97%A5%20201042.jpg)

```c

#include <studio.h>
#include <Stalin.h>
typedef int DataType;

//链式储存结构
//使用(a)结构
typedef struct BiTNode{
DataType data;
struct BiTNode *lchild, *rchild;//左右孩子指针
}BitNode, *BiTree;

//构造空二叉树
void InitBiTree(&T);
//销毁二叉树T
void DestroyViTree(&T);
//按照definition构造二叉树
void CreateBiTree(&T,definition);
//清空二叉树
void ClearBiTree(&T);
//二叉树是否为空
bool BiTreeEmpty(T);
//二叉树深度
int BiTreeDepth(T);
//获取二叉树的根
Root(T)
//返回e节点的值
DataType Value(T,e);
//将e赋值为value
void Assign(T,&e,DataType value);
//返回e的双亲，若为根节点返回空
Parent(T,e);
//返回e的左、右孩子，若无返回空
LeftChild(T,e);
RightChild(T,e);
//返回e的左、右兄弟，若无返回空
LiftSibling(T,e);
RightSibling(T,e);
//根据LR为0或1插入、删除c为T中p所指节点的左或右子树
void InsertChild(T,p,bool LR,c);
void DeleteChild(T,p,bool LR,c);
//先序遍历T，对每个节点执行visit函数
void PreOrderTraverse(T,visit());
//中序遍历
void InOrderTraverse(T,visit());
//后序遍历
void PostOrderTraverse(T,visit());
//层序遍历
void LevelOrderTraverse(T,visit());

```
### Code:
```c
#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

//链式储存结构
//使用(a)结构
typedef struct BiTNode{
DataType data;
struct BiTNode *lchild, *rchild;//左右孩子指针
}BiNode, *BiTree;

//构造空二叉树
void InitBiTree(BiTree &T);
//二叉树是否为空
bool BiTreeEmpty(BiTree T);
//根据LR为0或1插入(、删除)c为p所指节点的左或右子树
void InsertChild(BiTree p,bool LR,BiTree c);
//void DeleteChild(BiTree p,bool LR);
//创造一个节点,值为e
BiTree newNode(DataType e);
//先序遍历T，对每个节点执行visit函数
void PreOrderTraverse(BiTree T,void (* visit)(DataType e));
//中序遍历
void InOrderTraverse(BiTree T,void ( * visit)(DataType e));
//后序遍历
void PostOrderTraverse(BiTree T,void ( * visit)(DataType e));
//层序遍历
//void LevelOrderTraverse(BiTree T,void ( * visit)(DataType e));
void visit(DataType e)
{
    printf("%c",e);
}
//按照先序序列通过scanf创建二叉树
void CreateBiTree(BiTree &T);
//先序遍历打印出树的元素
//没想到好的方法，参考书上的使用递归，醍醐灌顶！
void printfTree(BiTree T);
int main()
{
    BiTree Root;
    InitBiTree(Root);
    Root->data = '-';
    printf("Tree Empty? :%d\n",BiTreeEmpty(Root));
    //BiTree test = newNode(10);
    //printf("%d",test->data);
    InsertChild(Root,1,newNode('+'));
    InsertChild(Root,0,newNode('/'));
    InsertChild(Root->lchild,1,newNode('a'));
    InsertChild(Root->lchild,0,newNode('*'));
    InsertChild(Root->lchild->rchild,1,newNode('b'));
    InsertChild(Root->lchild->rchild,0,newNode('-'));
    InsertChild(Root->lchild->rchild->rchild,1,newNode('c'));
    InsertChild(Root->lchild->rchild->rchild,0,newNode('d'));
    InsertChild(Root->rchild,1,newNode('e'));
    InsertChild(Root->rchild,0,newNode('f'));
    /*树为：
          -
      +       /
    a   *    e f
       b -
         c d   
    */
    //printf("%d",Root->lchild->data);
    //printfTree(Root);
    printf("\nPreOrder Traverse\n");
    PreOrderTraverse(Root,visit);
    printf("\n InOrder Traverse:\n");
    InOrderTraverse(Root,visit);
    printf("\nPostOrder Traverse:\n");
    PostOrderTraverse(Root,visit);  
    BiTree c;
    CreateBiTree(c);
    printf("\n\n");
    InOrderTraverse(c,visit);
}
void printfTree(BiTree T)
{
    if(T)
    {
        printf("%d\n",T->data);
        printfTree(T->lchild);
        printfTree(T->rchild);
    }
}
void InitBiTree(BiTree &T)
{
    T = (BiTree)malloc(sizeof(BiNode));
    T->lchild = NULL;
    T->rchild = NULL;
}
bool BiTreeEmpty(BiTree T)
{
    if(T->lchild || T->rchild)    return 1;
    return 0;
}
BiTree newNode(DataType e)
{
    BiTree t = (BiTree)malloc(sizeof(BiNode));
    t->data = e;
    t->lchild = NULL;
    t->rchild = NULL;
    return t;
}
void InsertChild(BiTree p,bool LR,BiTree c)
{
    if(LR)  p->lchild = c;
    else    p->rchild = c;
}
void PreOrderTraverse(BiTree T,void ( * visit)(DataType e))
{
    if(T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild,visit);
        PreOrderTraverse(T->rchild,visit);
    }
}
void InOrderTraverse(BiTree T,void ( * visit)(DataType e))
{
    if(T)
    {
        InOrderTraverse(T->lchild,visit);
        visit(T->data);
        InOrderTraverse(T->rchild,visit);
    }
}
void PostOrderTraverse(BiTree T,void ( * visit)(DataType e))
{
    if(T)
    {
        PostOrderTraverse(T->lchild,visit);
        PostOrderTraverse(T->rchild,visit);
        visit(T->data);
    }
}
void CreateBiTree(BiTree &T)
{
    DataType e;
    scanf("%c",&e);
    if(e != '0')
    {
        T = (BiTree)malloc(sizeof(BiNode));
        T->data = e;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    else T = NULL;
}
```