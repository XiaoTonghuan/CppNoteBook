# [LeetCode P236 最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

传入

1. root 一棵树的头节点
2. 目标p
3. 目标q

分析：有如下的情况

1. root == p 或者 root == q 一定能在他的子树中找到q或p
2. root != p && root != q 在其子树中寻找



边界条件分析

没找到返回空

找到了返回答案结点

左右的返回值都不为空时，表明这个结点就是答案

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == q || root == p) return root;
        TreeNode *lc = lowestCommonAncestor(root->left , p , q);
        TreeNode *rc = lowestCommonAncestor(root->right, p , q);


      if(lc && rc) return root;
      if(lc==nullptr) return rc;
      if(rc==nullptr) return lc;
        else
        return nullptr;
    }
};
```

# 输出到达某节点所经过的路径

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* q) {
        
        if(root == nullptr || root == q ) return root;  //找到或找不到
        TreeNode *lc = lowestCommonAncestor(root->left ,q);  //在左子树查找
        TreeNode *rc = lowestCommonAncestor(root->right,q);  //在右子树查找

        if(lc!=nullptr) { cout<<lc->val<<" "; return root;}  //左子树找到了，输出左子树的值
        else if(rc != nullptr ){ cout<<rc->val<<" "; return root;}  //右子树找到了，输出右子树的值
        else return nullptr;
    }
};
```

# [LeetCode 剑指offerP28对称二叉树](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/submissions/)

```c++
//水题一道，dfs秒过
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode * p, TreeNode *q)
    {
        if(!p && !q) return true;  //都为空说明到达递归最底层，并且在上面的层数中没有出现false，因此返回1
        else if(p && q && p->val == q->val) //该层镜像对称，搜索下一层
          	return dfs(p->left,q->right) && dfs(p->right,q->left);
        else return false;  //其他情况不合格
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left,root->right);
    }
};
```

# [LeetCode 剑指offer55 平衡二叉树](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/submissions/)

```c++
//水！好吧不是很水
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode * p ,int deep)  //深搜求树深度
    {
        if(!p) return deep - 1;  //空返回上一层深度
        else return max(dfs(p->left,deep + 1),dfs(p->right,deep + 1)); //否则这棵树的深度是左右子树中较大的那一个
    }
    bool isBalanced(TreeNode* root) {  //判断一棵树是否是平衡二叉树
        if(!root) return true;  //空树是平衡二叉树
        else
        {
            if(abs(dfs(root->left,1) - dfs(root->right,1)) <=1 )  //左右子树深度差<=1
                return (isBalanced(root->left) && isBalanced(root->right)); //继续查看他的左右子树是不是平衡二叉树
            else return false;//一个不是，整棵树就不是
        }
    }
};
```

# [LeetCode 剑指offer 27 生成镜像树](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/submissions/)

```c++
//水！
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createTree(TreeNode *& p, TreeNode *& q)
    {
        if(!q) p=nullptr;
        else{
            p = new TreeNode(q->val);
        createTree(p->left , q->right);
        createTree(p->right , q->left);
        }
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode * mirror = new TreeNode(root->val); //开辟新空间放原来的点
        createTree(mirror->left , root->right); //将原来树的右侧放到新树的左侧
        createTree(mirror->right , root->left); //将原来树的左侧放到新树的右侧
        return mirror;
    }
};
```

//实际上，你需要做的只是将这棵树遍历一遍就行了，每遍历到一个节点，就交换他们的左和右。这样就产生了镜像的效果

# [LeetCode P226 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)

这道题和上面的那道题一模一样

```c++
//先序
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->right);
        invertTree(root->left);
        return root;
    }
};

//中序
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        invertTree(root->left);

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);


        return root;
    }
};

//后序
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};


//层序
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* tmp = que.front();
            que.pop();
            
            if(tmp->left != nullptr) que.push(tmp->left);
            if(tmp->right != nullptr) que.push(tmp->right);

            TreeNode * l = tmp->left;
            tmp ->left = tmp->right;
            tmp -> right = l;

        }
        return root;
    
    }
};


//你甚至不用这些遍历的方式也行，只要你用某种方式能把所有的节点
```







# [LeetCode 剑指offer32 层序遍历输出](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/submissions/)

dfs

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode * root, int deep,vector<vector<int>>& res) //添加答案
    {
        if(!root) return;
        res[deep].push_back(root->val);
        dfs(root->left,deep+1,res);
        dfs(root->right,deep+1,res);
    }
    int level(TreeNode * root,int deep) //求树高
    {
        if(!root) return deep;
        return max(level(root->left,deep+1),level(root->right,deep+1));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res(level(root,0),vector<int>({}));
        dfs(root,0,res);
        return res;
    }
};
```

bfs

```c++
//可以增加一个计数器来统计这一层到底有几个结点，其他的是广搜模板
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> v;
            int cnt = q.size();  //计数器：我在这里！
            while(cnt)
            {
                TreeNode * tmp = q.front();
                v.push_back(tmp->val);
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                cnt--;
            }
            res.push_back(v);
        }
        return res;
    }
};
//我以为广搜会快点，没想到一样快。。。
```

# [Leetcode P32 层序遍历二叉树+](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/submissions/)

1. 奇偶逆序输出

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> res;
        bool flag = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> v;
            int cnt = q.size();  //计数器：我在这里！
            while(cnt)
            {
                TreeNode * tmp = q.front();
                v.push_back(tmp->val);
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                cnt--;
            }
            if(flag)   //判断奇偶层数
                reverse(v.begin(),v.end());
            flag = !flag;
            res.push_back(v);
        }
        return res;
    }
};
```

2. 双端队列

```c++

```





# [LeetCode 剑指offer 54 二叉搜索树的第k大节点]()

```c++
//水
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//大体思路是反中序遍历，刚开始以为是后序遍历函数名起的不对，不要在意这些细节！
class Solution {
public:
    int ans = 0;  //答案
    int cnt = 0;  //计数器
    void lastOrder(TreeNode* root , int k)  //传入一个结点和k
    {
        if(!root) return;  //空结点return，边界
        lastOrder(root->right,k);  //遍历右  
        cnt++; if(cnt == k) ans = root->val;  //遍历自己，cnt++;
        lastOrder(root->left,k);  //遍历左
    }   
    int kthLargest(TreeNode* root, int k) {
        lastOrder(root,k);
        return ans;
    }
};
```

# [LeetCode P965 单值二叉树](https://leetcode-cn.com/problems/univalued-binary-tree/submissions/)

真正的水题，怎么遍历都对

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool ans = true;
    int val;
    void dfs(TreeNode * root)
    {
        if(!root) return;
        if(root->val != this->val)
        {
            ans = false;
            return;
        }
        else
        {
            dfs(root->left);
            dfs(root->right);
        }
    }
    bool isUnivalTree(TreeNode* root) {
        this->val = root->val;
        dfs(root);
        return ans;
    }
};
```

# [LeetCode P653 两数之和4 输入BST](https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/)

```c++
//水！怎样遍历都可以
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> hash;
    bool findTarget(TreeNode* root, int k) 
    {
        if(!root) return false;
        if(hash.find(k - root->val)!=hash.end())
            return true;
        else
        {
            hash[root->val] = 1;
            return findTarget(root->left,k) || findTarget(root->right,k);
        } 
    }
};
```

# [LeetCode P1022 从根到叶的二进制数之和](https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/)

```c++
//草，这道题卡了
//1. 什么时候该累加：当是叶节点时，即左右子树都是空
//2. 二进制数和层数无关：比如一条路径0，1，0 二进制数是010 ，而不是01000000 //位数是树的层数
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void dfs(TreeNode*root , int ans)
    {
        if(!root) return;
        ans = ans*2 + root->val;
        TreeNode*&l = root->left;
        TreeNode*&r = root->right;
        if(l || r){
            dfs(r,ans);
            dfs(l,ans);
        }
        else{
            sum+=ans;
        }
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        dfs(root,0);
        return sum;
    }
};
```

# [LeetCode P404 左叶子节点之和](https://leetcode-cn.com/problems/sum-of-left-leaves/submissions/)

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum;
    void dfs(TreeNode * root , int pre)
    {
        if(!root) return;
        TreeNode *& l = root->left;
        TreeNode *& r = root->right;
        if(!l&&!r && pre){
            sum+=root->val;
            return;
        }else{
            dfs(l,1);  //传入左节点，标记这个节点为左节点
            dfs(r,0);  //同理
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};
```

# [LeetCode P572 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-tree/)

```c++
//呜呜呜,又卡了
//逻辑没理顺
//一个树是另一个树的子树等价于，这个树是左子树或者这个树是右子树
//然后通过深搜检测两棵树是否相同，两个都是空相同
//有且仅有一棵是空或者值不同不同
//都不是空且值相同检测左子树和右子树想不想同
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode * s ,TreeNode* t){
        if(!s && !t) return true;
        if( !t || !s || s->val != t->val ) return false;
        return dfs(s->right,t->right) && dfs(s->left,t->left);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        return dfs(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};
```

# [LeetCode P671 二叉树中第二个较小的数](https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/submissions/)

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//暴力解法就行了，用STL set或者map，遍历一遍树
class Solution {
public:
    map<int , int> seq;
    void dfs(TreeNode * root){
        if(!root) return;
        seq.insert(make_pair(root->val,1));
        dfs(root->left);
        dfs(root->right);
    }
    int findSecondMinimumValue(TreeNode* root)
    {
        dfs(root);
        auto it = ++seq.begin();
        if(it!=seq.end()) return it->first;
        else return -1;
    }
};
```

# [LeetCode P700 二叉搜索树中的搜索](https://leetcode-cn.com/problems/search-in-a-binary-search-tree/submissions/)

```c++
//奇怪的水题增加了
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//值比他大搜右树，小搜左树
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val == val) return root;
        else if(val < root->val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);

    }
};
```

# [LeetCode P100 相同的树](https://leetcode-cn.com/problems/same-tree/submissions/)

```c++
//板子题
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q || p->val != q->val)  return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);    
    }
};
```



# [LeetCode P112 路径总和](https://leetcode-cn.com/problems/path-sum/submissions/)

```c++
//有点像P1022
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode * root ,int ans, int targrt){
        if(!root) return false;
        ans+=root->val;
        if(ans == targrt && !root->left && !root->right) return true;  //叶子节点且结果相等就返回
        else return  //右或者左数+==target 那么符合题意 
        dfs(root->left , ans , targrt) || 
        dfs(root->right ,ans ,targrt);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return dfs(root,0,targetSum);
    }
};
```

# [LeetCode P104 最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

```c++
//板子题
class Solution {
public:
    int dfs(TreeNode*root , int deep)
    {
        if(!root) return deep;
        else return max(dfs(root->left,deep+1),dfs(root->right,deep+1));
    }
    int maxDepth(TreeNode* root) {
      return dfs(root , 0) ; 
    }
};
// p2
    int maxDepth(TreeNode* root) {
      if(!root) return 0;
      else return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
```

# [LeetCode P111 最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

```c++
//板子题变式
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode*root , int deep)
    {
        if(!root->right && !root->left) return deep;
        else if(root->left && root->right) return min(dfs(root->left,deep+1),dfs(root->right,deep+1));  //只有是叶子节点时才能确定深度
        else if(!root->left) return dfs(root->right,deep+1);
        else return dfs(root->left,deep+1);
    }
    int minDepth(TreeNode* root) {
      if(!root) return 0;
      return dfs(root , 1) ; 
    }
};
```

# [LeetCode P98 验证搜索二叉树](https://leetcode-cn.com/problems/validate-binary-search-tree/submissions/)

1. 蠢的一批的做法，没错就是我自己想的

```c++
class Solution {
public:
    bool dfsr(TreeNode*root , int val){  //查找根节点的左子树有没有比他大的树
        if(!root) return true;
        if(root->val > val) {
            return 
            dfsr(root->left , val) &&
            dfsr(root->right ,val); 
        }
        else    
            return false;
    }
    bool dfsl(TreeNode*root , int val){  //同理
        if(!root) return true;
        if(root->val < val) {
            return 
            dfsl(root->left , val) &&
            dfsl(root->right ,val); 
        }
        else    
            return false;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        else return
        dfsl( root->left , root->val) &&  //左面的数比他小
        dfsr( root->right , root->val) &&  //右面的比他大
        isValidBST(root->left) && isValidBST(root->right); //子树是搜索二叉树
    }
};
```

2. 中序遍历一定是升序

```c++
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(!root) return;  //边界
        inorder(root->left);  //遍历左树
        v.push_back(root->val); //加入序列
        inorder(root->right); //遍历右树
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i = 0 ; i < v.size()-1 ; ++i)
            if(v[i]>=v[i+1]) return false;
        return true;
    }
};
```

3. 遍历子树的时候顺便判断

```c++
class Solution {
public:
    bool helper(TreeNode* root , long upper , long lowwer){  //上限，下限
        if(!root) return true;
        if(root->val >= upper || root->val <= lowwer) return false;
        else return
        helper(root->left , root->val ,lowwer) && helper(root->right , upper , root->val);  //左树的上限改变，右树的下限改变
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MAX,LONG_MIN);  //注意测试数据有个越界的数据因此用LONG不用INT
    }
};
```

# [LeetCode P331 验证前序遍历序列](https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/)

很多解法，我大概只会暴力重建

```c++
//方法1：栈
//定义：槽位：当前二叉树中正在等待被填充的位置
/*
*槽位默认为2，如果填入空，槽位减，如果填入元素，槽位减，向栈中压入新槽位
*槽位为0弹出
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> place;
        place.push(1);  //放入一个空位
        int n = preorder.size();
        for(int i = 0 ; i < n ; ++i){
            if(preorder[i] == ',') continue; //如果上一个是‘#’，那么会在++i后执行这条
            else{
                if(place.empty()) return false;  //运行过程中空栈，不合题意
                else{
                    while(i < n && preorder[i]>='0' && preorder[i]<='9') ++i;  //读字符
                    //‘，’跳出是数字‘#’也可跳出
                    place.top()-=1;  //填充空位
                    if(place.top() == 0)
                        place.pop();
                    if(preorder[i] != '#')  //preorder是‘，’说明上一个读的是数字，‘#’停下，不填空位
                        place.push(2);
                }
            }
        }
        return place.empty();
    }
};




//方法2：计数 , 直接用计数器来保存空槽的数量
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int cnt = 1;
        int n = preorder.size();
        int i = 0;
        while(i < n){
            if(cnt == 0) return false;
            if(preorder[i] == ',') ++i;
            else if(preorder[i] == '#'){
                cnt--;
                ++i;
            }else{
                while(i < n && preorder[i] != ',') ++i;
                cnt++;
            }
        }
        return cnt==0;
    }
};

//出入度：树的出度==入度，前序遍历在最后的遍历完成之前入度>0
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int degree = 1;
        int n = preorder.size();
        int i = 0;
        while(i < n){
            if(preorder[i] == ',') {  //，直接跳过
                ++i;
            }
            degree--;  //入度，degree--
            if(degree < 0) return false;
            if(preorder[i] == '#'){  //‘#’直接跳了
                ++i;
                continue;
            } 
            while(i < n && preorder[i] != ',') ++i;  //不是‘#’，肯定是数字
            degree+=2;
        }
        return degree == 0;
    }
};

//分治：0s永远的神
/*s = "9,3,4,#,#,1,#,#,2,#,6,#,#"
*9是根节点，遍历左子树序列 "3,4,#,#,1,#,#,2,#,6,#,#",注意，此时并不知道右子树根节点
*对于"3,4,#,#,1,#,#,2,#,6,#,#"，3是根节点，继续遍历左子树序列，"4,#,#,1,#,#,2,#,6,#,#"
*对于"4,#,#,1,#,#,2,#,6,#,#"，4是根节点，继续遍历左子树序列，"#,#,1,#,#,2,#,6,#,#"
*对于"#,#,1,#,#,2,#,6,#,#"， #为根节点，为空。说明4左子树为空，此时遍历4的右子树"#,1,#,#,2,#,6,#,#"
*对于"#,1,#,#,2,#,6,#,#"，#为根节点，为空。说明4右子树为空，4为叶子节点，递归层返回，回到根节点为3的递归层"1,#,#,2,#,6,#,#"
*对于"1,#,#,2,#,6,#,#"，1为根节点，说明1是3的右子树根节点。遍历1的左子树"#,#,2,#,6,#,#"
*对于"#,#,2,#,6,#,#"，类似地，说明1是叶子节点。此时本递归层返回。回到根节点为9的递归层"2,#,6,#,#"
*对于"2,#,6,#,#"，2为根节点，说明2是9的右子树，访问2的左子树，"#,6,#,#"
*对于"#,6,#,#"，根节点为空，说明2的左子树为空，"6,#,#"
*对于"6,#,#",说明6是叶子节点，左右子树均为空。
*此时序列遍历完毕，任何一个子树都是有效的序列，所有返回true
*/
class Solution {
public:
    bool dfs(int &index,string& s){
        if(index == s.size()) return false;
        if(s[index] == ',') ++index;  //,跳过
        if(s[index++] == '#') return true; //#说明底层的左(右)子树遍历完成返回
        while(s[index] >= '0' && s[index] <= '9') ++index;
        return dfs(index,s) && dfs(index,s);
    }
    bool isValidSerialization(string preorder) {
        int index = 0;
        return dfs(index,preorder) && index == preorder.size();
    }
};
```

# BST(binary search tree)

- 重建搜索二叉树

Question：输入搜索二叉树的后续遍历结果，重建此二叉树，并返回他的头节点

```c++
struct TreeNode 
{
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() = default;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 TreeNode* CreatTree(int arr[], int L, int R)
 {
	 if (L > R) return nullptr;
	 TreeNode* head = new TreeNode(arr[R]);
	 int M = L - 1;
	 for (int i = L; i < R; i++)
		 if (arr[i] < arr[R])
			 M = i;
     //二分优化，不一定是完全有序才能使用二分，只要大体上有序就可以！
     /*	int M = L - 1;
	int right = R - 1;
	int left = L;
	while (right>=left)
	{
		int mid = left + ((right - left) >> 1);  //位运算那一段要加括号
		if (arr[mid] < arr[R])
		{
			M = mid;
			left = mid + 1;
		}
		else
		right = mid - 1;
	}*/
	 head->left  = CreatTree(arr, L, M);
	 head->right = CreatTree(arr, M + 1, R - 1);
	 return head;
 }
};
void PrintTree(TreeNode*head)
{
	if (head == nullptr) return;
	cout << head->val << endl;
	PrintTree(head->left);
	PrintTree(head->right);
}
int main()
{
	int arr[]{ 1,4,3,7,6,9,13,12,8 };
	TreeNode Tree1;
	TreeNode *Treehead = Tree1.CreatTree(arr, 0, 8);
	PrintTree(Treehead);
}
```

Test：[1,4,3,7,6,9,13,12,8]

# is Complete Tree

```c++
class Solution {
	bool isComplete( Tree_node<int>* root){
		/*
		* 1. 左右都不是空 ： 加进队列
		* 2. 左右都是空：false
		* 3. 右空左不空：false
		* 4. 左空右不空：之后所有的都是叶节点
		*/
		queue<Tree_node<int>* > que;
		que.push(root);
		int leaf = 0;
		while (!que.empty()) {
			Tree_node<int>* temp = que.front();
			if (leaf == 1) 
				if (temp->lc != nullptr || temp->rc != nullptr) 
					return false;
			if (temp->lc != nullptr) 
				que.push(temp->lc);
			if (temp->rc != nullptr)
				que.push(temp->rc);
			if (temp->lc == nullptr && temp->rc != nullptr)
				return false;
			else  //这里包含两种情况，一个是叶子节点的情况，另一个是左空右不空的情况
				leaf == 1;
			que.pop();
		}
		return true;
	}
};
```

其他写法

```c++
//其他写法
class Solution {
	bool isComplete( Tree_node<int>* root){
		/*
		* 1. 左右都不是空 ： 加进队列
		* 2. 左右都是空：false
		* 3. 右空左不空：false
		* 4. 左空右不空：之后所有的都是叶节点
		*/
		queue<Tree_node<int>* > que;
		que.push(root);
		int leaf = 0;
		while (!que.empty()) {
			Tree_node<int>* temp = que.front();
			if (leaf == 1) 
				if (temp->lc != nullptr || temp->rc != nullptr) 
					return false;
			if (temp->lc != nullptr)
				que.push(temp->lc);
			else if (temp->rc == nullptr)
				return false;
			if (temp->rc != nullptr)
				que.push(temp->rc);
			else //右是空，要求之后的节点都是叶
				leaf = true;
		}
		return true;
	}
};
```



