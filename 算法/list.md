# 练习

LeetCodeP206 单向链表反序

```c++
ListNode* reverseList(ListNode* head) 
{
    //三个指针：当前，下一个，上一个
    ListNode* curr = head; //当前为头
    ListNode* pre = NULL; //上一个应当为空
    while(curr!=nullptr) 
    {
        ListNode* ntp = curr->next; //更新下一个的位置
        curr->next = pre; //让curr指向他的上一个，同时打断了他和下一个的联系
        pre = curr; //更新下一个的位置
        curr = ntp; //更新当前的位置
    }
    return pre;
}
```

几个关键点：

- 当前和下一个的位置已经被打断，因此需要暂存下一个的位置。
- 关键在于更新几个指针的位置

```c++

```

