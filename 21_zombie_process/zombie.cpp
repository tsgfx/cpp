#include <iostream>
#include <unistd.h>
// #include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    // 如果子进程比父进程先退出，而父进程没有处理子进程退出的信息，那么，子进程将成为僵尸进程。
    // 使用signal忽略子进程退出的信号，子进程退出后会立即释放数据结构。
    signal(SIGCHLD, SIG_IGN);
    if (fork() == 0)
        return 0;
    while (true)
    {
        cout << "父进程服务运行中" << endl;
        sleep(1);
    }
}