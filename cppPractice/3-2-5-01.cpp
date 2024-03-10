#include <iostream>
#define MaxSize 3
using namespace std;
typedef char ElemType;
typedef struct 
{
    ElemType *data;
    int front, rear;
    int tag;
}SqQueue;

bool InitQueue(SqQueue& Q)
{
    Q.data = new ElemType[MaxSize];
    Q.front = Q.rear = 0;
    Q.tag = 0; 
    return true;
}

bool EnQueue(SqQueue& Q, ElemType elem)
{
    if(Q.rear == Q.front && Q.tag == 1) return false;
    Q.data[Q.rear] = elem;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1; //入队后，队列中肯定有元素，不为空tag=1
    return true;
}

bool DeQueue(SqQueue& Q, ElemType& elem)
{
    if(Q.rear == Q.front && Q.tag == 0) return false;
    elem = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0; //出队后，队列中肯定有空位, 不会溢出tag=0
    return true;
}
int main()
{
    SqQueue Q;
    InitQueue(Q);
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
    EnQueue(Q, 'd');
    DeQueue(Q, elem);
    cout << elem << " ";
    cout << endl;
    return 0;
}