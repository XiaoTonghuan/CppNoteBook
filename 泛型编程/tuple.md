# What

- 中文译名：元组

# How

常用接口

```c++
auto t0 = make_tuple("sdkla",5,3.14);
tuple<int,double,char,int,int> t1(3,5,'u',5,8);
tuple<int,double,char,int,int> t2;
//构造
get<0>(t1) = get<1>(t0);
cout<<get<0>(t1)<<get<1>(t0)<<endl;
//取得元素
//t2 = t0; 可以将tuple直接赋值，但是类型得一样
string s1; int n1; double d1;
tie(s1,n1,d1) = t0; 
//给这三个赋值
cout<<tuple_size<tuple<string,int,double>>::value<<endl; //输出大小
tuple_element<1,tuple<int,int>>::type n2 = 9; //取得里面的元素类型
```