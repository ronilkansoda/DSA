#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// By iteration, time complexity => O(logn) and space complexity =O(1) (more optimize)
void rotate(vector<int> &nums, int k)
{
    // int n = nums.size();
    // k = k % n;

    // int temp[k]; // storing in temp
    // for (int i = 0; i < k; i++)
    // {
    //     temp[i] = nums[n - k + i];
    // }

    // // moving last element to first positions
    // for (int i = k; i < n; i++)
    // {
    //     nums[i - k] = nums[i];
    // }

    // // moving first element to last positions
    // for (int i = n - k; i < n; i++)
    // {
    //     nums[i] = temp[i - (n - k)];
    // }

    int n = nums.size();
    if (n == 0 || k == 0)
    {
        return;
    }
    k = k % n;

    vector<int> temp(nums.end() - k, nums.end());

    for (int i = n - k - 1; i >= 0; i--)
    {
        nums[i + k] = nums[i];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}