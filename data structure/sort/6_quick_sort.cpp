#include "output.h"
/*
    快排
*/
using std::make_pair;
using std::pair;
// 此数组只有三种元素，要么小于基准值，要么等于基准值，要么大于基准值
pair<int, int> sorting(vector<int> &vec, int left, int right)
{
    // 定义基准值与左右边界
    int reference_value = vec[left], leftedge = left - 1, rightedge = right + 1;
    // 使用index遍历这三种元素
    int index = left;
    while (index < rightedge)
    {
        if (vec[index] == reference_value)
            index++;
        else if (vec[index] < reference_value)
            swap(vec[++leftedge], vec[index++]);
        else
            swap(vec[--rightedge], vec[index]);
    }
    // 返回两个值，这两个区间是所有与基准值相同的值
    return make_pair(leftedge, rightedge);
}
void quick_sort(vector<int> &vec, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    pair<int, int>p = sorting(vec, left, right);
    quick_sort(vec, left, p.first);
    quick_sort(vec, p.second, right);
}

void quick_sort(vector<int> &vec)
{
    if (vec.empty())
    {
        cout << "排序完成" << endl;
        return;
    }
    quick_sort(vec, 0, vec.size() - 1);
}

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    // vector<int> nums(15);
    // create_vec(nums);
    vector<int> nums = {1, 3, 33, 5, 21, 76, 77, 8, 8, 9, 45, 3, 65, 46, 3};
    quick_sort(nums);
    cout << "排序完成" << endl;
    print(nums);
    return 0;
}