# What

$hash \quad container$ 指散列容器

# how

哈希表内部结构

![哈希表示意](E:\C-NoteBook\泛型编程\STL\assets\哈希表示意.webp)

- 当$bucket\,list$的数量超过$bucket\,vector$的数量的时候，会扩容
- $hash\,code$的计算：每一个$bucket\,list$都对应着一个$hash\,code$，这个$hash\,code$由系统通过指定的$hash\,function$来计算。