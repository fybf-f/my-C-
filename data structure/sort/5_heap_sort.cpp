#include "output.h"

void adjust(vector<int> &vec, int father, int end);

void heap_sort(vector<int>& vec)
{
    // 1.数组判空
    int len = vec.size();
    if (len == 0)
    {
        cout << "排序完成 " << endl;
        return;
    }

    // 2.获得最后一棵子树的根节点，那么root_index--就是上一棵子树的根节点，以此类推
    int root_index = len / 2 - 1;
    for (int index = root_index; index >= 0; --index)
    {
        // 3. 将每一棵子树都构造成堆结构,自底向上进行调整，时间复杂度是O(n)
        adjust(vec, index, len - 1);
    }
    // 4.构造堆结构时发现，最终vec[0]是数组中的最值(自底向上会让vec[0]成为最值)
    // 将最值放在数组中的最后面，重新构造堆结构就行
    for (int i = len - 1; i >= 0; --i)
    {
        swap(vec[0], vec[i]);
        adjust(vec, 0, i - 1);
    }
}

void adjust(vector<int>& vec, int father, int end)
{
    // 获取数组最后一个元素下标，以及以father为根节点的左孩子
    int child = 2 * father + 1;
    // 3.在子树中寻找最大的孩子与根节点进行交换
    while(child <= end)
    {
        // 寻找子树中最大的孩子
        if (child + 1 <= end && vec[child] < vec[child + 1])
        {
            ++child;
        }
        // 改变子树中的根节点， 但是这个改变有可能破坏以father为孩子的子树，因此需要回溯至以father为孩子的子树
        if (vec[child] > vec[father])
        {
            // 改变根节点
            swap(vec[child], vec[father]);
            // 回溯子树
            father = child;
            child = 2 * father + 1;
        }
        else 
        {
            // 当子树已经是堆结构时，child不会有任何改变，并且chiid<=end会产生死循环
            break;
        }
    }
    
}



int main()
{
    // system("chcp 65001");
    vector<int> nums(15, 0);
    create_vec(nums);
    print(nums);
    cout << "--- 堆排序 ---" << endl;
    heap_sort(nums);
    print(nums);
    
    return 0;
}



