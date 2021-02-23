```c++
//求阶乘
double factor(int i) 
{
	if (i == 0)  return 1; 
	else return  i * factor(i - 1);
}

double mysin(double i) 
{
	double e = i * i;  //输入x，先算出x的平方。
	int j = 1; //j用来计算次方数。
	double f = i; //f是多项式中的某一项。
	double sum = 0; //sum是结果
	for(int b = 1 ; b<=30 ; b++)
	{
		sum = (j % 4 == 1) ? sum + f : sum - f;  //这个比较新奇，3，7，11%4 ==3 /5，9，13%4 == 1；可以利用这个来将奇数分成2部分。学到了，学到了。
		j = j + 2;
        //操作指数。
		i = i * e;
        //操作x，使x的次方数加2.
		f = i / factor(j);
        //算出展开式的值
	}
	return sum;
}
void main() {
	double k;
	k = mysin(8);
	cout << sin(8)<<endl;
	cout << k;
}
```
```c++
void test05()
{
    const double pi = 3.1415926535;
    double x = 0;
    cin >> x;
    cout << sin(x) << endl;
    while(x>pi)
    {
        x = x - 2 * pi;
    }
    double mysin = x;
    double tmp = 0;
    int n = 3;
    bool isnot = 1;
    while (fabs(mysin-tmp)>0.000001)
    {
        tmp = mysin;
        long double factor = 1;
        for (int i = n;i >= 1;i--)
            factor *= i;
        if (isnot == 1)
        {   
            mysin = mysin - pow(x, n) / factor;
            isnot = 0;
        }
        else
        {
            mysin = mysin + pow(x, n) / factor;
            isnot = 1;
        }
        n += 2;
    }
```
```c++
int main() 
{
	int a = 1;
	double x, y = 0, s = 1;
	cout << "input x" << endl;
	cin >> x;
	for (int n = 1; n < 13 ; n++)
	{
		for (int i = 1; i <= (2 * n - 1); i++)
		{
			a *= i;
		}
		s = pow(-1, n + 1) * pow(x, 2 * n - 1) / a;
		a = 1;
		y += s;
	}
	cout << "输出的y=" << y << endl;
	system("pause");
	return 0;
}
```
```c++
double factor(int power) //求阶乘，利用指数。
{
	if (power==1) return 1;
	else return power*factor(power-1);
}
double sum(int power,double x) //泰勒展开，相当于一个求和的问题。
{
	if(power == 1) return x  ;
	else if(power%4 == 1) return (pow(x,power)/factor(power)+sum(power-2,x));
	else return (-pow(x,power)/factor(power)+sum(power-2,x));
}
int main()
{
	double x;
	cin>>x;
	int power = 61;
	cout<<sum(power,x)<<endl;
	cout<<sin(x);
}
```

```c++
double factorial(int n)
{
    if(n==1) return 1;
    else return n*factorial(n-1);
}
int main()
{
    double x = 0;
    cin>>x;
    double res = 0;
    for(int i=1;i<30;i++)
    {
        double temp = pow(-1,i+1)*pow(x,2*i-1)/factorial(2*i-1);
        res+=temp;
    }
    printf("%.8lf",res); 
}
//熟能生巧啊，最后自己都能搞出简单的代码了。。。
```

已知容易搞不懂的几个错误

1. 求阶乘时，建议不要使用int，阶乘增长速度太快了。
2. 精确度的问题，当n取到一定数字的时候和sin的值已经相差极小了，而且由于不知名的问题double类型的结果竟然只能有6位小数。
3. 输入数字太大会导致循环次数太多导致阶乘爆掉，所以应当使用正弦函数的周期性来避免这个问题。但是在使用周期性时，定义的pi和超越数pi总是会存在误差，当输入的数字足够大时，这个误差将是难以避免的。