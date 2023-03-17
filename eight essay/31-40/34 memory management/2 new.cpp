#include <iostream>
#include <vector>
using namespace std;

/*
    new与malloc的区别：
    # new是运算符， malloc是函数包含在stdlib.h的文件夹下
    # new里面先调用malloc申请空间（自动计算空间）， 在调用构造函数实例化对象
    # new返回的是一个对象的指针不需要强制类型转换， malloc返回void*需要强制类型转换
    # new申请空间不需要传入空间大小（自动计算）， malloc需要传入空间大小
    # new使用delete/delete[]运算符释放空间， malloc使用free函数释放空间
    new是一个关键字，使用new编译器会调用两个函数，operator new()和构造函数
        operator的底层实现原理是使用malloc申请堆区控件，当然可以重载operator new使之
    在栈区或者其他地方申请空间，返回void*
        placement new也可以创建对象，但是不会分配内存，只能在已有地内存上显式分配空间
        placement new允许我们向new传递额外地地址（缓冲区地指针）（内存复用）
    从而在指定地内存区域创建对象，
        new (place_address) type  // place_address 是个指针
        new (place_address) type (initializers) 
        // initializers 提供一个（可能为空的）以逗号分隔的初始值列表
        new (place_address) type [size]
        new (place_address) type [size] { braced initializer list }
    当我们使用placement new时，最好重载operator new[], operator delete, 
        operator delete[]
    delete this:
        合法
*/

class Test
{
public:
    int id;
};

int main()
{
    char p[20];
    Test *t = new (p)Test();  // 使用palcement new创建一个栈区对象
    cout << 111 << endl;
    return 0;
}















