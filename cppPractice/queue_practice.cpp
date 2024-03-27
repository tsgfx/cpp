#include <iostream>
#define MaxSize 5
using namespace std;
typedef char ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

bool initSqQueue(SqQueue& Q)
{
    Q.front = Q.rear = 0;
    return true;
}

bool enQueue(SqQueue& Q, ElemType elem)
{
    if(Q.rear == MaxSize) return false;
    Q.data[Q.rear++] = elem;
    return true;
}

bool deQueue(SqQueue& Q, ElemType& elem)
{
    if(Q.rear == 0 || Q.front == MaxSize + 1) return false;
    elem = Q.data[Q.front++];
    return true;
}
int main()
{
    SqQueue Q;
    initSqQueue(Q);
    ElemType elem;
    enQueue(Q, 'a');
    enQueue(Q, 'b');
    enQueue(Q, 'c');
    enQueue(Q, 'd');
    enQueue(Q, 'e');
    enQueue(Q, 'f');
    deQueue(Q, elem);
    printf("%c\n", elem);
    deQueue(Q, elem);
    printf("%c\n", elem);
    deQueue(Q, elem);
    printf("%c\n", elem);
    deQueue(Q, elem);
    printf("%c\n", elem);
    deQueue(Q, elem);
    printf("%c\n", elem);
    return 0;
}