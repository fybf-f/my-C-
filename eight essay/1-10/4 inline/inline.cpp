#include <iostream>
#include <vector>
using namespace std;

/*
    内敛函数：
        1. 相当于把内联函数的内容直接写在函数的调用处；
        2. 相当于不用执行进入函数的步骤，直接执行函数体
        3. 相比于宏函数多了参数类型检查，具有真正的函数特性
        4. 是否内联大多由编译器决定，编译器一般不将包含递归，循环，switch
           等操纵复杂的函数进行内联
        5. 在类中声明中定义的函数。除了虚函数的其他函数都会自动隐式地当成内联函数

    编译器对内联函数的处理：
        1. 将inline的函数体复制到调用内联函数的调用点
        2. 为内联函数中的局部变量分配内存空间
        3. 将内联函数的输入参数和返回值映射到调用方法的局部变量空间中
        4. 如果内联函数中有多个分支返回点，将其转变为内联函数代码块末尾的分支
          （goto语句）

    内联函数的优缺点;
        优点：
            1. 内联函数像宏函数一样在调用处进行代码展开，省去了参数压栈，
               栈帧（栈空间）开辟与回收，结果返回等步骤，提高程序运行速度
            2. 内联函数具有函数特性，在代码展开时会进行参数类型检查或者自动类型转换，
               而宏函数不会
            3. 类内定义的函数会隐式内联，能够访问类内的成员，宏函数不会
            4. 内联函数可以调试，而宏函数不可以
        缺点:
            1. 代码膨胀
            2. 内联函数无法随着函数库升级而升级，内联函数的改变需要进行重新编译，
               非内联函数却可以直接链接
            3. 是否内联不可控，内联函数只是对编译器的建议，是否内联由编译器
    虚函数与内联：
        1. 虚函数可以是内联函数，当虚函数表现为多态时无法内联
           多态时，编译器也无法知道程序调用哪个代码，多态时不能内联
        2. 虚函数内联时：编译器知道调用的是哪一个类的代码，
           可以使用作用域告知编译器 ClassName::func();
           这只有编译器具有实际对象而不是对象的指针或引用时才会发生

*/

class testBase
{
public:
    int a;
    // 类内定义函数，隐式内联
    int get()
    {
        return a;
    }
    // 类内声明，想要内联就只能在类外使用inline显示声明
    inline void set(const int a);
    // inline可以修饰虚函数，说明虚函数可以进行内联，
    // 当且仅当虚函数不发生多态才可以内联
    inline virtual void print_start()
    {
        cout << "这是父类对象" << endl;
    }
};

class testChild : public testBase
{
public:
    int b;
    // 类内定义成员函数，隐式内联
    void fun()
    {
        cout << "你好" << endl;
    }
    // 重写父类的虚函数，发生多态时无法内敛
    inline virtual void print_start()
    {
        cout << "这是子类对象" << endl;
    }
};

inline void testBase::set(const int a)
{
    this->a = a;
}

// 可以内联，功能简单
inline int add(const int a, const int b)
{
    return a + b;
}

// 功能复杂，即使显式的声明为内联函数，但是编译器不会将该函数作为内联函数
inline void print_vec(const vector<int> vec)
{
    for (int i : vec)
        cout << i << " ";
    cout << endl;
}


int main(int args, char *argv[])
{
    cout << endl;
    testBase tb;
    // 编译器明确知道那个对象调用的哪一个函数，可以内联
    tb.print_start();
    // 父类指针指向子类对象，编译器无法知道调用的哪一个函数，无法内联
    testBase *tbc = new testChild();
    tbc->print_start();

    return 0;
}