#include <stdio.h>

int fun()
{
    static int a;
    ++a;
    return a;
}


int main(int args, char* argv[]) 
{
    printf("-----------------\n");
    printf("%d\n", fun());
    printf("%d\n", fun());
    printf("%d\n", fun());
    return 0;
}