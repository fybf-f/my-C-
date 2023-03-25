#include <iostream>
#include <vector>
#include <random>
#include <ctime>
// #include <algorithm>
// #include <iterator>
using std::cout;
using std::default_random_engine;
using std::distance;
using std::endl;
using std::uniform_int_distribution;
using std::vector;

void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void print(vector<int> vec)
{
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}

default_random_engine e;
uniform_int_distribution<int> u(0, 20);

void create_vec(vector<int>& nums)
{
    e.seed(time(0));
    for (int &i : nums)
    {
        i = u(e);
    }
    
}

