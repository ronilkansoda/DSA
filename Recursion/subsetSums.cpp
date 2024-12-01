#include <iostream>
#include <vector>
using namespace std;

void subRecursion(vector<int> &nums, int index, int currentSum, vector<int> &result)
{
    result.push_back(currentSum);

    // aa first time i=1 mate cur=[[],[1],[1,2],[1,2,3]] thase and subRecursion thai curr=[] thase pachi 2nd time for loop farse with i = 2
    for (int i = index; i < nums.size(); ++i)
    {

        // Recursively generate further subsets
        subRecursion(nums, i + 1, currentSum + nums[i], result);
    }
}

// TC = O(2^n * n) and SC = O(n)
vector<int> subsets(vector<int> &nums)
{
    vector<int> result;
    subRecursion(nums, 0, 0, result);
    return result;
}

int main()
{
    vector<int> nums = {5, 6, 7};
    vector<int> result = subsets(nums);

    // Print the result
    cout << "Subset Sums: ";
    for (int sum : result)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}