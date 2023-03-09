#include <iostream>

using namespace std;

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
    Test t = getObj(); // 因为getObj 返回的是右值，所以调用移动构造函数
    cout << "t.m_num: " << *t.m_num << endl;
    return 0;
};
