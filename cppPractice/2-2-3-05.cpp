#include <iostream>
#define ElemType int
#define MaxSize 10
using namespace std;

typedef struct 
{
    ElemType data[MaxSize];
    int length;
}SqList;

bool initList(SqList &L)
{
    L.length = 0;
    return true;
}

bool repeatDelete(SqList &L)
{
    if(L.length == 0) return false;
    int i, j;
    for(i = 0, j = 1; j < L.length; j++)
    {
        if(L.data[i] != L.data[j]) 
        {
            i++;
            L.data[i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}

void listPrint(SqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
}
int main()
{
    SqList L;
    initList(L);
    L.length = 5;
    for(int i = 0; i < L.length; i++)
    {
        L.data[i] = 3;
    }
    L.data[3] = 4;
    L.data[4] = 5;
    listPrint(L);
    repeatDelete(L);
    cout << endl;
    listPrint(L);
    cout << endl;
    return 0;
}