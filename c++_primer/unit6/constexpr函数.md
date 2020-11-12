  constexpr函数是指能用于常量表达式的函数。定义constexpr函数的方法于其他函数类似，不过要遵循几项约定：函数的返回类型及所有形参的类型都得是字面值类型，而且函数体中必须有且只有一条return语句：

```c++
constexpr int new_sz(){return 42;}
constexpr int foo =new_sz(); //正确foo是一个常量表达式

constexpr size_t scale(size_t cnt){ return new_sz()*cnt}//如果arg是常量表达式，则scale(arg)也是常量表达式
```

把内联函数和cosntexpr函数放在头文件中

​	和其他函数不一样，内联函数和constexpr函数可以在程序中多次定义。毕竟，编译器想要展开函数仅有函数声明是不够的，还需要函数的定义。不过，对于某个给定的内联函数或者constexpr函数来说，它的多个定义必须完全一致。基于这个原因，内联函数和constexpr函数通常定义在头文件中。