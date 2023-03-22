#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

union U
{
    int a ;
    char c = 1;
};
int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    U u;
    cout << u.a << endl;
    return 0;
}
