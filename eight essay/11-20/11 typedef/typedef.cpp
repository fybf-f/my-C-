#include <iostream>

using namespace std;

struct Student
{
    int id;
};

// 报错，Student的命名均在全局标识符表中
// void Student(int a)
// {

// }


int main(int args, char* argv[]) 
{
    cout << endl;
    // 不会报错，C++的编译器会在全局标识符表中搜索Student
    Student s;
    s.id = 10;
    cout << s.id << endl;
    return 0;
}