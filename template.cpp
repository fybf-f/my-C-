#include <iostream>

using namespace std;

template <class T>
class A
{
public:
    void func(T t)
    {
        cout << t << endl;
    }
};


int main(int args, char* argv[]) 
{
    cout <<" --------------" <<endl;
    A<int> a;
    a.func(10);
    A<string> b;
    b.func("aaa");
    return 0;
}