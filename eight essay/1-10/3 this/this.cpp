#include <iostream>
#include <string>
using namespace std;

/*
    1. this是存在于非静态成员函数的指针，指向调用成员函数的那个对象
    （相当于调用成员函数的当前对象）
    2. 当一个对象调用成员函数时，在编译期间先将对象的地址赋值给this。
    然后调用成员函数，每次成员函数存取非静态成员变量时都隐式的使用this指针
    3. 当一个成员函数被调用时，自动传递一个隐含的参数，该参数是一个指向这个成员函数所在对象的指针（C++ : this, python : self）
    4. this指针被隐含的声明为ClassName* const this，这意味着this是一个常量，不能被赋值
    同时也说明this指向的这种对象是不可修改的
    5. 区别于常规变量，this是一个右值，不能对其&this
    6. 为避免对同一对象进行赋值可以使用this
    7. 实现一些特殊结构使用this
*/

class test
{
public:
    // 普通成员函数
    int age;
    char sex;
    static string name;
    // 构造函数初始化对象

    test()
    {
        test(age = 0, sex = 'M');
    }

    test(int age, char sex)
    {
        // this只存在于非静态成员函数之间
        this->age = age;
        sex = sex;
    }
    void printInfo()
    {
        cout << age << endl;
    }
    static void static_get_info();
};

string test::name = "aaa";

void test::static_get_info()
{
    // 报错静态成员函数没有this
    // cout << this->age << endl;
    cout << name << endl;
}

int main()
{
    cout << endl;
    // 创建对象
    test t(20, 'F');
    // 输出对象的信息
    t.printInfo();
    // 输出类的信息
    t.static_get_info();

    cout << endl;
    return 0;
}