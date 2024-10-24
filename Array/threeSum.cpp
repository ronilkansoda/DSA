#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

// Brute Force approch O(n^3 * log(no. of unique triplates)) and space is 2 * O(no. of unique triplates)
vector<vector<int>> threeSum1(vector<int> &nums)
{
    set<vector<int>> st;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// More optimize approch O(n^2 * log(size of the set => hashset)) and space is O(n) + 2 * O(no. of unique triplates)
vector<vector<int>> threeSum2(vector<int> &nums)
{
    set<vector<int>> st;

    for (int i = 0; i < nums.size(); i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < nums.size(); j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Most optimize approch O(n^2)+ O(nlog(n)) and space is O(n) + 2 * O(no. of unique triplates)
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);

                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }

    return ans;
}

void printResult(const vector<vector<int>> &result)
{
    cout << "[";
    for (const auto &triplet : result)
    { // Iterate through each inner vector
        cout << "[";
        for (int num : triplet)
        { // Iterate through each element in the inner vector
            cout << num << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main()
{
    // vector<int> arr = {-1, 0, 1, 2, -1, -4};
    // vector<int> arr = {0, 0, 0};
    vector<int> arr = {0, 1, 1};

    vector<vector<int>> result = threeSum(arr);

    printResult(result);
    return 0;
}