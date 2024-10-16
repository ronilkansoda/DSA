#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> moveZero(vector<int> nums)
{
    int j = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j++;
        }
        else if (j > 0)
        {
            int t = nums[i];
            nums[i] = 0;
            nums[i - j] = t;
        }
    }
    return nums;
}

int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};

    vector<int> result = moveZero(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}