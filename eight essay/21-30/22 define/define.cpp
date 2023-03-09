#include <iostream>

using namespace std;

// 使用宏函数完成一个计算数字的平方

#define SQUARE(x) x*x

/*
    宏：
        宏定义可以实现类似于函数的功能，但是它终归不是函数，
        而宏定义中括弧中的“参数”也不是真的参数，
        在宏展开的时候对 “参数” 进行的是一对一的替换。
*/

int main(int args, char* argv[]) 
{
    cout <<" --------------" <<endl;
    int a = SQUARE(2);
    double d = SQUARE(1.5);
    cout << a << " " << d;
    return 0;
}