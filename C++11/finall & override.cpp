#include <iostream>

using namespace std;

/*
    final: 用于修饰类与虚函数
        1. 修饰类： 该类无法被继承
        2. 修饰虚函数，该虚函数无法被重写
    override: 用于修饰虚函数
        被修饰的虚函数一定要重写父类的虚函数，否则报错
*/

class Test final
{
public:
    int a;
};
// 报错，声明final的类无法被继承
// class Son : public Test
// {
// };

class Father
{
public:
    virtual void test(const int a) final {}
    virtual int add(const int a, const int b) { return 0; }
};

class Child : public Father
{
public:
    // 子类中不能重写父类中声明final的虚函数
    // virtual void test(const int a) {}
    // 子类使用override修饰的虚函数一定要重写父类的虚函数，不能是重载
    virtual int add(const int a, const int b) override
    {
        return 1;
    }
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;

    return 0;
}