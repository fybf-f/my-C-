#include <stdio.h>

void func(int* ptr)
{
    printf("这个是int*作为参数的函数\n");
}

void func(int p)
{
    printf("这个是int作为参数的函数\n");
}

int main(int args, char* argv[]) 
{
    printf("-----------------\n");
    int i;
    int *p = &i;
    // func(NULL);
    return 0;
}