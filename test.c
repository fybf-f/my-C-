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
    char chr = 127;
    int sum = 200;
    chr += 1;
    sum += chr;
    printf("%d\n", sum);
    return 0;
}