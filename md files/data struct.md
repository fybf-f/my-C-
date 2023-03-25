# 算法与数据结构

## 1.vector

### vector的底层实现

- 一段连续的内存空间
- 三个指针：
  - begin:  连续内存的首地址
  - finish: 指向最后一个元素的下一个位置
  - end: 连续内存后的下一个位置
    - en的位置可以使用 != 来判断，使用 < 计算量增大

### vector扩容机制

- 扩容时机： vec.size() == vec.capacity() 时发生扩容
- 扩容动作： 开辟一块**大小合适**的新空间，拷贝原vector元素，释放原来的空间
- 扩容效率问题：
  - 当我们不进行预分配空间时，可能导致边插入边扩容，扩容的动作效率很低
  - 使用reserve()函数进行预开辟空间



- 扩容容量计算：每次扩容之后的容量是大于上一次容量的，如果以2倍的原理进行扩容那么每次新申请的空间都肯定大于前面申请空间的总和（1, 2, 4, 8···）,申请的倍数最好是介于1~2之间的
  - msvc编译环境下为1.5倍扩容，可能在几次扩容后就能够重新使用前面使用的空间
  - mingw编译环境下为2倍扩容，虽然能够在一定程度上减少扩容动作，但是能够造成一定的空间的浪费（内碎片），因此linux下使用**伙伴系统**

- [伙伴系统](https://zhuanlan.zhihu.com/p/468829050)：为内核提供了一种用于分配一下连续的页而建立的一种高效的分配策略,对固定分区和动态分区方式的折中

  - 当申请的空间超过128kB时，先使用brk来扩张，而内存中arena（位图，固定大小的内存池）没有最够空间分配时，使用mmap向上扩张堆空间

  - **整个内存区域构建成基本大小basicSize的1倍、2倍、4倍、8倍、16倍等，即要求内存空间分区链均对应2的整次幂倍大小的空间，**整齐划一，有规律的而不是混乱的

  - 在分配和释放空间时，可以通过log2(request/basicSize)向上取整的哈希算法快速找到对应内存块。

  - **伙伴系统中的每条空闲分区链中挂的都是2i的页面大小，通过哈希思想进行空间分配与合并，非常高效。**估计可能是这个原因SGI-STL选择以2倍方式进行扩容

    

 ### vector的size()与capacity()

- size(): 返回当前vector中容纳的元素数量

- capacity(): 返回当前(未产生扩容动作)vector能够容纳的元素数量

  

### vector的clear()与resize()对vector的size()与capacity的影响

- clear()：clear()函数会清空当前vector容器内的所有元素，使用clear()后size()为0，但是capacity()不会受到任何影响

- resize()： 函数原理使用迭代器实现的！！！，假设当前vector的容量大小为10，

  ​				并将容器中的数据全都初始化为1(vec.size() = vec.capacity() = 10)

  - 当vec.resize(n)
    - n < vec.size()时，会保留前n个元素，后面n个元素被舍弃，使vec.size() = n, vec.capacity()不变
    - n = vec.size()时，什么都没有发生
    - vec.size() < n < vec.capacity()时：使vec.size() = n，并将元素默认(可以指定)初始化0，vec.capacity()不变
    - n > vec.capacity()时：发生扩容动作！！！，脑壳痛，不同编译环境下，resize结果不同
    - 不同编译环境下，resize结果不同，当n < 扩容因子时，自动扩容至原容量*扩容因子
    - n > 扩容因子时，capacity() = n, size() = n



### vector的扩容因子选择

**为了防止申请内存的浪费，现在使用较多的有2倍与1.5倍的增长方式，而1.5倍的增长方式可以更好的实现对内存的重复利用。**

![扩容因子选择](https://img-blog.csdnimg.cn/b092797cb7a54d8ea79d7b802da3a97d.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5qOu5piO5biu5aSn5LqO6buR6JmO5biu,size_20,color_FFFFFF,t_70,g_se,x_16)

### vector与list的区别

相同点：都是命名空间std下的两个容器

不同点：

|                 list                 |                vector                |
| :----------------------------------: | :----------------------------------: |
|   容器中元素在内存空间中**不连续**   |    容器中元素在内存空间中**连续**    |
|  不支持随机存取，平均时间复杂度O(n)  |   支持随机存取，平均时间复杂度O(1)   |
| 插入元素与删除元素平均时间复杂度O(1) | 插入元素与删除元素平均时间复杂度O(n) |



### vector随机访问时间复杂度以及优化查找

- vector的随机访问时间复杂度是O(1)
- 优化查找：
  - 使用二分查找法：如果vector已经排序，可以使用二分查找法来查找元素。这样可以将查找的时间复杂度从线性降低为对数级别的O（log n）。
  - 使用哈希表：可以将vector中的元素建立哈希表，这样就可以在常数时间内查找元素。但是建立哈希表需要额外的空间，并且在某些情况下可能会出现哈希冲突的问题。
  - 使用有序vector：如果对vector的操作以查找为主，可以将vector中的元素排序，这样可以在查找时使用二分查找法。虽然排序需要一定的时间，但是在查找次数比较多的情况下，这样做可以降低总体的时间复杂度。
  - 使用unordered_map：如果需要频繁的查找vector中的元素，可以将vector转化为unordered_map，这样可以在常数时间内查找元素。但是转化为unordered_map需要额外的空间，并且在某些情况下可能会出现哈希冲突的问题。



### 代码示例

```c++
#include <iostream>
#include <vector>
using namespace std;

/*
    mingw编译环境下，vector每次扩容是原vecotr容量的二倍
    msvc编译环境下，vector每次扩容是原来vector容量的1.5倍
*/

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    // 申请10容量的vector
    vector<int> vec(10);
    // vec.push_back(100);
    for(int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    // vec.clear();
    // cout << "vec.clear()" << endl;
    // 输出vector容器中的元素
    // for (int i : vec)
    // {
    //     cout << i << " ";
    // }
    cout << endl;
    // 使用resize对容器重新赋值空间大小
    vec.resize(25);
    cout << "vec.resize()" << endl;
    for (int i : vec)
    {
        cout << i << " ";
    }

    cout << "-----" <<endl;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}
```



## 2.内省排序

- sort函数实现原理
- 内省排序会在运行中检查元素个数进行选择最优的排序方案

- 当待排序元素数量小于等于16时，使用插入排序(此时比快速排序快)
  - 插入排序是对于小型数据最佳的比较排序算法；
  - 它是稳定排序算法；
  - 如果数组部分有序，其性能依然优于其他算法。

- 当数据量大于16时使用快速排序
  - 为什么不使用归并： 归并排序总是需要频繁创建、销毁辅助数组
  - 为什么不直接使用堆排序：
    - heap 排序虽然和快排在平均情况下的时间复杂度是 O(nlgn)，但是 heap 排序的时间常数要比快排的时间常数要大。
    - 快排的最坏情况在是很少发生
    - 快排能够比较好的吻合程序的空间局部性原理，因为它操作的基本都是相邻的元素（虚拟存储器的设计理论基础中就有程序的时间局部性和空间局部性），能够减少内存缺页中断的发生次数

- 当超出递归深度就转换快排为堆排序
  
  - 快速排序最坏情况的概率大大的提升了
  
  

## 3. 实现一个string类



## 4. 排序算法

### 1 冒泡排序

- 重复地走访过要排序的数组，依次比较两个相邻的元素，是他们基本有序。走访元素的工作是重复地进行，直到没有相邻元素需要交换，表示排序完成
- 最好的情况是元素已经排好顺序，所以使用一个bool变量记录是否交换过，如果没有，直接停止排序
- 每次排序都会把相对大的值放在右侧，因此内部循环就可以是数组长度 - i(i代表已经排序完的元素个数)
- 代码

```cpp
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void bubble_sort(vector<int> &vec)
{
    if (vec.empty())
    {
        return;
    }
    int len = vec.size();
    for (int i = 0; i < len; ++i)
    {
        bool flag = true;
        for (int j = 1; j < len - i; ++j)
        {
            if (vec[j] < vec[j - 1])
            {
                swap(vec[j], vec[j - 1]);
                flag = false;
            }
        }
        if (flag)
        {
            cout << "元素排序完毕" << endl;
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    cout << "--------" << endl;
    vector<int> nums = {6, 1, 4, 3, 2, 10, 7, 5, 11, 9};
    bubble_sort(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    char *ptr = "abcd";
}

```

### 2 选择排序

- 顾名思义：每次选择出来一个最大值放在右面。
- 代码：

```cpp
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
```

### 3 插入排序

- 插入排序：维护两个区域，一边是有序的区域，一边是无序的区域，每次从无需区中取一个元素，插入到有序区。每次插入确保有序区依旧有序，无序区逐渐减少

- 代码：

  ```cpp
  #include <iostream>
  #include <vector>
  using namespace std;
  
  
  void print(vector<int> vec)
  {
      for (int i : vec)
      {
          cout << i << " ";
      }
      cout << endl;
  }
  
  void insert_sort(vector<int>& vec)
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
                  break;  // 找到位置时，left不能继续--
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
  ```




### 4 计数排序

1. 遍历待排序的数组，寻找待排序数组中的最大值
2. 创建一个最大值+1的辅助数组
3. 使用待排序的数组初始化辅助数组
   - 辅助数组的下标是待排序数组中的元素
   - 辅助数组的下标对应的值是待排序数组中这个元素的数量
4. 遍历辅助数组，对原数组进行排序
5. 代码：

```cpp
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
```

### 5 堆排序

1. 将待排序的序列抽象成为一个完全二叉树

2. 使每棵子树都构建成最大或者最小堆

   - 最大堆： 每个子树中的根节点都是最大值
   - 最小堆： 每个子树中的根节点都是最小值

3. 完全二叉树的下标特点： 根节点的下标为i， 那么左子树的下标就是2 * 1 + 1,右子树的下标就是2 * i + 2

4. 代码：

   