#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int getCommon(vector<int> &nums1, vector<int> &nums2) // O(m+n)
{
    unordered_set<int> set2(nums2.begin(), nums2.end()); // O(m)

    int mini = INT_MAX;
    for (int i = 0; i < nums1.size(); i++) // O(n)
    {
        if (set2.find(nums1[i]) != set2.end())
        {
            mini = min(mini, nums1[i]);
        }
    }
    if (mini == INT_MAX)
    {
        return -1;
    }
    return mini;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 6};
    vector<int> arr2 = {7, 8, 9, 10};

    cout << "The smallest element common to both arrays is : " << getCommon(arr1, arr2);

    return 0;
}