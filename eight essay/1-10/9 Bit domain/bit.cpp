#include <iostream>

using namespace std;

/*
    1. 使用位域能够节省内存空间，使数据结构更加紧凑
    2. 位域受不同的系统与硬件影响，
       因此程序中使用位域会降低程序的可移植性
*/

class test
{
public:
    // 该int类型的属性只有1位，比原int节省31位
    int sex : 1;  
};

int main(int args, char *argv[])
{
    cout << endl;

    return 0;
}