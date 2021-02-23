# 栈
1. 先进后出

# 出栈和入栈
```C++
#include<stack>
stack<int> s;
//出栈
for(int i = 0; i <5;i++)
 s.push(i);
//入栈
for(int j = 0; j < 5; j++)
 s.pop();
```
# 其他接口
```c++
s.size(); //查看栈的大小
s.top();//查看栈顶元素
s.empty(); //查看是否为空
```