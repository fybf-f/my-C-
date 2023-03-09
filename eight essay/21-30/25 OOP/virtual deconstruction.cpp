#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    虚析构：
        析构函数是作用于对象（堆区、栈区）销毁工作，清空对象内部指针指向的的堆区内存。
        析构函数是在释放对象的时候自动调用，栈区对象自动释放，
        堆区对象手动释放delete才会调用析构函数。

*/

class Father
{
public:
    // 创建一个堆区vector
    vector<int>* vec = new vector<int>(100);
    virtual void print(const string name) 
    {
        cout << "父类的print函数，打印 ：" << name << endl;
    }
    // 如果父类的析构函数不是虚函数，子类存在虚析构函数
    // 那么在释放父类指针时，仍然不0会释放子类中申请的堆区内存
    ~Father()
    {
        delete vec;
        vec = nullptr;
        cout << "父类的虚析构函数" << endl;
    }
};

class Child : public Father
{
public:
    
    virtual void print(const string name)
    {
        cout << "子类重写的print函数， 打印： " << name << endl;
    }
    // 如果子类的析构函数不是虚函数，那么在释放父类指针时，不会释放子类中申请的堆区内存
    virtual ~Child()
    {
        delete vec;
        vec = nullptr;
        cout << "子类的虚析构函数" << endl;
    }
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    Father *f = new Child();
    f->print("aaa");
    // 销毁堆区对象需要使用delete才会调用虚析构函数
    delete f;
    return 0;
}