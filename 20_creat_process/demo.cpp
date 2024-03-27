#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
  int bh=8;
  string message="我是一只傻傻鸟。";

  pid_t pid=fork();

  if (pid>0)
  { // 父进程将执行这段代码。
    sleep(1);
    cout << "父：pid=" << pid << endl;
    cout << "父：亲爱的" << bh << "号：" << message << endl;
  }
  else
  { // 子进程将执行这段代码。
    bh=3; message="你是一只傻傻鸟。";
    cout << "子：pid=" << pid << endl;
    cout << "子：亲爱的" << bh << "号：" << message << endl;
  }
}

