#include <iostream>
#include <unistd.h>
using namespace std;

void func1()
{
    cout << "调用了func1()\n";
}

void func2()
{
    cout << "调用了func2()\n";
}

int main(int argc, char *argv[])
{
    atexit(func1); //登记第1个进程终止函数
    atexit(func2); //登记第2个进程终止函数
    return 0;
}