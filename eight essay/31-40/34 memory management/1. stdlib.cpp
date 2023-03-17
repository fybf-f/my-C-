#include <iostream>
#include <stdlib.h>

using namespace std;

/*
    malloc：申请指定字节数的内存。申请到的内存中的初始值不确定。

    calloc：为指定长度的对象，分配能容纳其指定个数的内存。申请到的内存的每一位（bit）都初始化为 0。

    realloc：更改以前分配的内存长度（增加或减少）。
    当增加长度时，可能需将以前分配区的内容移到另一个足够大的区域，而新增区域内的初始值则不确定。

​    alloca：在栈上申请内存。程序在出栈的时候，会自动释放内存。但是需要注意的是alloca 不具可移植性, 
而且在没有传统堆栈的机器上很难实现。alloca 不宜使用在必须广泛移植的程序中。C99 中支持变长数组 (VLA)，
可以用来替代 alloca。
*/

/*
    使用申请空间的四个函数会返回void*，通过返回的指针进行释放
    释放后一定要将指针赋值为空
*/


int main(int args, char* argv[]) 
{
    cout <<" --------------" <<endl;
    char *ptr = (char*)malloc(1000);
     

    return 0;
}