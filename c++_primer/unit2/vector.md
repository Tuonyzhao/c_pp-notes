### 标准库类型vector

标准库类型vector表示对象的集合，其中所有对象的类型都相同。

以vector为例，提供的额外信息是vector内所存放的对象的类型：

```c++
vector<int> ivec;  //保存int类型的对象
vector<Sales_item> Sales_vec; 保存Sales_item类型的对象
vector<vector<string>> file; //该向量的元素是vector对象
```

### 定义和初始化vector对象

初始化vector对象的方法：

```c++
vector<T>  v1;// v1是一个空vector,它潜在的类型是T类型的，执行默认初始化
vector<T> v2(v1);//v2中包含v1所有元素的副本
vector<T> v2=v1;//同v2(v1)
vector<T> v3(n,val);//v3包含了n个重复的元素，每个元素的值的都是val
vector<T>v4(n);v4包含了重复地执行了值初始化的对象
vector<T> v5{a,b,c...};//v5包含了初始值个数的元素，每个元素被赋予相应的初始值。
vector<T> v5={a,b,c...};//等价于v5{a,b,c...}
int a[]={1,2,3,4,5};vector<int> cc(a,a+sizeof(a));//用数组来初始化vector
```

### 列表初始值还是元素数量？

在某些情况，初始化的真实含义依赖于传递初始值时用的是花括号还是圆括号；一般情况下，圆括号是用来构造vector对象的，方括号是用来列表初始化vector对象的。

```c++
vector<string> v1{"a","an","the"};//列表初始化
vector<string> v2("a","b","c");//错误，列表初始化不能放在圆括号里
vector<int> ivec(10,-1);//10个int类型的元素，每个都被初始化为-1

vector<int> ivec(10);//10个元素，全部都初始化为0
vector<string> svec(10);//10个元素，每个都是空string对象

```

但是在花括号时，有一种特殊情况，就是在使用了花括号的形式，但提供的值又不能用来列表初始化，就要考虑用这样的值来构造vector对象了。

```c++
vector<string> v5{"hi"};//列表初始化，v5有一个元素
vector<string> v6("hi");//错误，圆括号不能使用字面值来构造vector对象
vector<string> v7{10};//v7有10个默认初始化的元素
vector<string> v8{10,"hi"};//v8有10个默认初始化为"hi"的元素
```

### 向vector对象中添加元素

创建一个空vector对象，使用vector类的成员函数push_back(参数)；push_back的作用是负责把一个值当成vector对象的尾元素“压到push”vector对象的尾端

```c++
2vector<int> v2;
f or(int i=0;i!=100;i++)
	v2.push_back(i);
	
string word;
vector<T> text;
while(cin>>word){
	text.push_back(word);
}
```

如果循环体内部包含有向vector对象添加元素的语句，则不能使用范围for循环。

### 其它vector操作

除了push_back以外，vector还提供了集中其它操作，大多数和string的相关操作类似。

vector支持的操作：

```c++
v.empty(); //如果不包含任何元素，返回真；否则返回假
v.size();//返回v中元素的个数
v.push_back(t);//向v的尾端添加一个值为t的元素
v[n] //返回v中第n个位置上元素的引用
v1=v2; //v2中的元素拷贝替换v1中的元素
v1={a,b,c...} //将列表中的元素拷贝替换到v1中
```

不能通过下标的方式添加vector元素，如果vector是空vector，则里面一个vector都没有。

