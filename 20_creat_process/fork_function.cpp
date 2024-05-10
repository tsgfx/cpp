#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    int number = 1;
    string message = "Hello world!";

    // 创建一个子进程
    pid_t pid = fork();

    // 输出返回值 父进程的返回值为子进程的ID 子进程的返回值为0
    // 因此可以通过返回值的不同让父进程和子进程执行不同的代码
    cout << "pid = " << pid << endl;

    // 下面的代码子进程执行一遍，父进程执行一遍
    // 输出两次
    cout << "Output message No." << number << " which context are " << message << endl;

    // 延时程序
    //  使用ps -ef | grep fork_function 查看进程列表
    //  使用pstree -p 进程号 查看哪个进程是父进程 pid小的为父进程
    sleep(20);
    cout << "Code end" << endl;
    return 0;
}