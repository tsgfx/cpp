#include <iostream>
#define MaxSize 5
using namespace std;
typedef char ElemType;
typedef struct
{
    ElemType *data;
    int top;
} Stack;

bool initStack(Stack &S)
{
    //S.data = (ElemType*)malloc(sizeof(ElemType) * MaxSize);
    S.data = new ElemType[MaxSize];
    S.top = -1;
    return true;
}

bool stackIsEmpty(Stack S)
{
    return S.top == -1 ? true : false;
}

bool Push(Stack &S, ElemType elem)
{
    if (S.top == MaxSize - 1) //S.top == MaxSize - 1;
        return false;
    S.data[++S.top] = elem;
    return true;
}

bool Pop(Stack &S, ElemType &elem)
{
    if (S.top >= MaxSize || S.top == -1)
        return false;
    elem = S.data[S.top--];
    return false;
}

bool getTop(Stack S, ElemType elem)
{
    if(S.top == -1) return false;
    elem = S.data[S.top];
    return true;
}

int main()
{
    Stack S;
    initStack(S);
    Push(S, 'a');
    Push(S, 'b');
    Push(S, 'c');
    Push(S, 'd');
    Push(S, 'e');
    ElemType elem;
    Pop(S, elem);
    printf("%c\n", elem);
    Pop(S, elem);
    printf("%c\n", elem);
    Pop(S, elem);
    printf("%c\n", elem);
    cout << stackIsEmpty(S) << endl;
    getTop(S, elem);
    cout << elem << endl;
    return 0;
}