#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Test
{
public:
    int id;
    const static void fun() {}
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    Test t;
    return 0;
}