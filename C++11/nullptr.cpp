#include <iostream>

using namespace std;

/*
    C语言中NULL既是空指针，又是0
    C++中NULL就是0
    C++中nullptr是void*
    注意C++函数重载时
    int类型的参数和int*类型的参数重载时，
    传入NULL默认调用int类型参数函数
*/




int main(int args, char* argv[]) 
{
    cout <<" --------------" <<endl;
    // C++是强类型语言，不支持将void*隐式转换成为char*,C语言可以
    // char *ptr = (void *)0;
    return 0;
}