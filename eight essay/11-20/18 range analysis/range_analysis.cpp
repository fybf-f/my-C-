#include <iostream>

using namespace std;

/*
    范围解析运算符：
        ::name, 全局作用域解析
        class::name, 类作用解析
        namespace::name, 命名空间解析
*/

class name
{
    public:
        
};

int a = 10;

int main(int args, char* argv[]) 
{
    cout <<" --------------" <<endl;
    int a = 5;
    // 在全局命名空间下寻找变量a
    cout << ::a << endl;
    return 0;
}