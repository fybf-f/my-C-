#include <iostream>

using namespace std;

/*
    被extern限定的函数或者变量是按照C语言的方式进行编译与链接
*/
// 使用extern

#ifdef __cplusplus
extern "C"
{
#endif
    // 函数test与变量c_element按照C语言的方式进行编译或链接
    void test(const int a, const int b);
    int c_element = 10;

#ifdef __cplusplus
}
#endif

int main(int args, char *argv[])
{
    cout << endl;

    return 0;
}