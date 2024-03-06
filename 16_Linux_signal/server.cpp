#include <iostream>
#include <unistd.h>
#include <signal.h>

void EXIT(int sig)
{
    std::cout << "收到了信号：" << sig << std::endl;
    std::cout << "正在释放资源，程序将退出......\n";
    //一下可以编写释放资源的代码

    std::cout << "程序退出。" << std::endl;
    exit(0);
}

int main()
{
    //忽略全部信号，防止程序被信号异常终止
    for(int ii = 1; ii <= 64; ii++) signal(ii, SIG_IGN);
    //收到2和5的信号时程序退出(Ctrl+C和kill、killall)
    signal(2, EXIT);
    signal(15, EXIT);
    while(true) 
    {
        std::cout << "执行了一次任务。\n";
        sleep(1); 
    }
    return 0;
}