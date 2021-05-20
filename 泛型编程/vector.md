# vector容器（向量）
1. 相当于数组，模拟了栈
2. 使用时包含头文件#include<vector>

# 用法简介
## 创建一个vector容器 
```c++
vector<int>v(12)//创建容器，长度为12，默认所有元素，初值为0.
vector<int>v //创建容器且没有申请开辟空间。
vector<int>a(12,1)//声明类名，传入参数，创建对象，构造函数（第一个填开辟空间的大小，第二个可以选择填上初值）
vector<int>v2(v1.begin(), v1.end()); //将[v.begin(), v.end())赋值给v2，注意是前开后闭。
vector<int>v2(v)//拷贝构造函数。
```
## 遍历vector容器里的元素
```c++
vector<int> v(12, 1);
    //1、通过while来遍历
    vector<int>::iterator itBegin = v.begin(); //创建迭代器，让它指向第一个元素
    vector<int>::iterator itEnd = v.end();     //创建迭代器，让它指向栈顶
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }

    //利用for循环
   vector<int> v(12, 4);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    //利用遍历模板
    void Myprint(int &val)
    {
        cout << val << endl;
    }

    void test01()
    {
        vector<int> v(12, 3);
        for_each(v.begin(), v.end(), Myprint);
    }
```
## 赋值操作
1. =
2. assign()函数
```c++
vector<int>v1;
vector<int>v2;
v1=v2;
v1.assign(v2);
v1.assign(v2.begin(), v2.end()); //前闭后开
```
## 插入元素
```C++
//尾插法push_back(ele);
    vector<int> v;
    v.push_back(3);
    v.push_back(34);
    v.push_back(87);
//删除尾部元素pop_back();
    v.pop_back();
//中间插入 insert(const v.pos,ele);
        //insert(const v.pos,int num,ele);
    v.insert(v.begin(),12);
    v.insert(v.begin(),2,3);//在开头插入2个3
//中间删除 erase(const v.pos);
        //erase(const v.pos1,v.pos2);
    v.erase(v.begin());
    v.erase(v.begin,v.end());
//全部删除
    v.clear();
```
## 容量和大小
由用户指定的大小叫大小，编译器会根据指定的大小创建一个1.5倍或者2倍的空间，称为容量
```c++
vector<int> v;
v.empty(); //返回1或0，1为空。
v.capacity(); //返回容量。
v.size(); //返回大小
v.resize(12, 56);//重新指定长度为12，多余的空间用26填充
v.resize(34);//重新制定长度为34的空间，多余的空间用0填充
v.resize(1);//重新指定长度为1的空间，多余的删去。
```
## 数据存取
```c++
vector<int> v;
//at(int idx);
//[idx]
v.at(2);
v[2];
//front(); back(); //返回第一个和最后一个元素
cout<<v.front();
cout<<v.back();
```
# 元素调换
```c++
vector<int > v1;
vector<int > v2;
//交换
v1.swap(v2);
//匿名对象加拷贝构造加交换实现capacity的收缩
vector<int>(v).swap(v);
//交换对象指向的空间，析构匿名对象。
```
# 预留空间
//vector 在动态管理内存的时候，会删除原来空间，然后申请一块新的空间。
```c++
vector<int > v;
int num;
int *p = NULL;
for(int i = 0;i<100000;i++)
{
    v.push_back(i);
    if(p!=&v[0])
    {
        p=&v[0];
        num++;
    }
}
```
//使用reserve预留空间
```C++
v.reserve(10000);
//预留空间（capacity）10000；
```
# vector存放自定义数据类型
```c++
class person
{
public:
    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};
void test01()
{
    person p[3] = {person("tom", 18), person("john", 87), person("jim", 90)};
    vector<person> v;
    for (int i = 0; i < 3; i++)
        v.push_back(p[i]);
    for (vector<person>::iterator it = v.begin(); it != v.end(); ++it)
        cout << it->name << endl
             << it->age << "  " << endl;
}

```

# 使用vector创建二维数组

```c++
  vector<vector<int> > v1;
    int x;
    for ( int i = 0;i<5;i++)
    {
        vector<int> v2;
        for (int i =0;i<5;i++)
        {
            cin >> x;
            v2.push_back(x);
        }
        v1.push_back(v2);
    }
    for (vector<vector<int> >::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
    {
        for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
            cout << *it2 << " ";
        cout << endl;
    } 
    //注意>>的识别问题，两个之间应该加个空格
```

禁止使用vector\<bool>来代替bool类型的数组！
