#include "output.h"

void insert_sort(vector<int> &vec)
{
    int len = vec.size();
    if (len == 0)
    {
        cout << "排序完毕" << endl;
        return;
    }
    // 使用两个变量right, left,  left用于扫描维护有序区基本有序并且让寻找插入位置
    for (int right = 1; right < len; ++right)
    {
        int temp = vec[right], left;
        for (left = right - 1; left > -1; --left)
        {
            // 当需要插入时，可能需要移动有序区元素
            if (vec[left] > temp)
            {
                vec[left + 1] = vec[left];
            }
            else
                break; // 找到位置时，left不能继续--
        }
        vec[left + 1] = temp;
    }
}

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    vector<int> nums = {6, 1, 4, 3, 2, 10, 7, 5, 11, 9};
    insert_sort(nums);
    print(nums);
    return 0;
}