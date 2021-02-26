# 课本练习

## 课本5.2.3

1. 对一个单调增数列中插入元素使得得到的数列依然是单调的

   ```c++
   void insert(vector<int>& v, int num)
   {
       int l = 0;
       int r = v.size() - 1;
       while (l <= r)
       {
           int mid = (l - r) / 2 + r;  //确定中间值
           if (mid==0 || v[mid - 1]<num && v[mid]>num)
           {
               v.insert(v.begin() + mid, num);
               return; 
           }
           else if (mid==v.size()-1 || v[mid]<num && v[mid + 1]>num) 
           {
               v.insert(v.begin() + mid + 1, num);
               return; 
           }
           else if (v[mid] > num) r = mid - 1;
           else if (v[mid] < num) l = mid + 1;
       }
   }
   ```

   二分可优化``O(logn+n)``

2. 判断一个单调集合是另外一个单调集合的子集

   ```c++
   int subset(vector<int>& v1, vector<int>& v2)
   {
       bool flag = 0;
       for (int i = 0; i < v2.size(); ++i)
       {
           int l = 0;
           int r = v1.size() - 1;
           while (r >= l)
           {
               int mid = (r - l) / 2 + l;
               if (v2[i] == v1[mid]) { flag = 1; break; }
               else  if (v1[mid] > v2[i]) r = mid - 1;
               else if (v1[mid] < v2[i])l = mid + 1;
           }
           if (flag == 0) return -1;
       }
       return 1;
   }
   ```

   二分可优化``O(log(M)+n)``

## 课本第五章

2. 集合运算

   ```c++
   //并集，遍历两个数组，建立哈希表
   //交集，遍历两个数组，建立哈希表
   //差集，遍历两个数组，建立哈希表
   //没错哈希表nb
   int main()
   {
       vector<int> v1,v2;
       for(int i = 0; i < 10 ; i+=2)
           v1.push_back(i);
       for(int j = 4; j < 15 ; j+=2)
           v2.push_back(j);
       unordered_map<int> hash;
       for(int i : v1)
           hash[i]++; //在第一个集合中出现的元素标记为1
       for(int i : v2)
           hash[i]--; //在第二个集合出现过-1，都出现过0
           
   	system("pause");
   }
   ```

3. 合并单调有序顺序表(leetcodeP88)

   ```c++
   //有几种方法，最好的一种是从后向前遍历
   //又是双指针，越界问题是真的烦
   class Solution {
   public:
       void merge(vector<int>& v1, int m, vector<int>& v2, int n) 
       {
           
           int p = m + n-1;
           m--;
           n--;
           while (p >=0 )
           {
               if(m < 0) v1[p--] = v2[n--];  //检测越界
               else if(n < 0) v1[p--] = v1[m--];  //检测越界
               else if( v2[n] > v1[m]) v1[p--] = v2[n--];
               else if( v2[n] <= v1[m]) v1[p--] = v1[m--];
           }
       }
   };
   ```

4. 删除重复元素(leetcodeP26)

   ```c++
   class Solution {
   public:
       int removeDuplicates(vector<int>& nums) 
       {
           if(nums.size()==0) return 0;
           int p1 = 0;
           int p = 0;
           for(int p2 = 1 ; p2 < nums.size() ; ++p2)
           {
               if(nums[p1++]!=nums[p2] ) 
                   nums[++p] = nums[p2];    
           }
           return p+1;
       }
       //我操，我吐了啊，我还以为是返回下标，结果是返回长度
       //双指针问题，可以先把所有if-else情况枚举一番，发现只有解答中的条件是必须要操作的
   };
   ```

# P1588

![image-20210121123216810](E:\C-NoteBook\刷题记录\assets\image-20210121123216810.png)

``O(n^3)``的解法，无脑暴力

```c++
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int sum = 0;
        int k = 1;
        while(k<=arr.size())
        {
            for(int i = 0 ; i<arr.size() ; i++) 
                for(int j = i ; j < i + k && i + k <= arr.size() ; j++)
                        sum+=arr[j];
            k+=2;
        }
        return sum;
    }
};
```

``O(n^2)``前缀和

实际上是高中所学数列中的$S_n$和$a_n$的关系
$$
\displaystyle S_i =\sum_{i = 0}^{i}a_i  \\
S_{i+1} = S_{i} + a_{i+1}\\
$$


本题中，我们可以看到上面的解法中包含求数组中一段连续区间的和，可以使用前缀和

```c++
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int sum = 0;
        vector<int> S{0}; //s的第一个元素一定是0，否则无法满足计算时的递推式
        for(int i : arr) S.push_back(S.back(),i);//算下来一共有arr.size()+1个元素
        for(int k = 1 ; k<=arr.size() ; k+=2)
            for(int i = 0 ; i<arr.size() && i+k <= arr.size() ; ++i) 
                sum += S[i+k] - S[i] ;  //片段和相加
        return sum;
    }
};
```

``O(n)``

统计数字在对应数组中出现的次数

那么这个数字究竟在哪几个数组中出现过呢

以这个数字为中心，所有出现的可能是

- 左边有奇数个连续数，右边有奇数个数连续，算上自己一共奇数个连续数
- 左边和右边都是偶数个连续数（包括啥也没有），算上自己一共奇数个连续数

```c++
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
      int sum = 0;
      for(int i = 0 ; i < arr.size(); ++i)
      {
          int left = i + 1; int right = arr.size() - i; //计算左边和右边所有可能连续数列（包括0个）的个数
          int left_odd = (left+1)/2; int left_even = left/2;
          //计算左边奇数和偶数情况的数量
          int right_odd = (right+1)/2; int right_even = right/2;
          //奇数和奇数组合，偶数和偶数组合
          sum+=(arr[i]*(left_odd*right_odd + right_even* left_even));
      }
      return sum;
    }
};
```

# P867

![image-20210121155457188](E:\C-NoteBook\刷题记录\assets\image-20210121155457188.png)

```c++
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) 
    {
        vector<vector<int>> v1;
        int line = A.size();
        int row = A.begin()->size();
        for(int i = 0 ; i < row  ; i++)
        {
            vector<int> v2;
            for(int j = 0 ; j < line ; j++)
                v2.push_back(A[j][i]);
            v1.push_back(v2);
        }
        return v1;
    }
};
```

水题

# 面试题 17.10/P169

![image-20210121164011709](E:\C-NoteBook\刷题记录\assets\image-20210121164011709.png)

## hash_table(O(n))

```C++
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int , int> hash;
        for(auto i  : nums)
        {
            hash[i]++; //这句很关键，当没有元素时自动创建，当有元素时，对应位置++
            if(hash[i]>nums.size()/2)
            return i;
        }
        return -1;
    }
};
```

## 摩尔投票法（Boyer-Moore ）

1. 将多个数字的问题转化称2个数字的，实在是妙啊

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int major; int cnt = 0;
        for(int i : nums)
        {
            if(cnt==0) //将第一个数假设为众数
            {
                major = i;
                cnt++;
            }
            else
                if(major==i) //投票器++
                    cnt++;
                else 		//下一个数和上一个不一样，将票拿回
                    cnt--;
        }
        if(cnt!=0)
        {
            cnt = 0;
            for(int i : nums)
                if(i == major)
                    cnt++;
            if(cnt>nums.size()/2) 
            return major;
            else
            return -1;
        } 
        return -1; 
    }
};
```

# P977

![image-20210121173824135](E:\C-NoteBook\刷题记录\assets\image-20210121173824135.png)

## 直接排序法

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        for(auto &i : nums)
            i*=i;
        sort(nums.begin(),nums.end());
        return nums;
    }
};
```

## 双指针

万能的双指针

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> res;
        int left = 0 , right = 1;
        for (int i = 0; i < nums.size(); ++i)
          	if (nums[i] < 0)
            {
                left = i;
                right = left + 1;
            }
        for (int i = 0; i < nums.size(); ++i)
            nums[i] *= nums[i];
        while (0 <= left || right < nums.size())
        {
            //此处分支语句似乎不能写在一块
            if (left < 0)
            {
                res.push_back(nums[right]);
                right++;
            }
            else if (right == nums.size())
            {
                res.push_back(nums[left]);
                left--;
            }
            else if ( nums[left] > nums[right])
            {
                res.push_back(nums[right]);
                right++;
            }    
            else
            {
                res.push_back(nums[left]);
                left--;
            }   
        }
        return res;
    }
};
```

小心几个坑爹的数据[1] [-1]和left和right的选取！

# P219

唯一解法 hash_table

```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        for(int i = 0;i < nums.size(); ++i)
        {
            if(m.find(nums[i]) != m.end()) //先找找表中有没有插入过这个元素，用find()接口！
            {
                int distance = i - m[ nums[i] ]; //计算距离
                if(distance <= k) //是否满足需要
                    return 1;
                else m[nums[i]] = i; //更新哈希表元素内容
            }
            else
                m[nums[i]] = i; //没有插入
        }
            return 0;
    }
};
```

# P125

熟悉C++中常见的字符串函数

```c++
class Solution {
public:
    bool isPalindrome(string s) 
    {
        int p = s.size()-1;
        for(int i = 0 ; i < p ;++i,--p)  //左指针 < 右指针 ,条件
        {
            while(i < p && !isalnum(s[i])  ) i++; //这里是while不
            									   //是if,常常会犯while写成if的毛病？？疑问
            while(i < p && !isalnum(s[p])  ) p--;
            if(toupper(s[i]) != toupper(s[p]) ) return false;
        }
        return true;
    }
};

//islower(char c) 是否为小写字母
//isupper(char c) 是否为大写字母
//isdigit(char c) 是否为数字
//isalpha(char c) 是否为字母
//isalnum(char c) 是否为字母或者数字
//toupper(char c) 字母小转大
//tolower(char c) 字母大转小
```





# 双指针算法总结

双指针的想法属于朴素的想法，容易想到，随意写出的代码能满足大部分测试案例，但是，细节上很容易出错，特别是对于数组下标越界的情况，数组中元素过少的情况下

1. 必要时考虑所有的分支情况
2. 考虑边界条件

## P228

![](E:\C-NoteBook\刷题记录\assets\image-20210122125740587.png)

### Solution1

```c++
class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> s;
        if (nums.size() == 0) return s;
        int flag2 = 0;
        //双指针中的一个隐藏在for循环里面
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i + 1 == nums.size() || nums[i] != nums[i + 1] - 1) //这里有几个坑
                //1.nums[i]+1可能回越界，因此必须写成nums[i+1] - 1
                //2.下标可能越界，因此在前面加一句单独判断是否i+1回越界
            {
                if (i == flag2) s.push_back(to_string(nums[i]));
                else
                    s.push_back(to_string(nums[flag2]) + "->" + to_string(nums[i]));
                flag2 = i + 1;//更新起始指针为i的下一个
            }
        }
        return s;
    }
};
```

### Solution2

```c++
class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> s;
        if (nums.size() == 0) return s;
        int p1 = 0;
        while(p1 < nums.size())
        {
            int  p2 = p1;
            while(p2 != nums.size() - 1 && nums[p2] == nums[p2 + 1]-1)
                p2++;
            //符合题意时，将其中的一个指针增加，知道不符合题意
            //不符合题意时，直接将元素输进字符串
            //注意下标和越界
            if( p2 == nums.size() - 1 || nums[p2] != nums[p2+1]-1)
            {
                if(p2-p1!=0)
                    s.push_back(to_string(nums[p1])+"->"+to_string(nums[p2]));
                else
                    s.push_back(to_string(nums[p2]));
                p1 = p2 + 1;
            }
        }
        return s;
    }
};
```

# P167

```c++
//这个题能用双指针？？？！！666

```



## P26

## P22(剑指offer)

![image-20210122153118240](E:\C-NoteBook\刷题记录\assets\image-20210122153118240.png)



## 链表逆置(剑指offer24、leetcodeP206)

//递归不会，到时候再说

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 三个指针，一个保存当前值，一个保存当前前面的值，一个保存当前后面的值，其原因是在调整指针指向的时候，pre和cur的联系会被斩断
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode * cur = head;
        ListNode * next = NULL;
        while(cur!=NULL)
        {
            ListNode *pre = cur->next;
            cur->next = next;
            next = cur;
            cur = pre;
        }
        return next;
    }
};
```

## 合并有序链表(LeetCodeP21)

//双指针我写不出来，TMD烦死了，不用那个哨兵节点巨麻烦，而且容易出错，边界不容易判断

//递归之后再说

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //技巧，哨兵节点的使用
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(0);
        ListNode* prev = cur;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val >= l2->val){
                prev->next = l2;
                l2 = l2->next;
            }else{
                prev->next = l1;
                l1 = l1->next;
            }
            prev = prev->next;
        }
        if(l1!=nullptr) prev->next = l1;
        else  prev->next = l2;
        return cur->next;
    }
};
```

# hash_table优化

## P3(剑指offer)

```c++

```

## P1(两数之和)

```c++
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			unordered_map<int, int>::iterator it = m.find(target - nums[i]);
			if (it != m.end())
                return{it->second,i};
            m.insert(make_pair(nums[i], i));
		}
		return {-1,-1};
	}
};
```

1. unordered_map是哈希表，不同于map的是他不是有序排列的，查找速度快
2. C++能返回不止一个数据啦！普天同庆
3. 将插入数据放在for的第一句在leetcode上得不到正确答案，离谱
4. hash的find函数时间复杂度是$O(1)$，离谱
5. map的key值不能取出（使用it->first会读写权限异常）



## P496

![image-20210130102259483](E:\C-NoteBook\刷题记录\sequence_list.assets\image-20210130102259483.png)

1. 暴力解法，就不贴了

```c++
//单调栈+hash_table
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)     {
        vector<int> res(nums1.size(),-1);
        stack<int> stk;
        unordered_map<int ,int> hash; 
        for(int i = nums2.size() - 1 ; i >= 0 ; --i )
        {
            while(!stk.empty() && nums2[i] >= stk.top())
                stk.pop();
            if( stk.empty() )
                hash[nums2[i]] = -1;
            else
                hash[nums2[i]] = stk.top();
            stk.push(nums2[i]); 
        }
        for(int i = 0 ; i < nums1.size() ; ++i)
        {
            if( hash.find( nums1[i] ) != hash.end() )
                res[i] = hash[ nums1[i] ];
        }
        return res;
    }
};
```

