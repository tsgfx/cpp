#include <iostream>
typedef int ElemType;
using namespace std;

bool reverse(ElemType A[], int begin, int end)
{
    if(begin >= end) return false;
   int mid = (begin + end) / 2;
   for(int i = 0; i <= mid - begin; i++)
   {
        ElemType temp = A[begin + i];
        A[begin + i] = A[end - i];
        A[end - i] = temp;
   }
   return true;
}

bool ListExchange(ElemType A[], int m, int n, int maxsize)
{
    if(m + n > maxsize) return false;
    reverse(A, 0, m+n-1);
    reverse(A, 0, m-1);
    reverse(A, m, m+n-1);
    return true;
}

void listPrint(ElemType A[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    ElemType A[10] = {1, 2, 3, 4, 5, 9, 8, 7, 6, 5};
    listPrint(A, 10);
    ListExchange(A, 5, 5, 10);
    listPrint(A, 10);
    return 0;
}