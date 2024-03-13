#include <iostream>
#define MaxSize 5
using namespace std;
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode; //结点没有头指针和尾指针

typedef struct
{
    LNode *front, *rear;
}LinkQueue; //队列才有头尾指针, 头尾指针指向结点

bool InitLinkQueue(LinkQueue& Q)
{
    Q.front = Q.rear = new LNode;
    Q.front->next = nullptr;
    return true;
}

bool IsEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear) return true;
    return false;
}

bool EnQueue(LinkQueue& Q, ElemType elem)
{
    LNode *newNode = new LNode;
    newNode->data = elem;
    newNode->next = nullptr;
    Q.rear->next = newNode;
    Q.rear = newNode;
    return true;
}

bool DeQueue(LinkQueue& Q, ElemType& elem)
{
    if(Q.front->next == nullptr) return false;
    LNode *tempNode = new LNode;
    tempNode = Q.front->next;
    elem = tempNode->data;
    Q.front->next = tempNode->next;
    delete tempNode;
    return true;
}

int main()
{
    LinkQueue Q;
    InitLinkQueue(Q);
    EnQueue(Q, 'a');
    EnQueue(Q, 'b');
    EnQueue(Q, 'c');
    ElemType elem;
    DeQueue(Q, elem);
    cout << elem << " ";
    DeQueue(Q, elem);
    cout << elem << " ";
    DeQueue(Q, elem);
    cout << elem << " ";
    cout <<  endl;
    return 0;
}