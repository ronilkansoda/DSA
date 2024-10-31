#include <iostream>
#include <string>
#include <map>
using namespace std;

int beautySum(string s)
{
    int ans = 0;

    for (int start = 0; start < s.length(); start++)
    {
        map<char, int> mp;
        for (int end = start; end < s.length(); end++)
        {
            mp[s[end]]++;
            int leastFrequent = INT_MAX;
            int mostFrequent = INT_MIN;
            for (auto it : mp)
            {
                leastFrequent = min(leastFrequent, it.second);
                mostFrequent = max(mostFrequent, it.second);
            }
            ans += mostFrequent - leastFrequent;
        }
    }
    return ans;
}

int main()
{
    string s1 = "aabcb";

    cout << beautySum(s1) << endl;

    return 0;
}