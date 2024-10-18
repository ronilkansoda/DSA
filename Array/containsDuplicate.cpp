#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force Approch
bool containsDuplicate1(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// O(n)
bool containsDuplicate(vector<int> nums)
{
    int n = nums.size();
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        if (mpp.find(nums[i]) != mpp.end())
        {
            return true;
        }
        mpp[nums[i]] = i;
    }

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};

    bool result = containsDuplicate(arr);

    cout << boolalpha << result << endl;

    return 0;
}