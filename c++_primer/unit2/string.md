### string



1. string 对象初始化的方式：

   ```c++
   string s1;//默认初始化，s1是一个空字符串
   string s2=s1;//s2是s1的一个副本
   string s2(s1);//s2是s1的副本,等价于上式
   string s3="hiya";//s3是该字符串字面值的副本
   string s3("hiya");//s3是字面值"hiya”的副本，等价于上式
   string s4(10,'c');//s4的内容是cccccccccc，会产生一个临时对象用于拷贝
   ```

2.string对象的操作：

```c++
os<<s;//将s写到输出流os中，返回os
is>>s;//从is中读取字符串赋给s,字符串以空白分隔
getline(is,s);//从is中读取一行赋给s,返回is
s.empty();//s为空返回true,否则返回false
s.size();//返回s中字符的个数
s[n];//返回s字符中第n个字符的引用
s1+s2;//返回s1和s2连接后的结果
s1=s2;//用s2的副本代替原来的字符
>=,<=,<,>,==,!=;//string 对象的比较"hiya">"helloworld"
```

3.string 对象需要using 和include声明

4.string中cin与getline 区别:因string对象用空白符分隔，所以cin中空格之后读取不到或报错；getline 用回车符分隔，所以输入中可包含空格。

5.string 对象的函数返回的是无符号整型的类型，名为string::size_type,string类及其它大多数标准库类型都定义了几种配套的类型

6.c++标准库中，允许把字符字面值和字符串字面值转换成string对象，但当string对象和字符字面值或字符串字面值混在一条语句时，必须确保'+'运算符两边至少有一个是string 对象。不能把字面值直接相加。

```c++
string s1="hello",s2="world";
string s3=s1+","+s2+'\n';//正确
string s4="hello"+','+s3;//错误
```

### cctype头文件处理string对象中的字符

改变string中某个字符的特性，在cctype头文件中定义了一组标准库函数处理这部分工作。

```c++
isalnum(c);//c是字母或数字返回真
isalpha(c);//字母
iscntrl(c);//控制字符
isdigit(c);//数字
isgraph(c);//当c不是空格但可打印为真
islower(c);//小写字母
isprint(c);可打印（空格或c具有可视化形式）
ispunct(c);//可打印字符
isspace(c);空白
isupper(c);大写字母
isxdigit(c);16进制数字
tolower(c);//输出小写字母
toupper(c);//输出大写字母
```

### c++11标准范围for(range for )语句

```c++
for(declaration:expression)
		statement
```

expression 表示为一个对象，表示为一个序列，declaration部分负责定义一个变量，改变量用于访问序列中的基础元素。每次迭代，declaration部分的变量会被初始化为expression部分的下一个元素值。

```c++
string str("some string");
for (auto c:str)
	cout<<c<<endl;
```

如果想改变序列中的元素，必须把循环变量的类型改为引用，当使用引用作为循环控制变量时，这个变量实际上已经依次绑定到序列中的每一个元素了。

```c++
string str("some string");
for (auto &c:str)
	c=toupper(c);
```

