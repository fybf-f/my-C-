#include <iostream>

using namespace std;

/*
关于继承：
    1. 结构体默认继承是public,类默认是private
    2. 父类中的成员变量是属于父类的，
       也就是说子类继承过来的成员变量只能由父类进行初始化
       哪怕是子类构造函数对继承过来的成员变量初始化也不行 
    3. 子类在继承父类时会默认调用父类的默认构造函数进行初始化
       
    4. 因此当我们的父类的构造函数已经自定义时，
       子类继承时需要显式调用父类的构造函数
    5. 语法见Child的构造函数

*/


class Father
{
private:
    int weight = 50;

public:
    string name;
    int age;

    // 自定义构造函数，编译器不在提供默认的构造函数
    Father(const string name, const int age)
    {
        this->name = name;
        this->age = age;
    }

    void print()
    {
        cout << this->name << ", " << this->age << endl;
    }
};

class Child : public Father
{
public:
    int id;
    // 子类需要显示调用父类的构造函数！！！
    Child(const int id, string name, int age) : Father("Anna", 20)
    {
        this->id = id;
        this->name = name;
        this->age = age;
    }
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;

    return 0;
}