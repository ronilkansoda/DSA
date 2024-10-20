#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// By iteration, time complexity => O(logn) and space complexity =O(1) (more optimize)
int sigleElemSA(vector<int> nums)
{
    int n = nums.size();
    int st = 0, end = n - 1;

    // Edge cases
    if (n == 1)
        return nums[0];

    while (st <= end)
    {
        int mid = st + (end - st) / 2; // at if st and end is INT_MAX then it will overflow

        // Edge cases
        if (mid == 0 && nums[0] != nums[1])
            return nums[mid];
        if (mid == n - 1 && nums[n - 1] != nums[n - 2])
            return nums[mid];

        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (mid % 2 == 0) // for Even
        {
            if (nums[mid + 1] == nums[mid]) // Goes Right side
            {
                st = mid + 1;
            }
            else // Goes Left side
            {
                end = mid - 1;
            }
        }
        else // for Odd
        {
            if (nums[mid - 1] == nums[mid]) //Goes Right side
            {
                st = mid + 1;
            }
            else //Goes Left side
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {3,3,7,7,11,11};

    int result = sigleElemSA(nums);

    cout << result << endl;

    return 0;
}