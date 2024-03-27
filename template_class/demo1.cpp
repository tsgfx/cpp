#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class Vector
{
private:
    T *items;
    int length;
public:
    //默认构造函数
    Vector(int size = 10):length(size)
    {
        items = new T[length];
    }
    //析构函数
    ~Vector() 
    {
        delete[] items;
        items = nullptr;
    }

    //扩展大小
    void resize(int size)
    {
        if(size <= length) return;
        T *newitems = new T[size];
        for(int i = 0; i < length; i++)
        {
            newitems[i] = items[i];
        }
        delete[] items;
        items = newitems;
        length = size;
    }

    int getSize() const //只读
    {
        return length;
    }

    //重载下标运算符[],可以修改数组中的元素
    T &operator[](int i)
    {
        if(i >= length) resize(i + 1);
        return items[i];
    }
    //重载下标运算符[],不可修改数组中的元素，以适应const对象
    const T &operator[](int i) const
    {
        return items[i];
    }
};

int main()
{
    Vector<int> arr(1);
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    for(int i = 0; i < 3; i++) cout << arr[i] << endl;
    return 0;
}