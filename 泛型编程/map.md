# What

- 每一个元素，都是一个对组。
- 插入元素会根据key自动排序。
- 底层和set一样，是二叉树

# 接口

1. 构造函数

   - ``map<T1,T2> m;``

   - ``map m(m1);``

2. 插入删除

   - ``m.insert(pair<T1,T2>(elem1,elem2))``
   - ``m.insert(make_pair(elem1,elem2))``
   - ``m.insert(map<T1,T2>::value_type(elem1,elem2))``
   - ``m[key] = elem``
   - ``m.erase(key)``删除key值所代表的数据
   - ``m.erase(beg,end)``按区间进行删除
   - ``m.erase(value)``删除值符合的元素
   - ``m.clear()``清空map

3. 大小和交换

   - ``m.size()``

   - ``m.swap(m1)``

   - ``m.empty()``

4. 查找和统计

   - ``m.find(elem)``找到值符合的元素返回迭代器，找不到返回end
   - ``m.count(elem)``统计，返回值为0或者1

   