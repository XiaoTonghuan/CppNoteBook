# 链表
1. 节点：包括，数据域，指针域
2. 优点：
   1. 对任意的位置进行快速的插入和删除元素。
   2. 动态分配内存，不会造成内存的溢出
3. 缺点：
   1. 遍历的速度比较慢，
   2. 占用的空间比数组大
4. 插入和删除的操作都不会造成原有迭代器的失效
5. STL中的链表是双向循环的链表
6. 不支持随机访问

# 结构

![image-20201231104810259](E:\C-NoteBook\泛型编程\STL\assets\image-20201231104810259.png)

# 构造函数
```c++
lsit<int> l;默认构造
list<int> l(l1.begin(), l1.end());//传入区间构造
list<int> l(3,5);//n个几的方式
lsit<int> l(l1); //拷贝构造函数
```
# list容器的赋值和交换操作
```c++
//赋值
list<int > l1;
for(int i=0;i<5;i++)
    l1.push_back(i);
//访问
for(list<int> :: iterator it = l.begin(); it != l.end();it++)
    cout<<*it

list<int > l2;
//等号
l2 = l1;
//assign()函数
l2.assign(3，5)；
l2.assign(l1);
l2.assign(l1.begin(),l1.end());
//交换
list<int> l3(10,100);
l2.swap(l1);
```
# list容器中的大小操作
```c++
//resize();
l.resize(10);
l.resize(98,5);
//empty()
l.empty();
l.size();
```
# 插入和删除
```c++
//尾插 push_back(elem);
l.push_back(1);
//尾删 pop_back();
l.pop_back();
//头插 front_back(elem);
l.front_back(2);
//头删
l.pop_front();
//中间插入 insert(pos,elem);
l.insert(l.begin(), l1); //返回新数据的位置
l.insert(l.begin(), l2,3); //插入12个3，没有返回值
l.insert(l2.begin(),l1.end()) //将一个前闭后开的区间插入，没有返回值。
l.clear() //清空
//删除
l.erase(l.begin()); //删除某个元素，返回下一个元素的位置
l.erase(l.begin(),l.end()); //删除一个前闭后开的区间，返回下一个元素的位置
l.remove(3); //删除所有与3值相同的元素。
```
# 访问
```c++
l.front();访问表头
l.back();访问表尾
```
# list反转和排序
```c++
l.reverse();//反转
sort(l); //这句是错的！不支持随机访问的迭代器不能用
l.sort(); //可以使用自己的，这是升序
//降序
bool Mycompare(int v1,int v2)
{
    return v1 > V2;
}
l.sort(Mycompare) //放进函数名即可
//(Mycompare里面书写，排序规则，排序会按照表达式为真的那个排序规则执行)
```
# 注意事项

1. 迭代器支持++或--的操作



# ++运算符重载

1. 后++是返回下一个节点值，并不会对以前的数据进行更改
2. 前++是返回下一个节点的引用，会对值进行更改
3. 前++比后++快
4. ``int i(6) i++++ `` 这是错的

 



