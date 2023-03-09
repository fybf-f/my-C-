#include <iostream>

using namespace std;

/*
    委托构造与继承构造
    委托构造： 使用重载的构造函数在初始化参数列表时帮助进行初始化
    继承构造： 子类直接使用父类的构造函数进行创建对象
*/

class Father
{
public:
    int age, length, id;
    Father(const int age) : age(age) {}
    // 使用委托构造，使用重载的构造函数帮助进行初始化
    // 使用委托构造的初始化参数列表中就不能使用其他初始化参数列表
    Father(const int length, const int id) : Father(22) {}
};
class Child : public Father{
public:
    // 委托构造，子类直接使用父类的构造函数创建对象
    using Father::Father;
};
int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    Child c(172, 21);
    cout << c.age << endl;
    return 0;
}