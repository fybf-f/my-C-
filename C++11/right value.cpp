#include <iostream>

using std::cout;
using std::endl;

int &&value = 520; // 右值引用，520是字面量，是右值

class Test
{
public:
    Test()
    {
        cout << "构造函数" << endl;
    }
    Test(const Test &a)
    {
        cout << "拷贝构造函数" << endl;
    }
    ~Test()
    {
        cout << "析构函数" << endl;
    }
};

Test getObj()
{
    Test t;
    return t;
}

/*
// 此代码应该在不同编译器中多运行运行
#include <iostream>

using std::cout;
using std::endl;

class Test
{
public:
    Test() : m_num(new int(100))
    {
        cout << "构造函数" << endl;
    }

    Test(const Test &a) : m_num(new int(*a.m_num))
    {
        cout << "拷贝构造函数" << endl;
    }

    // 添加移动构造函数，参数是右值引用
    Test(Test &&a) : m_num(a.m_num)
    {
        a.m_num = nullptr;
        cout << "移动构造函数" << endl;
    }

    ~Test()
    {
        delete m_num;
        cout << "析构函数" << endl;
    }

    int *m_num;
};

Test getObj()
{
    Test t;
    return t;
}

int main()
{
    int a1;
    // int &&a2 = a1;        // 报错 右值引用不能被左值初始化
    // Test& t1 = getObj();   // 右值不能初始化左值引用
    Test &&t2 = getObj();      // 函数返回的临时对象是右值，可以被引用
    const Test &t3 = getObj(); // 常量左值引用是万能可以接收左值，右值，常量左值，常量右值
    const int &t4 = a1;        // 被左值初始化
    int *p = &value;
    // p++;
    cout << *p << endl;
    return 0;
}
*/

int main()
{
    int a1;
    // int &&a2 = a1;        // 报错 右值引用不能被左值初始化
    // Test& t1 = getObj();   // 右值不能初始化左值引用
    Test &&t2 = getObj();      // 函数返回的临时对象是右值，可以被引用
    const Test &t3 = getObj(); // 常量左值引用是万能可以接收左值，右值，常量左值，常量右值
    // const int &t4 = a1;        // 被左值初始化
    // int *p = &value;
    // p++;
    // cout << *p << endl;

    return 0;
}
