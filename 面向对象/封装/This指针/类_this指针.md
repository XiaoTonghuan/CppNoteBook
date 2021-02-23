类_this指针

# 介绍
1. this 指针是一个指针。
2. this指针可以用来调用成员函数所属对象自身。
如``p-> == this->``  //函数中可以使用this来访问p这个对象.
3. 每一个成员函数里面都有一个this指针。
4. this指针是一个指针常量，指向是不可以修改的，永远指向调用函数的对象。 如``this = NULL``是错误的。但是``this->m_age = 100``是正确的（函数体内指针解引用的方式。）
# 调用时机
1. 区分形参和成员变量名
2. 类对象作为返回值
# 代码实例
```c++
class person
{
public:
	int age;
	person(int age) //构造函数，形参的名称和成员函数一样。
	{
		this->age = age; //通过this指针来标记成员函数。
	}
};
```
```c++
class person
{
public:
	int age;
	person(int age)
	{
		this->age = age;
	}
	person & addage (person& p)
	{
		this->age += age; //传入一个对象，让他的age加在被调用的对象身上。
		return *this; //返回这个对象。
	}
};
int main()
{   
	person p1(25);
	person p2(30);
	cout<<p2.addage(p1).addage(p1).addage(p1).age;  //链式结构。将p1的值加到p2上，返回这个对象，+p1+p1，返回这个对象，打印他的age.
}
```