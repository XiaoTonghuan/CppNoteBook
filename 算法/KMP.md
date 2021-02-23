# 同源异构词

- 指含有的数目相同元素的种类和个数都相同，但顺序不同。



# 浮动窗口和欠债表

```c++
int isnContainSon(string target, string str)
{
	if (target.size() > str.size()) return -1;
	int InValidNum = 0;
	int Table[256]{};
	int M = target.size();
	for (int i = 0; i < target.size(); i++)
		Table[target[i]]++;  //建立欠债表,如果最终欠债表还是原来的样子（同时会有InValid==0），说明符合题意。表示Target借出。
	for (int i = 0; i < M; i++) //查看第0个窗口的情况
		if (Table[str[i]]-- <= 0)  //欠债表--，表示还债（也可能是强赛），欠债表<=0表示（target）没借过（或者被多还了）。
			InValidNum++; //在<=0时，欠债表--，表示被强塞了，还债是无效的还债，无效的还债数增加。
	int R = M; //记录第二个窗口的结束位置，第一个窗口结束在M-1；
	for (; R < str.size(); R++)
	{
		if (!InValidNum) return R-M;
		if (Table[str[R]]-- <= 0)
			InValidNum++;
		if (Table[str[R-M]]++ < 0) //欠债表++，表示将开头的那个窗口踢出去（只要str有还债（重借）或者强赛（要回），都会++或者--）
			InValidNum--; //<0,表示现在有无效的借债。所以++之后，无效的还债数减少了！
	}
	return InValidNum == 0 ? R - M : -1;
}
```

