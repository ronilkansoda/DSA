#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// By iteration, time complexity => O(logn) and space complexity =O(1) (more optimize)
int RotatedSortedArray(vector<int> nums, int target)
{
    int n = nums.size();
    int st = 0, end = n - 1;

    while (st <= end)
    {
        // int mid = (st + end) / 2;
        int mid = st + (end - st) / 2; // at if st and end is INT_MAX then it will overflow

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[st] <= nums[mid]) // left sorted
        {
            if (nums[st] <= target && target <= nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else // right sorted
        {
            if (nums[mid] <= target && target <= nums[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 10;

    int result = RotatedSortedArray(nums1, target1);

    cout << result << endl;

    return 0;
}