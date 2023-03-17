#include <iostream>

using namespace std;
/*
    抽象类：含有纯虚函数的类
    接口类：仅含有纯虚函数的抽象类
         ○ 派生类继承抽象类或者接口类时必须对基类中的所有纯虚函数进行重写，不然派生类仍是抽象类或者接口
    聚合类：用户可以直接访问其成员，并且具有特殊的初始化语法形式。
    满足如下特点：
         ○ 所有成员都是 public
    ​     ○ 没有定义任何构造函数
    ​     ○ 没有类内初始化
    ​     ○ 没有基类，也没有 virtual 函数

*/

class Interface
{
public:
    virtual void func() = 0;
    virtual void func1() = 0;
};

class Abstract
{
public:
    virtual void func() = 0;
    void func();
};

class AggregationClass
{
public:
    void swap() {}
    void add() {}
};

class Child : public Abstract
{
public:

};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    // Child c;
    return 0;
}