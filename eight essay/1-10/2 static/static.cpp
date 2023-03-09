#include <iostream>

using namespace std;

// 全局变量不进行初始化也默认为0，为避免错误请在声明全局变量时进行初始化
int buf_size = 1;
// 全局变量其他文件仍然可以进行访问,但实际静态全局变量只能本文件进行访问
static int cur_file_count;

class test
{
public:
    // 普通成员变量
    int age;
    // 静态成员变量，只能在类内声明，类外进行初始化
    static char sex;
    // 声明普通成员函数
    void print();
    // 静态成员函数只能在类中声明，类外进行初始化, 并使用对象调用
    static int output();
};

// 静态成员变量只能在类外进行初始化,类外初始化静态成员变量通常不加static
char test::sex = 'M';

void test::print()
{
    cout << this->age << endl;
    cout << this->sex << endl;
}

// 类外初始化静态成员函数通常不加static
int test::output()
{
    // 报错，因为静态成员函数属于类，而不是某个对象，所以使用this会报错
    // cout << this->sex << endl;

    // 静态成员函数只能访问静态成员变量，不能访问普通成员变量
    // cout << age << endl;
    cout << sex << endl;
    return 0;
}

// 静态函数（该函数在该文件内是可见的，但是文件外不可见）
static int add(const int a, const int b)
{
    return a + b;
}


int main()
{
    cout << endl;
    // static修饰静态变量，该变量将在静态区（共享区）分配内存
    static int static_count = 1;
    // 静态局部变量未经初始化将默认为0，但是避免在其他平台错误等等
    // 声明静态局部变量时请进行初始化
    test *t = new test();
    t->output();

    return 0;
}