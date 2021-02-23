# 1

## 几个前提

- 任何整数做**（2*k-1）**变换，一定是奇数。
- 任何整数做**（k*2）**变换，一定是偶数。

- 偶数加奇数是奇数

## Question

生成一个任意长度的数列，在其中选择arr[i],arr[j],arr[k] (i<j<k)使得arr[i]+arr[k]!=arr[j]*2 

分析：arr[j]*2必是偶数，只要arr[i]和arr[k]一个是奇数，另一个是偶数即可。

数列如何生成？

先构造一个符合题意的数列，然后分别做奇变换和偶变换，将两列数排成一列，即为符合题意的数列，一直这样构造下去即可得到任意数量符合题意的数列。

## Code

- 向上取整：$(K+1)/2$

- 这是不是归并的拼接加上一点点数学啊！

```c++
int* MakeSequence(int size)
{
	if (size == 1) return new int[1]{ 1 };

	int half = (size + 1) / 2;
	int* base = MakeSequence(half);
	int* res = new int[size] {0};


	for (int i = 0; i < half; i++)
		res[i] = base[i]*2-1;
	for (int i = half; i < size; i++)
		res[i] = base[i-half] * 2;

	delete base;
	return res;
}

int main()
{
	int* p = MakeSequence(8);
	for (int i = 0; i < 8; i++)
	{
		cout << p[i] << endl;
	}
}
```

# 2

![image-20210104165625021](E:\C-NoteBook\算法\数论\Other.assets\image-20210104165625021.png) 

```c++
// 先确定第一维数是多少
// 再确定第二维数字
// 第一维和第二维的确定方法不一样。
for()



```

