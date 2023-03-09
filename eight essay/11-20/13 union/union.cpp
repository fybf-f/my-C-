#include <iostream>
using namespace std;

/*
    1. 默认访问权限是public
    2. 可以含有构造函数于析构函数
    3. 不能含有引用类型的成员
    4. 不能继承其他类，也不能被其他类集成
    5. 没有虚函数
    6. 匿名联合在定义所在作用域可直接访问联合内的成员
    7. 匿名联合不能包含protected, private成员
    8. 全局匿名联合必须是静态的

*/

union UnionTest
{
    int i;
    double d;
    // 联合的构造函数
    UnionTest() : i(10){};
};

// 全局匿名联合
static union
{
    int i;
    double d;
};

int main()
{
    cout << endl;
    // 初始化一个联合对象
    UnionTest u;

    union
    {
        int i;
        double d;
    };

    cout << u.i << endl; // 输出 UnionTest 联合的 10

    ::i = 20;
    cout << ::i << endl; // 输出全局静态匿名联合的 20

    i = 30;
    std::cout << i << std::endl; // 输出局部匿名联合的 30

    return 0;
}
