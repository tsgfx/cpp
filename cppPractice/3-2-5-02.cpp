#include <iostream>
#define MaxSize 6
using namespace std;
typedef char ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int top;
}Stack;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

bool InitStack(Stack& S)
{
    S.top = -1;
    return true;
}

bool InitSqQueue(SqQueue& Q)
{
    Q.front = Q.rear = 0;
    return true;
}

bool Push(Stack& S, ElemType elem)
{
    if(S.top == MaxSize -1) return false;
    S.data[++S.top] = elem;
    return true;
}

bool Pop(Stack& S, ElemType& elem)
{
    if(S.top == -1) return false;
    elem = S.data[S.top--];
    return true;
}

bool EnQueue(SqQueue& Q, ElemType elem)
{
    if((Q.rear + 1) % MaxSize == Q.front) return false; //(Q.rear + 1 + MaxSize) - Q.front == 0
    Q.data[Q.rear] = elem;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue& Q, ElemType& elem)
{
    if(Q.front == Q.rear) return false;
    elem = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int main()
{
    Stack S;
    InitStack(S);
    SqQueue Q;
    InitSqQueue(Q);
    //初始化队列
    EnQueue(Q, 'a');
    EnQueue(Q, 'b');
    EnQueue(Q, 'c');
    EnQueue(Q, 'd');
    EnQueue(Q, 'e');
    //队列入栈
    ElemType elem;
    DeQueue(Q, elem);
    Push(S, elem);
    DeQueue(Q, elem);
    Push(S, elem);
    DeQueue(Q, elem);
    Push(S, elem);
    DeQueue(Q, elem);
    Push(S, elem);
    DeQueue(Q, elem);
    Push(S, elem);
    //出栈入队列，队列逆置
    Pop(S, elem);
    EnQueue(Q, elem);
    Pop(S, elem);
    EnQueue(Q, elem);
    Pop(S, elem);
    EnQueue(Q, elem);
    Pop(S, elem);
    EnQueue(Q, elem);
    Pop(S, elem);
    EnQueue(Q, elem);
    //出队，打印
    DeQueue(Q, elem);
    cout << elem << " ";
    DeQueue(Q, elem);
    cout << elem << " ";
    DeQueue(Q, elem);
    cout << elem << " ";
    DeQueue(Q, elem);
    cout << elem << " ";
    DeQueue(Q, elem);
    cout << elem << " ";
    cout << endl;
    return 0;
}
