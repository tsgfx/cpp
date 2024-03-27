#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

bool CreatTree(BiTree& T)
{
    ElemType elem;
    cin >> elem;
    if(elem == '#') T = nullptr;
    else
    {
        T = new BiTNode;
        T->data = elem;
        CreatTree(T->lchild);
        CreatTree(T->rchild);
    }
    return true;
}

void PreorderTree(BiTree T)
{
    if(T == nullptr) return;
    cout << T->data << " ";
    PreorderTree(T->lchild);
    PreorderTree(T->rchild);
}

void InorderTree(BiTree T)
{
    if(T == nullptr) return;
    InorderTree(T->lchild);
    cout << T->data << " ";
    InorderTree(T->rchild);
}

int main()
{
    BiTree T;
    CreatTree(T);
    PreorderTree(T);
    cout << endl;
    InorderTree(T);
    cout << endl;
    return 0;
}