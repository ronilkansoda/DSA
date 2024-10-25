#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

int main()
{
    // vector<int> arr = {-1, 0, 1, 2, -1, -4};
    // vector<int> arr = {0, 0, 0};
    vector<int> arr = {0, 1, 1};

    int res = searchInsert(arr, 4);

    printResult(result);
    return 0;
}