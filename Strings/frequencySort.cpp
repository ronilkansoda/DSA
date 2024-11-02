#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> mp;
    for (auto it : s)
    {
        mp[it]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }
    string res;
    while (!pq.empty())
    {
        int val = pq.top().first;
        while (val--)
        {
            res += pq.top().second;
        }
        pq.pop();
    }
    return res;
}

int main()
{
    string s1 = "tree";

    cout << frequencySort(s1) << endl;

    return 0;
}