#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityEle1(vector<int> nums)
{
    int n = nums.size();

    // sort
    sort(nums.begin(), nums.end());

    // freq count
    int freq = 1, ans = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }

        if (freq > (n / 2))
        {
            return ans;
        }
    }
    return ans;
}
int majorityEle(vector<int> nums)
{
    int n = nums.size();

    int freq = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }

        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    freq = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ans)
        {
            freq++;
        }
    }

    if (freq > n / 2)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> num = {1, 2, 2, 1, 1, 1,3};

    int result = majorityEle(num);

    cout << "Result : " << result << endl;

    return 0;
}