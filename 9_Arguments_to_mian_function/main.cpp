#include <iostream>
using namespace std;

int main(int argc,char *argv[],char *envp[])
{
  if (argc!=4)
  {
    cout << "表白神器程序的使用方法：./demo 追求者姓名 被追求者姓名 表白内容\n";
    return -1;
  }

  cout << argv[1] << "开始向" << argv[2] << "表白。\n";
  cout << argv[3] << endl;
  cout << argv[1] << "表白完成。\n";

  //return 0;

  cout << "一共有" << argc << "个参数。\n";

  // 显示全部的参数。
  for (int ii=0;ii<argc;ii++)
  {
    cout << "第" << ii << "个参数：" << argv[ii] << endl;
  }
  // 显示全部的环境变量。
  for (int ii=0;envp[ii]!=0;ii++)  // 环境变量数组最后一个元素是0。
  {
    cout << envp[ii] << endl;
  }

  // 设置环境变量AA。
  setenv("AA","aaaa",0);

  // 显示环境变量AA的值。
  cout << "AA=" << getenv("AA") << endl;

  return 0;
}
