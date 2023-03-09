#include <iostream>
#define BUFSIZE 100  // 宏定义常量

/*
    宏与const的区别：
    宏：相当于字符替换      const：常量声明
    宏：预处理器处理        const：编译器处理
    宏：无类型安全检查      const：有类型安全检查
    宏：不分配内存          const：需要分配内存
    宏：内存中在.text段     const：内存中在.data段
    宏：可以通过undef取消   const：不可取消
*/

using namespace std;
/*
    修饰变量：说明该变量不可以改变（C语言中，被const修饰的变量仍可以通过指针修改，C++不能）
    修饰指针：分为指向常量的指针和自身就是常量的指针
    修饰引用：指向常量的引用，多用于形参类型，即避免了拷贝，也能防止函数对值的修改
    修饰类的成员函数：说明该成员函数不能修改成员变量
    const修饰参数；被const修饰的参数在函数中不能被改变
    const int 类型的参数不能在函数内部初始化指针和引用
    const修饰返回值：const int* 与 int* const

*/
class test
{
public:
    const int a = 1; // 常对象成员变量
    int b;
    test()
    {
        this->b = 1;
        b += a;
    }

    int temp();       // 声明一个普通成员函数
    int temp() const; // const稀释函数成为常成员函数，可以用来函数重载
};

int test::temp()
{
    // cout << endl;
    cout << "这是普通成员函数temp" << endl;
    return b;
}

int test::temp() const
{
    cout << "这是常函数temp" << endl;
    return a;
}

int add(const int a, const int b)
{
    // 报错，被const修饰的参数不能被改变
    // a = 2;
    // const int 类型的参数不能在函数内部初始化指针和引用
    // int *pa = &a;
    // int &tempa = a;
    int c = a + b;
    return c;
}

int main()
{
    cout << endl;
    const int int_temp = 10;
    // 报错，从指针变量定义直接阻止这种违法行为
    // int *ptr_temp = &int_temp;
    // 定义的指针变量也需要使用同含义的const修饰
    const int *ptr_a = &int_temp;
    cout << "常量BUFSIZE的大小为：";  // 宏的大小可以使用sizeof()来获得
    cout << sizeof(BUFSIZE) << endl;
    // const int a;  报错，常量在声明时必须进行初始化
    // 普通对象，能够调用所有成员函数
    test t;
    // 常对象，只能调用以及访问常成员
    const test ct;
    cout << t.b << endl;
    t.temp();
    ct.temp();
    char greeting[] = "hello";
    char *common_p = greeting;        // 指针变量指向字符数组变量
    const char *common_p1 = greeting; // const修饰* 指针变量，指针变量指向指向字符数组常量
    // （const后面是char, 说明指向的字符是常量不能改变）
    char *const const_p = greeting; // const修饰指针，该指针是常量，指向的是字符数组变量
    
    return 0;
}
