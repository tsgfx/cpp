#include <iostream>
#include <dirent.h>
using namespace std;
int main(int argc, char *argv[])
{
    if(argc != 2) 
    {
        cout << "Using ./demo 目录名\n";
        return -1;
    }
    DIR *dir;
    //打开目录
    if((dir = opendir(argv[1])) == nullptr) return -1;
    //用于存放从目录中读取到的内容
    struct dirent *stdinfo = nullptr;
    while(1)
    {
        //读取一项内容并显示
        if((stdinfo = readdir(dir)) == nullptr) break;
        cout << "文件名=" << stdinfo->d_name << ",文件类型=" << (int)stdinfo->d_type << endl;
    }
    closedir(dir); //关闭目录指针
}