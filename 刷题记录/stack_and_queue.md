# 2.3 表达式计算

1. 对于仅限四则运算的情况

   关键点在于乘号的处理，我们只需要在检测到乘号的下一个符号的时候再对乘号两侧的数进行运算即可。

2. 对于括号的处理

   在检测到括号时，我们可以使用递归的方式，使得括号减少

**P224、P227、P770**

```c++
class Solution {
public:
    int calculate(string s) 
    {
        stack<int> stk;
        int res = 0;
        int sign = 1;
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(s[i]>='0' && s[i]<='9') //统计数字
            {
                int num = 0;
                while(s[i]>='0' && i < s.size())
                    num = num * 10 + (s[i++] - '0'); 
                --i;
                res += sign * num;
            }
            else if(s[i]=='+') sign = 1;
            else if(s[i]=='-') sign = -1;
            else if(s[i] == '(')
            {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign =1;
            }
            else if(s[i] == ')')
            {
                res*= stk.top();
                stk.pop();
                res+= stk.top();
                stk.pop();
            }
        }
        return res;
    }
};
```

# 3.2.3队列的应用

1. 杨辉三角

   ```c++
   #include<iostream>
   #include<queue>
   using namespace std;
   int main()
   {
   	queue<int> que;
   	que.push(1);
   	que.push(1);
   	int n = 0;
   	cout << 1 << endl;
   	for(int j = 0 ; j < 7 ; ++j) {
   		for (int i = 0; i < j + 2; ++i) {
   			int temp = que.front();
   			if (temp == 1) {
   				que.push(temp);
   				n++;
   			}
   			cout << temp <<" ";
   			que.pop();
   			if (n < j + 2) {
   				n++;
   				que.push(temp + que.front());
   			}
   		}
   		n = 0;
   		cout<<endl;
   	}
   }
   //课本上添加了辅助0，方法更加巧妙
   ```

# [LeetCode P1047删除相邻的重复元素](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/)

其实就是利用栈，当栈顶元素和当前元素一样时，弹出栈顶，否则将元素插入栈，注意关键词，相邻！

注意一个坑，在循环中可能会出现栈空的情况。

```c++
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        int l = 0;
        while(l < S.size()){  //遍历一遍字符串
            if(!res.empty() && res.back() == S[l]) //栈非空且重复
                res.pop_back();  //弹出
            else{
                res.push_back(S[l]);  //栈空或者元素不重复，加入栈
            }
            l++;
        }
        return res;
    }
};
```

