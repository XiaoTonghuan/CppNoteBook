# 无参宏

无参的宏用来替换文本。

```C
# define MAX 1000
//# define 宏名 替换文本
//在下面出现MAX时，会自动替换成1000。
```

## 注意

1. 类对象宏(object-like macro)//指无参宏。
2. 不能加 `;` ， 否则代替的文本会变成1000;
3. 如果要写宏不止一行，则在结尾加反斜线符号使得多行能连接上

```C
# define H "hello\
world"
//注意要对齐。
```

4. 宏定义必须写在函数之外，作用域为整个源程序，如果想提前结束他，可以使用``# undef``

```c
# define M 5
# undef M
```

5. 宏可以嵌套

```c
# define M 5
# define MM M*M
//注意，该过程在编译阶段已经完成
```

6. 可以代替数据类型

```c
# define student ST
//或者
# define struct student ST
//
struct student
{
    char* s;
    int n;
};
ST s = {"jack",100}; //相当于 struct student s = {...};
//等价于typedef
typedef int I;  // # define int I
```

7. 宏无法重复定义

# 有参宏

如果宏名加上参数，他可以用来代替函数

```c
# define count(M) M*M
//可以实现输出M*M的值
```

1. 宏和函数有巨大的不同，宏只进行替换，而函数会对实参进行预处理

```c
# define count(M) M*M
cout<<count(14+1); //结果会是14+1*14+1，而不是我们想要的15*15.
```

2. 宏名和（）之间不允许有空格

3. 宏不会为形参分配内存，而值传递会
4. 宏定义也可以用来定义表达式或者多个语句

```c
#define JI(a,b) a = i + 3; b = j + 5;   //宏定义多个语句
```



# 可变宏

… 和 \__VA_ARGS__

...可以填到形参列表中\__VA_ARGS__填到被替换的语句中。

```c
# define PR(...) cout<<__VA_ARGS__<<endl
```



# 其他

1. ``##`` 可以起到粘合剂的作用 如``# define M num##0`` M被替换成num0
2. ``#``字符串串接

```c
# define sum(a,b) cout<<#a"+"#b"="<<a+b
int main()
{
	sum(10,20);
}
//输出结果为10+20=30
```

