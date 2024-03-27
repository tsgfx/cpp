#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    char path1[256];
    getcwd(path1, 256);
    cout << "path1 = " << path1 << endl;

    char *path2 = get_current_dir_name();
    cout << "path2 = " << path2 << endl;
    free(path2); 

    
}