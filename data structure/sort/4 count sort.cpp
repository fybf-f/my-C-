#include "output.h"

// 练习使用迭代器，并对代码进行规范
void count_sort(vector<int>& vec)
{
    // 1. 寻找最大值
    int max = INT_MIN;
    for (int i : vec)
    {
        max = max > i ? max : i;
    }
    // 2. 创建一个max + 1的数组
    
    vector<int> *temp = new vector<int>(max + 1);
    // 3. 构建桶数组
    for (int i : vec)
    {
        ++(*temp)[i];
    }
    /*  // 打印桶数组
        for (auto item = temp->begin(); item != temp->end(); ++item)
        {
            cout << *item << " ";
        }
    */
    // 4.遍历桶数组，对原数组进行排序
    int index = 0;
    auto start = temp->begin();
    for (auto itor = temp->begin(); itor != temp->end(); ++itor)
    {
        while (*itor != 0)
        {
            vec[index++] = distance(start, itor);
            --(*itor);
        }
    }


}

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    vector<int> nums(15);
    create_vec(nums);
    print(nums);
    count_sort(nums);
    cout << " ------- " << endl;
    print(nums);
    return 0;
}