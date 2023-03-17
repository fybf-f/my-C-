#include <iostream>
#include <vector>
using namespace std;

/*
    mingw编译环境下，vector每次扩容是原vecotr容量的二倍
    msvc编译环境下，vector每次扩容是原来vector容量的1.5倍
*/

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    // 申请10容量的vector
    vector<int> vec(10);
    // vec.push_back(100);
    for(int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    // vec.clear();
    // cout << "vec.clear()" << endl;
    // 输出vector容器中的元素
    // for (int i : vec)
    // {
    //     cout << i << " ";
    // }
    cout << endl;
    // 使用resize对容器重新赋值空间大小
    vec.resize(25);
    cout << "vec.resize()" << endl;
    for (int i : vec)
    {
        cout << i << " ";
    }

    cout << "-----" <<endl;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}