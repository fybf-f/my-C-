#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Test
{

    int b : 1;
    char a;

}Test;

int main(int args, char *argv[])
{

    printf("%d\n", sizeof(Test));
    return 0;
}