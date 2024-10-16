#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target)
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

int main()
{
    vector<int> num = {2, 7, 11, 15};
    int target = 7;

    vector<int> result = pairSum(num, target);

    cout << "[" << result[0] << "," << result[1] << "]" << endl;
}