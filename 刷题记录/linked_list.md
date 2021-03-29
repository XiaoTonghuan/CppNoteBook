# [LeetCode P21 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

1. 创建一个额外的指针用来串新表便
2. 一个元素被串上之后，对应指针应该增加
3. 用来穿线的指针向后移动一位
4. 注意使用dummy节点来使部分操作简单

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        else if(!l2) return l1;
        ListNode * dummy = new ListNode;
        ListNode * head = dummy;
        while(l1 || l2){
            if(!l2 || (l1 && l2 && l1->val < l2->val)){ //l2是空直接串l1，或者串两者中较大者
                head->next = l1;
                l1 = l1->next;
            }else if(!l1 || (l1 && l2 && l1->val >= l2->val)){  //同理
                head->next= l2;
                l2 = l2->next;
            }
            head = head->next; //串针后移
        }
        return dummy->next;
    }
};
```

# [LeetCode P24 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

1. 要点是设置三个指针分别指向前一个这一个和后一个

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* pre = NULL;
        while(cur){
            //上一次没完成的位移
            next = cur->next;
            //改变指向
            cur->next = pre;
            //指针位移
            pre = cur;
            cur = next; 
        }
        return pre;
    }
};
```

# [LeetCode P61旋转链表](https://leetcode-cn.com/problems/rotate-list/)

1. 实际上相当于从倒数第k个开始的链表

```c++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;  //空节点返回空
        int size = 0;
        ListNode* flag = head;
        while(flag){
            size++;
            if(!flag->next) {  //成环
                flag->next = head;
                break;
            }
            flag = flag->next;  
        }  //统计大小，并且定位flag为最后一个
        int idx = size - k > 0 ? (size - k ) % size: (size - k) % size + size;  //正数和倒数的关系
        while(idx){
            flag = flag->next;
            head = head->next;
            idx--;
        }  //查个数找到开始节点
        flag->next = nullptr;  //断开
        return head;
    }
};
```

