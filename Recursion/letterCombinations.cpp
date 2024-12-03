#include <bits/stdc++.h>
using namespace std;

// TC = O(4^n)(as at max it will run for "wxyz") and SC = O(n⋅4^n)
void solve(string digits, string output, int ind, vector<string> &ans, string mapping[])
{
    if (ind >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[ind] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, ind + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
        return ans;
    string output;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, 0, ans, mapping);
    return ans;
}

int main()
{
    vector<string> ans = letterCombinations("529");

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }

    return 0;
}