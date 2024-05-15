#include <iostream>
#include <unistd.h>
#include <wait.h>
using namespace std;

void func(int sig)
{
    int sts;                // 接收子进程退出信息
    pid_t pid = wait(&sts); // 等待子进程退出
    cout << "已终止的子进程的编号是：" << pid << endl;
    if (WIFEXITED(sts))
    {
        // 参考 2.进程终止
        cout << "子进程是正常退出的，退出状态是：" << WEXITSTATUS(sts) << endl;
    }
    else
    {
        cout << "子进程是异常退出的，终止它的信号是：" << WTERMSIG(sts) << endl;
    }
}

int main()
{
    signal(SIGCHLD, func); // 捕获子进程退出的信号
    if (fork() > 0)
    {
        while (true)
        {
            cout << "父进程忙着执行任务。" << endl;
            sleep(1);
        }
    }
    else
    {
        sleep(5);
        int *p = nullptr;
        *p = 10;
        exit(1);
    }
}