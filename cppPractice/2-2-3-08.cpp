#include <iostream>
#define MaxSize 10
typedef int ElemType;
using namespace std;
typedef struct
{
    ElemType *data;
    int length;
}SqList;

void initList(SqList& L)
{
    L.length = 0;
    L.data = (ElemType*)malloc(sizeof(ElemType) * MaxSize);
}

void swap(ElemType& a, ElemType& b)
{
    ElemType temp;
    temp = a;
    a = b;
    b = temp;
}

bool find_x(SqList &L, ElemType x)
{
    bool isfound = false;
    for(int i = 0; i < L.length; i++)
    {
        if(L.data[i] == x && i != L.length-1)  
        {
            swap(L.data[i], L.data[i+1]);
            isfound = true;
            break;
        }
    }
    if(!isfound)
    {
        int j;
        for(int i = 0; i < L.length; i++)
        {
            if(x < L.data[i]) 
            {
                for(j = L.length - 1; j >= i; j--)
                {
                    L.data[j + 1] = L.data[j];
                }
                L.data[i] = x;
                L.length++;
                break;
            }
        }
    }
    return true;
}

void listPrint(SqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
int main()
{
    //初始化
    SqList L;
    initList(L);
    for(int i = 0; i < 8; i++)
    {
        L.data[i] = i;
    }
    L.data[4] = 3;
    L.length = 8;
    listPrint(L);

    //查找
    ElemType x = 4;
    find_x(L, x);
    listPrint(L);
    return 0;
}