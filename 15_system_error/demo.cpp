#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int ii;
    for(ii = 0; ii < 150; ii++)
    {
        cout << ii << ":" << strerror(ii) << endl;
    }
    return 0;
}