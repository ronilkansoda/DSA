#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

bool isValid(vector<int> nums, int n, int m, int maxAllowedpages) // O(n)
{
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > maxAllowedpages)
        {
            return false;
        }

        if (pages + nums[i] <= maxAllowedpages)
        {
            pages += nums[i];
        }
        else
        {
            students++;
            pages = nums[i];
        }
    }

    return students > m ? false : true;
}

int allocateBooks(vector<int> nums, int n, int m) // O(logN * n)
{
    if (m > n)
    {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    int ans = -1;

    int st = 0, end = sum;

    while (st <= end)
    {
        // int mid = (st + end) / 2;
        int mid = st + (end - st) / 2; // at if st and end is INT_MAX then it will overflow

        if (isValid(nums, n, m, mid)) // left side
        {
            ans = mid;
            end = mid - 1;
        }
        else // right side
        {
            st = mid + 1;
        }
    }

    return ans;
}

int main()
{
    // vector<int> nums = {2, 1, 3, 4};
    vector<int> nums = {15, 17, 20};
    
    int n = 3, m = 2; // it must be m > n

    int result = allocateBooks(nums, n, m);

    cout << result << endl;

    return 0;
}