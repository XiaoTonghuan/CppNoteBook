//砝码称重
#include <iostream>
#define max 1005
using namespace std;
int a[7] = {0, 1, 2, 3, 5, 10, 20};
int b[max]={0};
int x = 0;
int num = 0;
bool f[max] = {0}; //表示前i个砝码中重量为j的情况是否存在
int main()
{
    // 1、将问题转换成01背包问题
    for (int i = 1; i <= 6; i++)
    {
        cin >> x; //输入每个砝码的个数
        for (int j = 1; j <= x; j++)
            b[++num] = a[i]; //将砝码的重量放入新的数组里面。
    }
    //动态规划开始
        f[0] = 1; //前i个砝码重量为0的情况一定存在。
    for (int i = 1; i <= num; i++)
    { //枚举前n种情况重量为j是否存在。
        for (int j = 1000; j >= 1; j--)
        {                               //可以等于0，有实际意义。
                f[j] = f[j] + f[j - b[i]]; //前i种情况里面重量为j是否存在？当i-1中情况重量为j的情况存在时，不取第i个砝码，或者前i种情况j-w[i]存在时，取第i个砝码，都能导致前i个砝码重量为j的情况存在。
        }
    }                            
    //动态规划完成，计算输出重量的个数。
    int count = 0;
    for (int i = 1; i <= 1000; i++)
    {  
        if (f[i])
            count++;
    }
    cout <<"Total=" <<count;
}