# STL

- stl有6大组件，它们分别是
- 容器（Containers）
- 分配器（Allocators）
- 算法（Algorithms）
- 迭代器（Iterators）
- 适配器（Adapters）
- 仿函数（Functors）
- 指$end()$是最后一个元素的下一个位置

# 容器

## 容器遍历

```c++
for(vector<int>::iterator it = v.begin();it!=v.end();it++) {...}//before C++11
for(auto it : v){...}  //C++11
```

## 容器的结构分类

1. Sequence Containers  序列式的容器
2. Associative Containers 关联式容器 
3. Unordered Containers 散列容器

![容器结构示意图 ](E:\C-NoteBook\泛型编程\assets\容器结构示意图.jpg)

# 分配器

## 简介

- 分配器是用来管理内存的
- 每一个容器都有第二个参数，第二个参数就是分配器，分配器有一个默认值``vector<int , allocator<int>> v;``
- 可以显示的使用分配器``allocator<int> a; int *p = a.allocate(100); a.deallocate(p,100);``
- 直接用的话，不好用

## 底层实现

- 通过调用``operator new/operator delete`` 函数实现内存的分配，而``operator new/operator delete``又是调用的``malloc/free``函数。
- 有些编译器对内存的分配没有优化，比起直接调用``malloc``反而变慢了。

![image-20201231081652252](E:\C-NoteBook\泛型编程\assets\image-20201231081652252.png) ``size``才是你想要的，有些编译器采用的内存池的设计，减少``malloc``的调用。

- 内存对齐：比如说我想要一个3字节的空间，然而编译器给我申请4个，而4个的情况是一开始已经申请好了的（一开始就申请了一大块空间），直接切出一块给用户使用。

- 内存``cookie``：当你分配内存时，会有一个东西标记你开辟了多少内存，当你多次的分配同样大小的空间时，这些``cookie``就是没用的。



# 迭代器

- 实际上是泛化的指针对象，拥有类似于指针的行为（指运算符重载）

- 就像指针有指针常量一样，迭代器也有指针常量

  ``vector<int>::const_interator it;`` 这时，值不能被修改**没错 const_interator是指定值不能被修改的** 

- 如果你希望创建一个常量指针

  ``const vector<int>::interator it;`` 这时指向不能被修改



