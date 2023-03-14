#include <iostream>

using namespace std;

/*
    1. 在菱形继承中存在二义性问题，使用作用域能够在一定程度上进行区分
    2. 可以使用虚继承进行解决
    3. 虚继承实现原理：
        # 普通继承会将基类中的内容拷贝一份在子类中，
          如果派生过多，就会导致浪费存储空间和二义性问题（菱形继承）
        # 虚继承底层实现原理与编译器相关，通过虚基类指针和虚基类表实现，
          每个虚继承的子类都有一个虚基类指针（占用一个指针的存储空间，4字节）
          和虚基类表（不占用类对象的存储空间）
          （需要强调的是，虚基类依旧会在子类里面存在拷贝，
          只是仅仅最多存在一份而已，并不是不在子类里面了）；
          当虚继承的子类被当做父类继承时，虚基类指针也会被继承。
        # 当派生类想要访问父类中的成员就能通过指针偏移实现（两个问题，多态实现原理类似，为什么不将这两个指针合并）
        # 在不同编译条件下C++实现多态存在区别，msvc上虚函数表与虚基类表是不同的，mingw是相同的
        # msvc: 当虚继承的基类含有虚函数时，派生类会继承两个指针：虚函数表指针（指向虚函数表），虚基类指针（指向虚基类表）
        # mingw: 无论虚继承的基类是否含有虚函数，派生类只会继承一个指针，虚基类指针，因此实现多态只靠虚基类指针偏移
*/

class Father
{
public:
    int num;
    virtual void func(){};
};

class Son1 : public Father
{
public:
    int son1_id;
    int all = 10;
};

class Son2 : public Father
{
public:
    int son2_id;
    int all = 20;
};

class Test : public Son1, public Son2
{
public:
    // num = 10;  报错，二义性，不知道num是Son1的还是Son2的
    // 使用作用域能够解除二义性
    int self_id;
    Test()
    {
        this->self_id = Son1::num;
        // cout << this->all << endl;
    }
};

class A
{
public:
    int father_id = 10;
};

// 虚继承基类
class a1 : virtual public A
{
public:
    int a1_id;
    a1()
    {
        this->father_id = 20;
    }
};

class a2 : virtual public A
{
public:
    int a2_id;
    a2()
    {
        this->father_id = 30;
    }
};

class b : public a1, public a2
{
public:
    b() : a1(), a2()
    {
        // 不会报错
        cout << this->father_id << endl;
    }
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    b ob;
    return 0;
}