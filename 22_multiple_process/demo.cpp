#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;
void FathEXIT(int sig);
void ChilEXIT(int sig);

int main()
{
    //忽略全部信号
    for(int i = 1; i < 64; i++) signal(i, SIG_IGN);
    
    //设置信号，在shell状态下可用"kil进程号"或"Ctrl+C"正常终止这些进程
    //但请不要用"kill -9 + 进程号"强制终止
    signal(SIGTERM, FathEXIT); //15
    signal(SIGINT, FathEXIT); //2

    while(true)
    {
        if(fork() > 0)
        {
            sleep(5);
            continue;
        }
        else
        {
            //子进程需要重新设置信号
            signal(SIGTERM, ChilEXIT); //子进程的退出函数和父进程的不一样
            signal(SIGINT ,SIG_IGN); //子进程不需要捕获SIGINT(Ctrl+C)信号
            while(true)
            {
                cout << "子进程" << getpid() << "正在运行中。\n";
                sleep(3);
                continue; 
            }
        }
    }
}


//父进程处理函数
void FathEXIT(int sig)
{
    // 防止信号处理函数在执行的过程中再次被信号中断
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    cout << "父进程退出， sig=" << sig << endl;
    kill(0, SIGTERM); //通知全部子进程退出
    //在这里增加释放资源的代码
    exit(0);
}

//子进程处理函数
void ChilEXIT(int sig)
{
    // 防止信号处理函数在执行的过程中再次被信号中断
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    cout << "子进程" << getpid() << "退出， sig=" << sig << endl;
    //下方还可增加释放资源的代码（只释放子进程资源）
    exit(0);
}