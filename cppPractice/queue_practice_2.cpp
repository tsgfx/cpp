#include <iostream>
#define MaxSize 5
using namespace std;
typedef char ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

bool InitQueue(SqQueue& Q)
{
    Q.rear = 0;
    Q.front = 1;
    return true;
}

bool EnQueue(SqQueue& Q, ElemType elem)
{
    if(((Q.rear + 1 - Q.front) + MaxSize) % MaxSize == MaxSize - 1) return false;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.data[Q.rear] = elem;
    return true;
}

bool DeQueue(SqQueue& Q, ElemType& elem)
{
    if((Q.rear + 1) % MaxSize == Q.front) return false;
    elem = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
int main()
{
    SqQueue Q;
    InitQueue(Q);
    ElemType elem;
    EnQueue(Q, 'a');
    EnQueue(Q, 'b');
    EnQueue(Q, 'c');
    EnQueue(Q, 'd');
    //EnQueue(Q, 'e');
    //EnQueue(Q, 'f');
    DeQueue(Q, elem);
    printf("%c\n", elem);
    DeQueue(Q, elem);
    printf("%c\n", elem);
    DeQueue(Q, elem);
    printf("%c\n", elem);
    DeQueue(Q, elem);
    printf("%c\n", elem);
    //DeQueue(Q, elem);
    //printf("%c\n", elem);
    return 0;
}