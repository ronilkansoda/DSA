#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &result)
{
    // Add the current subset to the result
    result.push_back(current);

    // aa first time i=1 mate cur=[[],[1],[1,2],[1,2,3]] thase and backtrack thai curr=[] thase pachi 2nd time for loop farse with i = 2
    for (int i = index; i < nums.size(); ++i)
    {
        // Include the current element in the subset
        current.push_back(nums[i]);

        // Recursively generate further subsets
        backtrack(nums, i + 1, current, result);

        // this will empty current for i = 2 (means e backtrack thaine current = [] kar dese)
        current.pop_back();
    }
}

// TC = O(2^n * n) and SC = O(n)
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    // Print the result
    for (const auto &subVec : result)
    {
        cout << "[";
        for (int num : subVec)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
// ------------------------------------------------------------------------------------------------------
// my rought solution
vector<vector<int>> subsets1(vector<int> &nums)
{
    vector<vector<int>> result;
    result.push_back({});
    for (int i = 0; i < nums.size(); i++)
    {
        result.push_back({nums[i]});
        for (int j = i + 1; j < nums.size(); j++)
        {
            result.push_back({nums[i], nums[j]});
        }
    }
    result.push_back(nums);
    return result;
}
//            ||
//            \/
//           chat gpt improved solution

vector<vector<int>> subsets2(vector<int> &nums)
{
    vector<vector<int>> result;
    result.push_back({});

    // for first time {{}}
    for (int num : nums)
    {
        int n = result.size();

        for (int i = 0; i < n; ++i)
        {
            // aa niche {{},{}} create karse as result[0] = {} che etle
            result.push_back(result[i]);

            // pachi num = 1 che froms nums[1,2,3] so aa {{},{1}} thai jase
            result.back().push_back(num);
        }
    }

    return result;
}
