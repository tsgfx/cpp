#include <iostream>
using namespace std;
typedef int ElemType;
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

LNode* GetPreElem(LinkList L, int pos)
{
    for(int i = 0; i < pos - 1; i++)
    {
        L = L->next;
    }
    return L;
}

void headInsert(LinkList& L, ElemType elem, int pos)
{
    LNode *newNode = (LNode*)malloc(sizeof(LNode));
    LNode *preNode = GetPreElem(L, pos);
    newNode->data = elem;
    newNode->next = preNode->next;
    preNode->next = newNode;
}

bool delete_x(LinkList& L, ElemType x)
{
    LNode  *p = L->next;
    LNode *preNode = L;
    LNode *temp = nullptr;
    while(p)
    {
        if(p->data == x)
        {
            temp = p;
            p = p->next;
            preNode->next = p;
            free(temp);
        }
        else
        {
            preNode = p;
            p = p->next;
        }
    }
    return true;
}

void listPrint(LinkList L)
{
    L = L->next;
    while(L != nullptr) 
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}
int main()
{
    LinkList L;
    initLinkList(L);
    headInsert(L, 1, 1);
    headInsert(L, 2, 1);
    headInsert(L, 3, 1);
    headInsert(L, 4, 1);
    listPrint(L);
    delete_x(L, 1);
    listPrint(L);
    return 0;
}