# What

- 静态的数组

- 类似于``int a[100],char c[100]``

# How

```c++
array<int,10> a{1,2,3,4,5,6,7,8,9,10};
array<string,3> b{"io","re","djn"};
for(int i : a) cout <<i<<endl;
for(string i : b) cout <<i<<endl;
```

