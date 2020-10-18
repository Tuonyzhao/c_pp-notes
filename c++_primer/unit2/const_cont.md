#### const限定符

const int [对象名] =常量 or 其它；const对象一旦创建后，其值就不能再改变，所以const对象必须初始化。

```c++
int i=42;

const int ci=i; //正确，i的值被拷贝给了ci

int j=ci; //正确，ci的值被拷贝给了j;
```



注：ci的常量特征仅仅在执行改变ci的操作时才会发挥作用，当用ci去初始化j 时，根本无需在意ci是不是一个常量。

默认情况下，const对象被设定为仅在文件内有效，如果希望多个文件共享一个const对象，像其它非常量对象一样工作，解决的办法是，对于const变量不管是声明还是定义都添加extern关键字，这样只需定义一次就可以了：

```c++
//file1.cc定义并初始化了一个常量，该常量能被其它文件访问

extern const int bufSize=fcn();

//file1.h 头文件

extern const int bufSize;//与file1中定义的bufSize是同一个
```



#### const 引用

1。非常量引用不能指向一个常量对象

2。对常量的引用不能被用作修改它所绑定的对象

3。非常量引用不能引用常量

4.对const的引用可以引用一个非常量对象

3。引用的类型必须与其所引用的对象的类型一致，但有梁中意外：

1）第一种是初始化常量引用时，允许用任意表达式作为初始值，只要该表达式的结果能转换成引用的类型。但在类型转换时会产生一个临时量对象。所谓临时量对象就是当编译器需要一个空间来暂存表达式的值的时候临时创建的一个为命名的对象。例如：

```c++
double dval=3.14;

const int &ri =dval;
```

编译器把上述代码变成如下代码：

```c++
const int temp=dval;//这里const 不起作用，只在改变temp值的时候const才起作用

const int &ri=temp;
```

#### 指针和const

1.指向常量的指针可以指向非常量，但不可以通过常指针修改对象的值。

2.普通指针不可以指向常变量。

#### 顶层const

1.顶层const表示指针本身是一个常量，底层const,表示指针所指的对象是一个常量。指针类型既可以是顶层const,也可以是底层const。

2.更一般地，顶层const可以表示任意的对象是常量，对任意数据类型都适用。

例：

```c++
        int i=0;

​	int *const p1=&i;//不能改变p1的值，这是一个顶层const,可以通过 *p1改变对象的值，初始化后不可以再指向其它地址。

​	const int  ci=42;//不能改变ci的值,是一个顶层const

​	const int *p2=&ci;//p2是一个底层const,但不可以修改指向的对象的值。

​	const int *const p1=p2;//靠右的const是顶层const,靠左的const是底层const.表示既不能改变地址的值，也不能该表该指针所指的对象的值。
```

#### auto 和decltype

auto让编译器通过知道初始值来推算变量的类型，auto 定义时必须有初始值；decltype 希望表达式的类型推断出要定义的变量的类型，但是不想用表达式的值初始化变量。

```c++
decltype(f())sum=x;//sum的类型就是函数f的返回类型
const int ci=0,&cj=ci;
decltype(ci)x=0;//x的类型是const int
decltype(cj)y=x;//y的类型是const int&,y绑定到变量x
decltype(cj) z;//错误：z是一个引用必须初始化
```

```c++
const int ci-=i,&cr=ci;
auto b=ci;//b是一个整数，ci的顶层const特性被忽略了
auto c=cr;//c是一个整数，cr是ci的别名，ci是顶层const，被忽略了
auto d=&i;//d是一个整型指针，整数的地址就是指向整型的指针
auto e=&ci//e是一个指向整数常量的指针
```

auto一般会忽视顶层const特性，而保留底层const；decltype则不同，会保留顶层const 的特性，返回什么类型就声明什么类型。