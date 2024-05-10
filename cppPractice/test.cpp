#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums;
    nums = {3, 2, 2, 3};
    int val = 3;
    int length = nums.size();
    for (int i = nums.size(); i >= 0; i--)
    {
        if (nums[i] == val)
        {
            for (int j = i; j < nums.size(); j++)
            {
                nums[j] = nums[j + 1];
            }
            i++;
            length--;
        }
    }
    cout << length << endl;
    return 0;
}