#include <iostream>
#include <assert.h>

using namespace std;

/*
    1. assert断言，是宏函数
    2. 满足assert的条件返回错误，会终止程序运行
    3. 只在debug模式可用
    4. 如果assert括号里面的内容会报错，
       assert会终止程序运行，并返回错误
*/

int main(int args, char* argv[]) 
{
    cout << endl;
    int *p = nullptr;
    
    assert(p);

    return 0;
}