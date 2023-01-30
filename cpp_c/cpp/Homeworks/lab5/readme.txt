运行方式
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make
./lab5.exe

修改文件
UnaryOP.h:
    增加了Tan类定义，作为UnaryOP的子类，用于计算正切函数与求导
    增加了Ln类定义，作为UnaryOP的子类，用于计算自然对数函数与求导
    增加了Exp类定义，作为UnaryOP的子类，用于计算以e为底数的指数函数与求导
UnaryOP.cpp:
    为以上三个类分别定义构造函数，析构函数，求值函数，求导函数（仅假设参数只有变量X），转字符串函数，复制构造函数
BinaryOP.h:
    增加了Power类定义，作为BinaryOP的子类，用于计算幂函数与求导
    增加了Log类定义，作为BinaryOP的子类，用于计算对数与求导
BinaryOP.cpp:
    为以上两个类分别定义构造函数，析构函数，求值函数，求导函数，转字符串函数，复制构造函数
Operation.h:
    增加了tan，ln，exp，power，log函数的声明，用于将某一种操作转化为对应的一元/二元操作符所对应的类
Operation.cpp:
    增加对tan、ln、exp函数的定义：如果有变量则返回一个Variable的子类，如果没有变量则返回一个Constant子类
    增加对power，log函数的定义：排除了一些没有定义的情况，根据变量的位置（左值或右值）进行不同的返回。
Expression.h:
    增加对tan、ln、exp、符号^，log的定义，使其可以直接用在main函数的表达式书写中。
Expression.cpp:
    增加上述函数的定义，利用Operation.h中的函数将表达式转换为各个表达式类。
