#include <iostream>
typedef int ElemType;
using namespace std;

typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode, *LinkList;

void initLinkList(LinkList& L)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->next = nullptr;
}

LNode* getNode(LinkList L, int pos)
{
    int i = 0;
    while(L != nullptr && i < pos)
    {
        L = L->next;
        i++;
    }
    if(L == nullptr || i > pos) return nullptr;
    return L;
}

int getLength(LinkList L)
{
    int i = 0;
    while(L->next != nullptr)
    {
        L = L->next;
        i++;
    }
    return i;
}

bool headInsert(LinkList& L, ElemType elem)
{
    LNode *newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = elem;
    newNode->next = L->next;
    L->next = newNode;
    return true;
}

bool backInsert(LinkList& L, ElemType elem)
{
    LNode *newNode = new LNode;
    newNode->data = elem;
    LNode *lastNode = getNode(L, getLength(L)); //获取尾结点
    newNode->next = nullptr;
    lastNode->next = newNode; //更新尾结点
    return true;
}

bool deleteMin(LinkList& L)
{
    LNode *minNode = L->next;
    LNode *preMinNode = L;
    LNode* preNode = L->next;
    LNode* p = minNode->next;
    if(minNode == nullptr) return false;
    if(p == nullptr) 
    {
        preMinNode->next = nullptr;
        free(minNode);
    }
    while(p->next)
    {
        if(p->data < minNode->data)
        {
            minNode = p;
            preMinNode = preNode;
        }
        p = p->next;
        preNode = preNode->next; 
    }
    preMinNode->next = minNode->next;
    free(minNode);
    return true;
}

void printList(LinkList L)
{
    L = L->next;
    while(L)
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

int main()
{
    //初始化
    LinkList L;
    initLinkList(L);

    //前插
    headInsert(L, 9);
    headInsert(L, 8);
    headInsert(L, 7);
    printList(L);

    //后插
    backInsert(L, 1);
    backInsert(L, 2);
    backInsert(L, 3);
    printList(L);

    //删除最小值结点
    deleteMin(L);
    printList(L);
    return 0;
}