# 常用遍历算法

## for_each

```c++
for_each(v.begin(),v.end(),Myprint()); //传仿函数
for_each(v.begin(),v.end(),Myprint);//传普通函数
void Myprint(int val)
{
    cout<<val<<" ";
}
class Myprint
{
    void operator()(int val)
    {
        cout<<val<<" ";
}
};
```

## tansform

```c++
class Tansform
{
    int operator()(int val)
    {
        return val;
 	}
};
int main()
{
    //将v中的数据搬运到vTar中。
    vector<int> v;
    vector<int> vTar;
    vTar.resize(v.resize());
    tansform(v.begin(),v.end(),vTar.begin(),Tansform());
}
```

# 常用查找算法

- ``find_if(beg,end,perd)``

- ``find(beg,end,elem)``（必须要重载=）

- ``adjcent_find(beg,end)``（查找相邻重复元素）
- ``binary_search(beg,end,val)``
  1. 只能查找有序序列
  2. 返回值是bool，不是迭代器
- ``count(beg,end,val)``返回数据出现的次数
- ``count_if(beg,end,val,perd)``

# 常用的的排序算法

- ``sort(beg,end,perd)``
- ``random_shuffle(beg,end)``随机打乱
- ``merge(beg1,end1.beg2,end2,beg_tar,perd)``合并两个有序序列，合并完成之后还是有序的
- ``reverse(beg,end)``逆置

# 拷贝和替换算法

- ``copy(beg,end,Tbeg)`` 提前给目标容器开辟空间
- ``replace(beg,end,Tval,Newval)``将指定范围内的旧元素修改为新元素
- ``replace_if(beg,end,perd,val)``根据条件替换数值
- ``swap(s1,s2)``显然不能交换不同类型的容器

# 算术生成算法

- ``numeric``

- ``accumulate(beg,end,start)`` 将一个容器里的值累加到start上面，返回一个start类型的和.
- ``fill(beg,end,val)``填充，将区间内的值替换为val，常用于后期重新指定值

# 常用集合算法

- 交集 ``set_intersection(beg1,end1,beg2,end2,beg_tar)``返回交集的结束迭代器。(只能对有序序列使用)
- 并集``set_union(beg1,end1,beg2,end2,tar_beg)``同样，返回并集结束位置的迭代器
- 差集``set_difference(beg1,end1,beg2,end2,tar_beg)``求1和2的差集









