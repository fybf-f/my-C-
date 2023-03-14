#include <iostream>

using namespace std;

class Father
{
    public:
    virtual void fun() {}
};

class Son : public virtual Father
{
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    cout << sizeof(Son);
    return 0;
}
