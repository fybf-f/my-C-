#include "output.h"
/*
    归并排序
*/

// mid参数是用来分隔，mid两边的数组是有序的，需要合并两段有序数组
void sorting(vector<int> &vec, int left, int mid, int right)
{
    // 合并有序数组，先申请一个大小合适的临时数组
    vector<int> temp(right - left + 1);
    // 使用两个下标记录这两段数组的元素，使用index记录临时数组的位置
    int index = 0, one = left, two = mid + 1;
    while (one <= mid && two <= right)
    {
        if (vec[one] <= vec[two])
            temp[index++] = vec[one++];
        else
            temp[index++] = vec[two++];
    }
    while (one <= mid)
        temp[index++] = vec[one++];
    while (two <= right)
        temp[index++] = vec[two++];
    index = left;
    for (int i = 0; i < temp.size(); ++i)
    {
        vec[index++] = temp[i];
    }
}

void merge_sort(vector<int> &vec, int left, int right)
{
    // 递归前进状态进行分割, 回退状态进行排序

    // 递归前进
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
        cout << " 排序完成 " << endl;
        return;
    }
    merge_sort(vec, 0, vec.size() - 1);
}

int main()
{
    cout << "-----------" << endl;
    vector<int> nums(20);
    create_vec(nums);
    merge_sort(nums);
    print(nums);
    return 0;
}