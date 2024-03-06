#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    int ret = execl("/bin/ls", "/bin/ls", "/tmp", 0);
    cout << "ret=" << ret << endl;
    perror("execl");
}