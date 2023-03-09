#include <stdio.h>

/*
    1. C语言是一个面向过程的语言，并没有类的概念
       并且基本没有面向对象的用法
    2. 使用C语言实现类就需要明白C语言中的结构体与C++类的差别
    3. 面向对象：封装、继承、多态
    4. C语言中的结构体中不能定义函数，实现封装可以通过函数指针
    5. C语言中的结构体不能进行继承，
       要继承，那么两个结构体相同的成员都要定义成一样，
       新增的成员变量放在后面。
       定义的顺序很重要，先定义的作为基类
    6. 通过函数指针可以实现伪多态
*/

typedef struct C_Class
{
    int age;
    // 定义一个函数指针
    void (*to_class)(const int *age);
}Cpp;

// 伪继承
typedef struct SubClass
{
    int age;
    void (*to_class)(const int *age);
    char *buf;
}Sub;

int main(int args, char* argv[]) 
{
    printf("\n");
    Cpp c;
    c.age = 20;
    Sub sub;
    return 0;
}