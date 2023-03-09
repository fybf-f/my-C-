#include <iostream>
#include <string>
using namespace std;

/*
    1. 类与结构体最本质的区别是默认的访问权限
    2. 类的默认访问权限是private，因此适合构造对象
    3. 结构体的默认访问权限是public因此适合构造数据结构
*/

struct TestFather{
// 结构体中存在private修饰符
private:
    // int height;

public:
    string name;
    int age;
    // C++中的结构体允许函数，可以使用构造函数创建对象
    // 当当前结构体被继承时必须存在默认的构造函数
    // TestFather()
    // {

    // }
    TestFather(const string name, const int age)
    {
        // C++的结构中存在this指针
        this->name = name;
        this->age = age;
    }
    void print()
    {
        cout << this->name << ", " << this->age << endl;
    }
};
// 默认公有继承，但是指明继承方式可以增加代码可读性
struct TestChild : public TestFather  
{
    int id;
    TestChild(const int id) : TestFather("jhon", 20)
    {
        this->id = id;
    }
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    // 构造父亲结构体对象
    TestFather *tf = new TestFather("jhon", 20);
    tf->print();
    return 0;
}