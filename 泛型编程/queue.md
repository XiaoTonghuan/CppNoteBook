# 队列
1. 先进先出
2. 只有队头能被访问

# 出入和访问
```C++
//入队
for(int i = 0 ;i<5;i++)
    q.push(i);
//访问队头
    cout<<q.front();
//访问对头
    cout<<q.back();
//出队
for(int i = 0 ;i<5;i++)
    q.pop();
q.size();//队列的大小
```
# 构造
```C++
#include<queue>
queue<int>q;
```