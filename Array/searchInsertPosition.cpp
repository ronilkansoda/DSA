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
    vector<int> arr = {1, 3, 5, 6};
    int target = 5;

    int res = searchInsert(arr, target);
    cout << res << endl;
    return 0;
}