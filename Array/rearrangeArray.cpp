#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <map>
using namespace std;

// My approch with time and spance complexity O(n)
vector<int> rearrangeArray1(vector<int> &nums)
{
    vector<int> pos, neg, res;

    for (int num : nums)
    {
        if (num > 0)
        {
            pos.push_back(num);
        }
        else if (num < 0)
        {
            neg.push_back(num);
        }
    }

    int i = 0, j = 0;
    while (i < pos.size() || j < neg.size())
    {
        if (i < pos.size())
        {
            res.push_back(pos[i++]);
        }
        if (j < neg.size())
        {
            res.push_back(neg[j++]);
        }
    }

    return res;
}

// Better approch with time and spance complexity O(n)
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> res(nums.size());
    int posIdx = 0, negIdx = 1; // Even indices for positives, odd for negatives

    for (int num : nums)
    {
        if (num > 0)
        {
            res[posIdx] = num;
            posIdx += 2;
        }
        else
        {
            res[negIdx] = num;
            negIdx += 2;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> result = rearrangeArray(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}