# 欧几里得算法

## 内容

都知道欧几里得算法，即辗转相除法。
$$
gcd(a,b) = gcd(b,a\%b)
$$
代码如下

```c++
int gcd(a,b)
{
    if(!b) return b;
    else return(b,a%b);
}
```

## 欧几里得和连分数

$$
a\in R\;,q\in Z\;,q<a:a=q+\frac{1}{a_2}(a_2>1)\\
若a_2\notin Z\;,a_2= q_2+\frac{1}{a_3}(a3>1)\\
...\\
直到a_n为整数
$$

如：
$$
\frac{75}{48} = 1+\frac{1}{\frac{48}{27}}\\
\frac{48}{27} = 1+\frac{1}{\frac{27}{21}}\\
\frac{27}{21} = 1+\frac{1}{\frac{21}{6}}\\
\frac{21}{6} = 3+\frac{1}{2}\\
$$
不难发现，连分数中分离出来的整数$q$是商，$a_n$的分子分母分别是除数和余数，可以把一个数表示为一个数串
$$
\frac{75}{48}=<1,1,1,3,2>
$$
这串数，就是辗转相除法每一步得到的商

1. 有理数的连分数的表达式是有限的，无理数连分数的表达式是无限的

# 扩展欧几里得

## 内容

实际上在使用辗转相除法的过程中，我们能顺便求出一个特定的不定方程的解
$$
ax+by = gcd(a,b)\quad a,b\in Z
$$
两侧同乘k，结论依然成立

## 举例

举个例子 如 求48和75的最大公约数
$$
75-48\times1 = 27\\
48-27\times1=21\\
27-21*1=6\\
21-6\times3=3\\
gcd(75,48)=3
$$
将到二行的6用到三行的左侧式子换掉，说明3可以用21和27表示再往上换，换到最后得到
$$
3 =75\times(-7)+48\times11\\
3 =48\times4+27\times(-7)\\
3 =27\times(-3)+21\times4\\
3 =21\times1+6\times(-3)\\
实际上还能写出两行\\
3= 6\times0+3\times1\\
3=3\times1+0\times0
\\
实际上我们就求得了这个方程的一个解\\
75x+48y = 3\\
$$

## 代码

1步代换之后（由后往前），就得到了$x$和$y$的值，即
$$
ax+by=c\\
bx_0+(a-[a/b]b)y_0=c
$$
根据待定系数法可知
$$
x=y_0\\
y=x_0-[a/b]y_0
$$
这是一个递归算法，对比上面的情况，不难得出最后是$x_0=1,y_0=0$

代码如下

```c++
// 扩展欧几里得 
#include<iostream>
using namespace std;
static int x = 0;
static int y = 0;  //使用静态变量记录方程的解。
int exgcd(int a, int b)
{
	
	if (!b) //当b为0的时候，说明到达递归边界，这时候最后一步方程的解为1，0。
	{
		x = 1;
		y = 0;
		return a; //返回最大约数
	}
	int r = exgcd(b, a % b); //使用递归来保存x，y的值，最后一步为1，0
    int x_0 = x, y_0 = y; //保存这一步的解。 
    //上一步的x = y_0,上一步的y = x_0-(a/b)*y_0
	x = y_0;
	y = x_0 - (a / b) * y_0;
	return r; //返回最大公约数
    //实际上，可以并不用计算最大公约数的值
}
int main()
{
	exgcd(75, 48);
	cout << x<<endl;
	cout << y;
}
```

稍微简化了一下

```c++
void Exgcd(int a,int b,int &x,int&y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return ;
	}
    Exgcd(b,a%b,y,x);
    y -= (a/b)*x;
    return ;
}
```



# 裴蜀定理

关于$a,b$和$gcd(a,b)$的线性不定方程
$$
ax+by = gcd(a,b)\quad a,b\in Z
$$
存在$x,y$都有$ax+by$是$gcd(a,b)$的倍数。

证明

通过扩展欧几里得，我们已经知道了，这个方程的一组整数解，不妨设为$x=x_0,y=y_0$，这时候令$x_1 = x_0 + \delta$代入得到
$$
ax_1-a\delta+by_0 = gcd(a,b)\\
ax_1+b(y_0-\frac{a\delta}{b}) = gcd(a,b)\\
y_1 = y_0-\frac{a\delta}{b}\\
$$
这时，只要保证$y_1$和$\delta$是整数即可
$$
\frac{a}{b} = \frac{\frac{a}{gcd(a,b)}}{\frac{b}{gcd(a,b)}}=\frac{a'}{b'}
$$



显然$a',b'$是互质的

只要让$\delta=kb'$即可保证$y_1$是个整数，此时$\delta$也是整数，这样就求得了通解
$$
x = x_0+k\times\frac{b}{gcd(a,b)}\\
y=y_0-k\times\frac{a}{gcd(a,b)}\\
$$
记忆技巧，$a$和$x$位置是相反的