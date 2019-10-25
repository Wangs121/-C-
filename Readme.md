# 数据结构(C语言版) -严蔚敏 吴伟民 编著 -清华大学出版社 自学练习笔记

对应书中的数据结构以及处理函数的实现

文字编码格式统一为UTF-8

## 链表
2.3 [ 线性链表的链式表示和实现](https://github.com/Wangs121/DataStructureInC/blob/master/List/LinearList.c)（发现使用gun编译器会编译失败，g++则没问题🤢，原因是函数内使用`(LLinkList &L)`，[混用了c与c++]( https://stackoverflow.com/questions/20831221/error-expected-or-before-token/46370936#46370936 )，而自己还没找到通过函数参数改变头指针，暂时只能这样用。

2.12 [线性表的静态单链表存储结构](https://github.com/Wangs121/DataStructureInC/blob/master/List/StaticLinkList.c)

## 栈
3.1 [顺序栈](https://github.com/Wangs121/DataStructureInC/blob/master/Stack/Stack.c)
   > 使用了新的函数[`void *realloc(void *ptr, size_t size)`](https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm)
   >
   > [函数指针](https://www.geeksforgeeks.org/function-pointer-in-c/)

