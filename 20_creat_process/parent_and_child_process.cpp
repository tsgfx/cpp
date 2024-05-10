#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    int number = 1;
    string message = "Hello world!";

    // 创建一个子进程
    pid_t pid = fork();

    // 父进程返回值为子进程的id
    if (pid > 0)
    {
        cout << "Parent pid = " << pid << endl;
        cout << "Parent Output message No." << number << " which context are " << message << endl;

        cout << "Parent Output message No." << &number << " which context are " << &message << endl;
    }
    // 子进程返回值为0
    else
    {
        cout << "Child pid = " << pid << endl;
        cout << "Child Output message No." << number << " which context are " << message << endl;

        // 父进程和子进程变量的地址相同（虚拟地址相同），但是不是同一块物理内存
        // 修改子进程的变量值不会改变父进程的变量值
        cout << "Child Output message No." << &number << " which context are " << &message << endl;
    }
    return 0;
}