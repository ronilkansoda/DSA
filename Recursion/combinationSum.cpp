#include <bits/stdc++.h>

using namespace std;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        // if target difference decrease thai 0 thai jai to ds vector(array) ma je append kariyu che e return karisu as ans
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        // aa nichenu recursion if mare 2ej repeat karvu hoi ena mate
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    //  aa nichenu recursion if mara ds ma 2,2 che and target = 7-4 = 3 thayu to indx increase kari next number ma javamate
    findCombination(ind + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}
int main()
{
    vector<int>
        v{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}