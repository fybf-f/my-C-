#include <stdio.h>

typedef struct TestFather
{
    // public:
    // 注意C语言中的struct是没有访问权限修饰符的
    
};
// C语言的结构体是没有继承的概念的
typedef struct TestChild /*: TestFather*/
{
    // C语言的结构中是不能存在函数的
    // int add(const int a, const int b);
};


int main(int args, char* argv[]) 
{
    printf("\n");
    
    return 0;
}