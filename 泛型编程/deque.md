# deque
1. deque底层的数据结构是链表，模拟队列
2. 像是一个动态的二维数组（2级指针叫中控器，数据是缓冲区）

# 构造函数
```c++
//默认构造
deque<T> d;
//区间
deque<T> d(d1.begin(),d1.end());
//n个i
deque<T> d(12,123);
//拷贝
deque<T> d(d1);
```
# 赋值
1. 重载等号
2. assgin();  
```c++
//重载等号
deque<int> d1;
deque<int> d2;
d2 = d1;
//assign();
d2.assign(2,5); //2个5
d2.assign(d1.begin(),d1.end());//区间
```
# 大小操作
```c++
deque.empty();//判断是否为空，空返回1
deque.size(); //返回大小
deque.resize(21);//重新指定大小，比原来长填默认值，比原来短，删除多余的元素
deque.resize(22,9)//放22个9
```
# 插入和删除
```c++
//前后插
d.push_back(i);
d.push_front(i);
//前后删
d.pop_back();
d.pop_front();
//中间插
d.insert(d.begin(),d1.begin(),d1.end());
d.insert(d.begin(),2,3000);
//删
d.erase(d.begin());//删单个
d.erase(d.begin(),d.end());//删区间
d.clear()//清空
```
# 数据存取
```c++
deque<int> a;
a[i];
d.at(6);
d.front(); //第一个元素的访问
d.back(); //第二个元素的访问
```
# deque的排序
```c++
sort(d.begin(),d.end()); //alglorithm
```

