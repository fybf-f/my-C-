#include <iostream>
#include <vector>
using namespace std;
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

void select_sort(vector<int> &vec)
{
    int len = vec.size();
    if (len == 0)
    {
        cout << "排序完毕" << endl;
        return;
    }
    for (int i = 0; i < len; ++i)
    {
        // 使用curr_max记录当前最大元素的下标, 使用j记录尚未排序的最后一个位置
        int j, curr_max = 0;
        for (j = 1; j < len - i; ++j)
        {
            if (vec[j] > vec[curr_max])
                curr_max = j;
        }
        // 因为执行++j,所以j比预期大1，需要减掉
        swap(vec[j - 1], vec[curr_max]);
    }
}

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    vector<int> nums = {6, 1, 4, 3, 2, 10, 7, 5, 11, 9};
    select_sort(nums);
    print(nums);
    return 0;
}