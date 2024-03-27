#include <iostream>
#define MaxSize 5
using namespace std;

typedef char ElemType;
typedef struct LNode  
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkStack;

bool InitStack(LinkStack& S)
{
    S = new LNode;
    S->next = nullptr;
    return true;
}

bool Push(LinkStack& S, ElemType elem)
{
    LNode* newNode = new LNode;
    newNode->data = elem;
    newNode->next = S->next;
    S->next = newNode;
    return true;
}

bool Pop(LinkStack& S, ElemType& elem)
{
    if(S->next == nullptr) return false;
    LNode * tempNode = S->next;
    elem = tempNode->data;
    S->next = tempNode->next;
    delete tempNode;
    return true;
}

int main()
{
    LinkStack S;
    InitStack(S);
    Push(S, 'a');
    Push(S, 'b');
    Push(S, 'c');
    ElemType elem;
    Pop(S, elem);
    cout << elem << " ";
    Pop(S, elem);
    cout << elem << " ";
    Pop(S, elem);
    cout << elem << " ";
    cout << endl;
    return 0;
}