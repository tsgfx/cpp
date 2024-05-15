#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    // 让1号进程托管子进程
    if (fork() > 0)
        return 0;
    while (true)
    {
        cout << "服务运行中" << endl;
        sleep(1);
    }
}