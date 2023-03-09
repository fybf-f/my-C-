#include <iostream>
#include <string>
using namespace std;

/*
    1. 当的成员访问权限是private时，
       当且仅当当前类内才能进行访问
    2. 通过友元类与友元函数能够访问类的私有成员
    3. 使用友元破坏了类的封装性
    4. 友元关系是不可传递的
    5. 友元是单向的
    6. 声明友元的形式与数量不受限制

*/

class Test
{
private:
    // 私有成员变量
    int age = 40;
    string local = "here";

public:
    string name;
    // 类中声明友元函数
    friend void print(Test &test);
    // 类中声明友元类
    friend class Friend;
};

class SubTest : public Test
{
private:
    int tel;
};

// 友元类Friend能够访问类Test中的私有成员，但是不能访问他的子类
class Friend
{
private:
    string name;

public:
    // 声明友元的类的对象成员变量
    void print(Test &test)
    {
        cout << "age = " << test.age << endl;
    }
    void sub_print(SubTest &sub_test)
    {
        // 友元关系无法继承
        // cout << sub_test.tel;
    }
};

class SubFriend
{
    public:
    void out_put(Test& test)
    {
        // 友元关系无法得到继承
        // cout << test.age;
    }
};

// 实现友元函数
void print(Test &test)
{
    cout << test.age << endl;
    cout << test.local << endl;
}

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    // 初始化声明友元的对象
    Test t;
    t.name = "aaa";
    // 使用友元函数访问私有成员
    print(t);
    // 使用友元类访问私有成员
    Friend f;
    f.print(t);
    return 0;
}