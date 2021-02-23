# 初始化字符串
```c++
string str;// 啥也不写，一个空字符串
const char * s ="Hello,World";
string str(s); //传入一个字符指针
string str("jdskajdska");//直接写入一个字符串
string str(5,'l'); //指定字符的个数。
string s = "Hello,World"; //利用等号
string str(s); //拷贝构造函数
```
# 赋值
```c++
//使用等号赋值
string str;
string s1 = "dasdas";
str = 's';
str = "hello";
str = s1;
//使用函数赋值
str.assign(s1);
str.assign("asda");
str.assign('s'); //不对！
str.assign("dasda",3) //只赋值字符串的前三个
str.assign(5,'d'); //将字符串的前五个赋值为d
```
# 拼接
```c++
string str;
string str2;
const char *str1 ="dasdasd";
//重载+=
str+='s'//接字符
str+=str1;//接C风格字符串
str+=str2;//接C++字符串
//直接使用函数
str.append('s');
str.append("sss");
str.append("dassdadsa",5); //截取前5个；
str.append("adadsd",0,4); //从第0个开始，截取前4个。
```
# 查找
```c++
string str = "dasdadsasdasdfsc";
str.find("da"); //从左向右查找，返回下标。
str.rfind("da"); //从右向左查找，返回下标，找不到返回-1；
```
# 替换
```c++
string str = "dasdadsasdasdfsc";
str.replace(3,3,"oijutt");//。将从3起长度为3的空间替换为oijutt。
```
# 比较
```c++
string str1 ="hello";
string str2 = "world";
str1.compare(str2);//相等返回0，前面单个字符ASC大返回值>0，后面单个字符ASC码大返回值<0。
```

# 读取
1. 直接通过[i]的方式来读取第i个。
2. 通过s.at(i)来读取第i个。

# 插入和删除
```c++
string str = "Hello";
str.insert(1,"dada");//0和1之间，插入dada。
str.erase(1,3);从第一个位置开始，删除3个。
```

# 字串获取

```c++
string str = "Hello";
str.sbustr(1,3);//从第1个位置开始，截取3个长度。
```