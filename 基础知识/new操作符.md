new操作符

new开辟后，可以（**必须**）使用delete进行释放。
# new的基本语法
## 在堆区中开辟数据
```c++
int *p = new int(20); //创建一个整型变量，没有变量名
int * p = new int[10]{}; //可以直接使用指针来存放数组，不用写[]。{}里面可以初始化变量
int**p = new int*[10]{NULL};//创建一个指针数组
```
注意
1. 开辟的数据传入的是任意数据类型返回的是地址。
2. 堆区的数据不会自动释放

## 释放数据
```c++
delete 指针名; //将堆指针释放。
delete[] 指针名 //释放数组。
```

# 开辟一个动态的二维数组
## 开辟
```c++
	int line, queue;
	cout << "输入行" << endl;
	cin >> line;
	cout << "输入列" << endl;
	cin >> queue;
	cout<<"输入数字"<<endl;
	int **arr = new int *[line] { NULL };
	for (int i = 0; i < line; i++)
		arr[i] = new int[queue]{0};
	for (int i = 0; i < line; i++)
		for (int j = 0; j < queue; j++)
			if (*(arr + i) + j != NULL)
				cin >> arr[i][j];
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < queue; j++)
			if (*(arr + i) + j != NULL)
				cout<< arr[i][j]<<" ";
		cout<<endl;
	}	
```
## 销毁
```c++
for (int i = 0; i < line; i++)
{
		if (*(arr + i) + j != NULL)
			delete[] arr[i];
        arr[i] = NULL;
}
delete [] arr;
arr = NULL;
```

# new在继承和多态中的使用

当类对象需要指针指向堆区一块内存时，要用到new，这时传参数和赋值运算是缺省的，会使不同对象的指针指向同一块内存，析构时会产生重大错误！

## Problem

1. 使用值传递和返回值，调用默认拷贝构造函数
2. 赋值运算没有额外开辟内存
3. 析构时重复析构，或者析构不干净

## Solution

1. 重载$=$
2. 使用深拷贝

```c++
class public fa
{
    char* str;
    fa(const fa & f);
    virtual ~fa();
    this& operator=(cosnt fa& f);
}
fa::fa(const & f) //传入引用已经可以避免传值时调用默认拷贝构造函数的问题了
{
    if(this->str!=NULL) delete[] str;
	this->str = new char[strlen(f.str)+1];
    strcpy(this->str,f.str);
}
this&fa::operator=(const fa& f)
{
    if(this==&f) return *this;
    else
    {
     	if(this->str!=NULL) delete[] str;
        this->str = new char[strlen(f.str)+1];
        strcpy(this->str,f.str);
	}
}
virtual fa::~fa()
{
    if(this->str!=NULL)
    {
        delete []str;
        str = NULL;
    }
}
//将析构函数设计成virtual,是为了在析构时调用子类的析构函数，处理子类除继承父类数据之外开辟在堆区的数据
```

- 何时是拷贝，何时是赋值？

  ```c++
  fa f1 = f0; //应当调用copy构造函数，而不是重载赋值号
  fa f2 = fa(); //应当调用重载赋值号
  ```

- 



