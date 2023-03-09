#include <iostream>

using namespace std;

class Test
{
public:
    int number;

    void func(const int a, int b)
    {
        /*
            使用lambda表达式
            常见错误写法：
                auto ret1 = [](){return number; };
                auto res2 = [number](){return number; };
        */
        // 正确写法：
        auto ret3 = [this]()
        { return this->number; };
        // 值捕获所有此lambda上面的所有变量
        auto ret4 = [=]() -> int
        { return number + a + b; };
        // cout << typeid(ret4).name() << endl;
        // 引用捕获此表达式上面的所有变量
        auto ret5 = [&]()
        { return (number++) + a + (++b) + ret4(); };
    }
};

int main(int args, char *argv[])
{
    cout << " --------------" << endl;
    Test t;
    t.func(10, 20);
    auto f = [](int i)
    {
        return i;
    };
    char temp;
    cout << "类型为：" <<typeid(temp).name() << endl;
    return 0;
}