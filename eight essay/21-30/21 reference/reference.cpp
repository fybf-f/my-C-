#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
    引用:
        引用实体和引用类型必须为同种类型
        引用在定义时必须初始化并且不能被初始化为NULL
        不可以改变引用关系
    右值引用：
        右值引用就是对右值引用的类型。因为右值是匿名的，所以我们只能通过引用的方式找到它。
        无论是左值引用还是右值引用都必须被初始化，
        因为引用类型本身并不拥有所绑定对象的内存，只是该对象的一个别名。
        通过右值引用，该右值所占的内存又可以被使用。
        右值引用可实现转移语义（Move Sementics）和精确传递（Perfect Forwarding），它的主要目的有两个方面：
            消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率。
            能够更简洁明确地定义泛型函数。
            


*/

class Test
{
public:
    // 有参数的构造函数
    int size;
    Test(const int size, 
        const int age):size(size), heap_ptr(new int[this->size]), age(age)
    {
        cout << "有参数的构造函数" << endl;
    }
    // 拷贝构造函数:深拷贝的拷贝构造函数
    Test(const Test& t)
    {
        this->heap_ptr = new int[t.size];
        cout << "拷贝构造函数" << endl;
    }
    // 通过右值引用实现移动构造函数: 浅拷贝
    Test(Test&& t)
    {
        this->heap_ptr = t.heap_ptr;
        t.heap_ptr = nullptr;
        cout << "移动构造函数" << endl;
    }
    // 析构函数
    ~Test()
    {
        delete heap_ptr;
        cout << "执行析构函数" << endl;
    }

private:
    // 在堆上申请size大小的数组
    int *heap_ptr;
    int age;
};

Test getTest()
{
    Test t(100, 10);
    return t;
}

int main()
{
    cout << "----------" << endl;
    Test t = getTest();
    cout << "----------" << endl;
    cout << t.size << endl;
    return 0;
}
