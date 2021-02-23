//算法分析：
//定义一个二维数组存放状态i和状态i到终点所走的步数。
#include <iostream>

using namespace std;
#define MAX 100
int main()
{
    int F[MAX][MAX] = {}; //定义F为当前位置到起点的数字的和。
    int D[MAX][MAX] = {}; //定义D为当前位置所存储的数字。
    //状态方程 F[i][j] = max{D[x+1][y],D[x+1][y+1] }
    int n; //n为行数。
    cout << "请输入你想要的行数" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> D[i][j];
        }
    } //输入数字金字塔
    F[1][1] = D[1][1];
    for (int i = 2; i <= n; i++) //只能从第二行开始。
        for (int j = 1; j <= i; j++)
        {
            F[i][j] = max(F[i - 1][j - 1], F[i - 1][j]) + D[i][j];
        }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, F[n][i]);
    }
    cout << res;
    return 0;
}