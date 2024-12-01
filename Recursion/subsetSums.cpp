#include <iostream>
#include <vector>
using namespace std;

void subRecursion(vector<int> &nums, int index, int currentSum, vector<int> &result)
{
    result.push_back(currentSum);

    for (int i = index; i < nums.size(); ++i)
    {

        subRecursion(nums, i + 1, currentSum + nums[i], result);
    }
}

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