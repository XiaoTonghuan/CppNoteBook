# 最大公倍数
## 两个数的最大公倍数？
### 欧几里得算法

$$
    \gcd(a,b) = \gcd(b,a\%b)  \\
    显然，这里面的a>b。
$$
```c++
int gcd(int a, int b)
{
    while(1) //不停循环即可实现
    {
        if(a%b == 0) return b; 
        else
            {
                int temp = a;
                a = b;
                b = temp%b;
            }
    }
} //非递归。
```
```c++
int gcd(int a, int b)
{
        if(a%b == 0) return b; //递归边界。
        else gcd(b,a%b);
}
```
```c++
int gcd(int a, int b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}
//究极简化。。。。
```
### 更相减损法

1. 判断较大的数字能否被2整除？能则除以2，然后再次进行判断，不能则下一步。
2. 将较大的数字减较小的数字，直到所得结果和较小的数字相等。

```c++
int gcd(int a, int b)
{
	while(a!=b)
	{
		if(a%2==0&&b%2==0)
		{
			a/=2;
			b/=2;
		}
		else if(a>b)
		{
			a-=b;
		}
		else
		{
			b-=a;
		}
	}
}//非递归
```
```c++
int gcd(int a, int b)
{
	
	if(a==b) return a;
	else if(a%2==0 && b%2==0) gcd(a/2,b/2);
	else gcd(a-b,b);
} //递归。
```
### stein算法

```c++
//有待补充

```
## n个数的最大公因数
实际上就是求前n-1个数和第n个数的最大公因数，可以使用递归来实现
```c++
int GcdN(int array[], int n)
{
	for (int i = 0;i < n-1;i++)
		array[i+1] = gcd(array[i], array[i + 1]);//将第i个数和第i+1个数的最大公约数放在第i+1位，这样能保证最后一位一定是所有数字的最大公约数。
	return  array[n-1];
}
int main()
{
    int n = 0;
    cin>>n;
    int array[1000]{0};
    for(int i = 0;i<n;i++)
        cin>>array[i];
    cout<<GcdN(array,n);

}
```
## 例题
1、给出n个数字，取k个数字，求这k个数字最大公约数的最大值
2、分析
1. 当a|b的时候，公约数最大
2. 第k个数的最大值为k*gcd
3. 取等号全部成立，gcd(max) = [n/k];
4. 神不神奇，意不意外？？
# 最小公倍数
$$
lcm(a,b)=\frac{ab}{(a,b)}
$$
```c++
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
```
## n个数的最大公倍数
第n个数和前n-1个数字最大公倍数的最大公倍数。
$$
lcm(a_1,a_2,...a_n) = \frac{lcm(a_1,a_2,...a_{n-1})*a_n}{(lcm(a_1,a_2,...a_{n-1}),a_n)}
$$
```c++
int Lcm(int array[], int n)
{
	for (int i = 0;i < n-1;i++)
	{
		array[i + 1] = lcm(array[i], array[i + 1]);
	}
	return array[n - 1];
}
```

