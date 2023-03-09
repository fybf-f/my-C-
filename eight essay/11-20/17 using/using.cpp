#include <iostream>
// 这是一条using指示，说明导入的头文件以及stl都是在std命名空间下的      
// using namespace std;

using std::cout;
using std::endl;
using std::string;
/*
    1. using引入命名空间
        每个人可以在自己的命名空间下进行代码的书写
        能够解决变量、函数、类、结构体等等重名的问题
    2. 子类重用其直接父类定义的构造函数
       编译器都生成一个与父类对应（形参列表完全相同）的子类构造函数。

*/

// 自定义命名空间
namespace myself
{
    string name = "lzh";
    int id = 21;
}

class Father
{
private:
    int age;

public:
    string name;
    Father(const int age, const string name) : age(age), name(name) {}
};

class Child : public Father
{
public:
    using Father::Father;
    char sex;
    // Child(const char sex) : sex(sex) {}
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    // 输出局部变量id，使用::访问命名空间下的id
    int id = 100;
    cout << id << " " << myself::id << endl;
    cout << " --------------" << endl;
    Child c(10, "abc");
    // 这是一条using声明
    std::cout << c.Father::name << endl;
    return 0;
}