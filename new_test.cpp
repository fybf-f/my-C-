#include <iostream>
#include <vector>
using namespace std;

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    vector<int> vec = {0, 1, 2, 3, 4, 5};
    vector<int> new_vec = vec;
    vec[0] = 10;
    cout << new_vec[0];
    return 0;
}