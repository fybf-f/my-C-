#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void swap(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}

void bubble_sort(vector<int> &vec)
{
    if(vec.empty())
    {
        return ;
    }
    int len = vec.size();
    for (int i = 0; i < len; ++i)
    {
        bool flag = true;
        for (int j = 1; j < len - i; ++j)
        {        
            if(vec[j] < vec[j - 1])
            {
                swap(vec[j], vec[j - 1]);
                flag = false;
            }            
        }
        if (flag)
        {
            return ;
        }
    }
}


int main(int argc, char *argv[])
{
    cout << "--------" << endl;
    vector<int> nums = {6, 1, 4, 3, 2, 10, 7, 5, 11, 9};
    bubble_sort(nums);
    for(int i : nums)
    {
        cout << i << " ";
    }
}
