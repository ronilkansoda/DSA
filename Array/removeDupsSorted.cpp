#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> nums)
{
    int j = 1;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main()
{
    vector<int> arr = {3,2,2,3};

    int result = removeDuplicates(arr);

    cout << "Total Different Number's are : " << result << endl;
    return 0;
}