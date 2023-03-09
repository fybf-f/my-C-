#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    1. sizeof()是运算符，能够获得变量在内存中的字节数
    2. sizeof()返回的值与编译器和环境有着很大关系
    3. 对于stl容器，使用sizeof()无法获得其在内存中真正的字节数
    4. 对于一个空的类实例化的对象，其大小为1（用于占位）
    5. 对于一个非空类实例化的(非指针)对象，
       其大小规则同结构体对其规则
    6. sizeof对数组得到整个数组所占空间大小
    7. sizeof对指针得到指针本身所占的空间
*/

class test
{
public:
    int a = 10;
    double b = 2.101;
};

int main(int args, char *argv[])
{
    cout << endl;
    // mingw编译器输出32，X86下vs编译输出28，X64下编译输出40
    string str_test = "abc";
    int a = 10;
    vector<int> vec(100, 0);
    test t;
    // cout << sizeof(str_test) << sizeof(a) << endl;
    cout << "sizeof(vec) = " << sizeof(vec) << endl;
    cout << sizeof(t);
    return 0;
}