#include <iostream>

using namespace std;

/*
    使用初始化参数列表的好处：
        更高效：少了一次调用默认构造函数的过程
            由于对象成员变量的初始化动作发生在进入构造函数之前，对于内置类型没什么影响，
            但如果有些成员是类，那么在进入构造函数之前，会先调用一次默认构造函数，
            进入构造函数后所做的事其实是一次赋值操作(对象已存在)，
            所以如果是在构造函数体内进行赋值的话，等于是一次默认构造加一次赋值，
            而初始化列表只做一次赋值操作。
        有些场合必须要用初始化列表：
            常量成员，因为常量只能初始化不能赋值
            引用类型，引用必须在定义的时候初始化，并且不能重新赋值
            没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化

*/

int main(int args, char* argv[]) 
{
    cout <<" --------------" <<endl;
    
    return 0;
}