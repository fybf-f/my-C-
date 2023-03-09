#include <iostream>

using namespace std;

/*
    多态的三个必要条件
        继承关系
        需要重写
        向上传递
    C++ 多态分类及实现：
        重载多态（Ad-hoc Polymorphism，编译期）：函数重载、运算符重载
        子类型多态（Subtype Polymorphism，运行期）：虚函数
        参数多态性（Parametric Polymorphism，编译期）：类模板、函数模板
        强制多态（Coercion Polymorphism，编译期/运行期）：基本类型转换、自定义类型转换
    虚函数：用 virtual 修饰成员函数，使其成为虚函数
​    动态绑定：当使用基类的引用或指针调用一个虚函数时将发生动态绑定
    ​    可以将派生类的对象赋值给基类的指针或引用，反之不可
    ​    普通函数（非类成员函数）不能是虚函数
    ​    静态函数（static）不能是虚函数
    ​    构造函数不能是虚函数（因为在调用构造函数时，虚表指针并没有在对象的内存空间中，
        必须要构造函数调用完成后才会形成虚表指针）
​        内联函数不能是表现多态性时的虚函数，
*/

// 运行时多态
class Humen
{
public:
    // 纯虚函数
    virtual void name() = 0;
};

class Man : public Humen
{

public:
    virtual void name()
    {
        // 重写父类的纯虚函数
        cout << "ClassName = Man" << endl;
    }
};

class Women : public Humen
{
public:
    virtual void name()
    {
        cout << "ClassName = Women" << endl;
    }
};

void getHumen(Humen* h)
{
    h->name();
}


class Father
{
public:
    virtual void print(const string name)
    {
        cout << "Father : " << name << endl;
    }
};
class Child : public Father
{
public:
    virtual void print(const string name)
    {
        cout << "Child : " << name << endl;
    }
};

// 参数多态（编译时）
template <class T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    // 引用型多态
    Child c;
    Father &f = c;
    f.print("ccc");
    // 指针型多态
    Child cp;
    Father *fp = &cp;
    fp->print("aaa");
    Man m;
    getHumen(&m);
    // 参数多态（泛型）
    cout << ::max(9, 5) << endl; // 9

    string foo("foo"), bar("bar");
    cout << ::max(foo, bar) << endl; // "foo"

    return 0;
}