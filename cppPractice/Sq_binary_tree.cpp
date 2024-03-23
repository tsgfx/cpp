// 二叉树的顺序存储
#include <iostream>
#define BiNodeSize 10
using namespace std;
typedef char ElemType;
typedef struct
{
    ElemType data;
    bool isEmpty;
} BiNode, *BiTree;

bool InitBiTree(BiTree &T)
{
    T = new BiNode[BiNodeSize];
    for (int i = 0; i < BiNodeSize; i++)
    {
        T[i].isEmpty = true; //T[i]等价于*(T+i)所以用.访问结构体中的元素。
    }
    return true;
}

bool AddRoot(BiTree &T, ElemType elem)
{
    if (T[1].isEmpty == false) return false;
    T[1].data = elem;
    T[1].isEmpty = false;
    return true;
}

bool AddLeftChild(BiTree &T, ElemType elem, int index)
{
    if (T[index].isEmpty == true) return false;
    if (T[2 * index].isEmpty == false) return false;
    T[2 * index].data = elem;
    T[2 * index].isEmpty = false;
    return true;
}

bool AddRightChild(BiTree &T, ElemType elem, int index)
{
    if (T[index].isEmpty == true) return false;
    if (T[2 * index + 1].isEmpty == false) return false;
    T[2 * index + 1].data = elem;
    T[2 * index + 1].isEmpty = false;
    return true;
}

void SqPrint(BiTree T)
{
    for (int i = 1; i < BiNodeSize; i++)
    {
        if (T[i].isEmpty == false)
        {
            cout << T[i].data << " ";
        }
    }
    cout << endl;
}
int main()
{
    BiTree T;
    InitBiTree(T);
    AddRoot(T, 'a');
    AddLeftChild(T, 'b', 1);
    AddRightChild(T, 'c', 1);
    AddLeftChild(T, 'd', 2);
    AddRightChild(T, 'e', 2);
    SqPrint(T);
    return 0;
}