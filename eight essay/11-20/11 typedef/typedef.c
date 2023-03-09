#include <stdio.h>

/*
    1. C语言中实例化结构体需要使用关键字struct
    2. typedef修饰结构体，并为这个结构体起别名
       能够使用这个别名来实例化结构体
       这个别名在全局标识符命名空间
*/

// Student的命名空间在结构体命名空间
typedef struct Student
{
    int age;
} S;

// struct Student s;
void Student()
{
    // 不会报错，因为有typedef修饰
    printf("this is a student\n");
}

int main(int args, char* argv[]) 
{
    
    printf("\n");
    // 不会报错，因为有typedef修饰
    S s;
    s.age = 10;
    printf("%d\n", s.age);
    return 0;
}