#include <iostream>

using namespace std;

/*
    1. 初始化参数列表是C++11里面的特性
    2. 初始化参数列表中，成员初始化次序与它们在类中的声明次序相同，
       与初始化参数列表中的次序无关。
    3. 数据成员的执行次序为： 类内初始 > 初始化参数列表 > 构造函数体
    4. 常量成员、引用成员必须使用初始化列表进行初始化，
       因为常量和引用只能初始化不能赋值，没有默认构造的类作为父类时，
       子类必须在初始化参数列表中创建父类
*/

class Other
{
public:
    int num;
    Other(const int num)
    {
        this->num = num;
    }
};

class Father
{
private:
    const string name = "l";

public:
    int age;
    Father(int const age) : age(age)
    {
    }
};

class Child : public Father
{
public:
    // Father f(10);
    int id;
    // Father f(1)
    // 在创建其他类对象时必须在初始化参数列表中对声明的对象进行初始化
    Other o;
    Child(const int id) : id(id), Father(10), o(10)
    {
    }
};

class Test
{
private:
    int i, j;

public:
    Test() : j(10), i(j)
    {
        cout << i << " " << j << endl;
    }
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    Test t;
    return 0;
}