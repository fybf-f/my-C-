#include <stdio.h>

int main()
{
    /*
        1. volatile是一种类型修饰符，被volatile修饰的变量表示可以被
           某些编译器未知的因素（操作系统， 硬件， 线程）更改
        2. 使用volatile告诉编译器不应该对这样的对象进行优化
           即：每次访问这样的对象都必须重新从内存中取值
           （release模式下由于编译器的优化，可能从cpu寄存器中取值）
        3. volatile可以修饰指针
        4. volatile可以像const一样进行使用
        5. 详见 https://www.runoob.com/w3cnote/c-volatile-keyword.html

    */
    volatile int i = 10;
    int a = i;

    printf("i = %d\n", a);
    // __asm {
	// 	mov dword ptr[ebp - 4], 20h
    // }

    int b = i;
    printf("i = %d", b);
    return 0;
}