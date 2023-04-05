#include <iostream>
#include <vector>

using namespace std;

void sorting(vector<int> &vec, int left, int mid, int right)
{
    vector<int> temp(right - left + 1);
    int one = left, two = mid + 1;
    int temp_index = 0;
    while (one <= mid && two <= right)
    {
        if (vec[one] <= vec[two])
            temp[temp_index++] = vec[one++];
        else
            temp[temp_index++] = vec[two++];
    }
    while (one <= mid)
        temp[temp_index++] = vec[one++];
    while (two <= right)
        temp[temp_index++] = vec[two++];
    temp_index = 0;
    for (int i = left; i <= right; ++i)
    {
        vec[i] = temp[temp_index++];
    }
}

void merge_sort(vector<int> &vec, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (right - left) / 2 + left;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    sorting(vec, left, mid, right);
}

void merge_sort(vector<int> &vec)
{
    if (vec.empty())
    {
        cout << "排序完成" << endl;
        return;
    }
    merge_sort(vec, 0, vec.size() - 1);
}

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    vector<int> nums = {1, 3, 33, 5, 21, 76, 77, 8, 8, 9, 45, 3, 65, 46, 3};
    // quick_sort(nums);
    merge_sort(nums);
    for (auto i = nums.begin(); i != nums.end(); ++i)
    {
        cout << *i << endl;
    }
    return 0;
}