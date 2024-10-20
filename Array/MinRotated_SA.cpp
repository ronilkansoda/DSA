#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// By iteration, time complexity => O(logn) and space complexity =O(1) (more optimize)
int MinRotated_SA1(vector<int> nums)
{
    int n = nums.size();
    int st = 0, end = n - 1;

    while (st <= end)
    {
        // int mid = (st + end) / 2;
        int mid = st + (end - st) / 2; // at if st and end is INT_MAX then it will overflow

        int mini = min(nums[st], min(nums[mid], nums[end]));

        if (nums[st] < nums[mid] && nums[st] < nums[end])
        {
            end = mid - 1;
        }
        else if (nums[end] < nums[mid] && nums[end] < nums[st])
        {
            st = mid + 1;
        }
        else
        {
            return nums[mid];
        }
    }

    return -1;
}

int MinRotated_SA(vector<int> nums)
{
    int n = nums.size();
    int st = 0, end = n - 1;
    int mini = INT_MAX;

    if (nums[st] < nums[end])
    {
        retrun nums[st];
    }

    while (st <= end)
    {
        // int mid = (st + end) / 2;
        int mid = st + (end - st) / 2; // at if st and end is INT_MAX then it will overflow

        if (nums[st] <= nums[mid]) // left sorted
        {
            mini = min(mini, nums[st]);
            st = mid + 1;
        }
        else // right sorted
        {
            mini = min(mini, nums[mid]);
            end = mid - 1;
        }
    }

    return mini;
}

int main()
{
    vector<int> nums = {5, 1, 2, 3, 4};

    int result = MinRotated_SA(nums);

    cout << result << endl;

    return 0;
}