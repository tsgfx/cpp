#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    if(fork() > 0)
    {
        sleep(20);
        cout << "父进程退出。" << endl;
        return 0;
    }
    else 
    {
        for(int i = 0 ; i < 100; i++)
        {
            cout << "子进程继续运行中。" << endl;
            sleep(1);
        }
    }
}