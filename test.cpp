#include <vector>
#include <iostream>
using namespace std;

vector<int> fun1(int num)
{
    vector<int> values;
    for (int j = 0; j < num; j++)
    {
        values.push_back(j);
    }
    return values;
}

int main()
{
    vector<int> myvector;
    int i;
    myvector = fun1(10);
    cout << endl;
    for (int m = 0; m < myvector.size(); m++)
    {
        cout << myvector[m] << endl;
    }
    return 0;
}