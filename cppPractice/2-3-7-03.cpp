#include <iostream>
using namespace std;
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void initLinkList(LinkList& L)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->next == nullptr;
}

bool headInsert(LinkList& L, ElemType elem)
{
    LNode *newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = elem;
    newNode->next = L->next;
    L->next = newNode;
    return true;
}

LNode* getNode(LinkList L, int pos)
{
    int i = 0;
    if(L == nullptr || i > pos) return nullptr;
    while(L != nullptr && i < pos)
    {
        i++;
        L = L->next;
    }
    return L;
}

int getLength(LinkList L)
{
    int length = 0;
    while(L->next) 
    {
        length++;
        L = L->next;
    }
    return length;
}

bool backInsert(LinkList& L, ElemType elem)
{
    LNode *newNode = (LNode*)malloc(sizeof(LNode));
    LNode *preNode = getNode(L, getLength(L));
    newNode->data = elem;
    newNode->next = preNode->next;
    preNode->next = newNode;
    return true;
}

void printLinkList(LinkList L)
{
    L = L->next;
    while(L)
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

//03
void reverse(LinkList& L)
{
    LNode *tempNode = L->next;
    L->next = nullptr;
    while(tempNode)
    {
        headInsert(L, tempNode->data);
        tempNode = tempNode->next;
    }
}

//04
void deleteBetween(LinkList&L, ElemType a, ElemType b)
{
    LNode *p = L;
    while(p->next)
    {
        if(p->next->data > a && p->next->data < b)
        {
            LNode *tempNode = p->next;
            p->next = tempNode->next;
            free(tempNode);
        }
        else
        {
            p = p->next; //当没有发生删除操作时，指针后移
        }
    }
}

//06
void seperateList(LinkList L, LinkList& L1, LinkList& L2)
{
    LNode *a = L->next;
    LNode *b = a->next;
    while(b->next != nullptr)
    {
        backInsert(L1, a->data);
        headInsert(L2, b->data);
        a = b->next;
        b = a->next;
    }
    backInsert(L1, a->data);
    headInsert(L2, b->data);
}

int main()
{
    LinkList L;
    initLinkList(L);
    headInsert(L, 3);
    headInsert(L, 2);
    headInsert(L, 1);
    backInsert(L, 4);
    backInsert(L, 5);
    backInsert(L, 6);
    printLinkList(L);
    reverse(L);
    printLinkList(L);
    //deleteBetween(L, 1, 7);
    //printLinkList(L);
    LinkList L1;
    LinkList L2;
    initLinkList(L1);
    initLinkList(L2);
    seperateList(L, L1, L2);
    printLinkList(L1);
    printLinkList(L2);

    return 0;
}