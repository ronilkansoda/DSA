#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> nums, int val)
{
    int j = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main()
{
    vector<int> arr = {0,1,2,2,3,0,4,2};
    int value = 2;

    int result = removeDuplicates(arr, 3);

    cout << "Total Different Number's are : " << result << endl;
    return 0;
}