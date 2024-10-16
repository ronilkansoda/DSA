#include <iostream>
#include <vector>
using namespace std;

// Brute Force O(n^2)
vector<int> pairSum1(vector<int> nums, int target)
{
    int n = nums.size();
    vector<int> ans = {-1, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

// Optimized way O(n)
vector<int> pairSum(vector<int> nums, int target)
{
    int n = nums.size();
    int i = 0, j = n - 1;
    vector<int> ans;

    while (i < j)
    {
        int ps = nums[i] + nums[j];
        if (ps > target)
        {
            j--;
        }
        else if (ps < target)
        {
            i++;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> num = {2, 7, 11, 15};
    int target = 26;

    vector<int> result = pairSum(num, target);

    cout << result[0] << "," << result[1] << endl;

    return 0;
}