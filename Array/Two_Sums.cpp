#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSums(vector<int> &nums, int target)
{
    map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, 1};
}

int main()
{
    vector<int> arr = {3, 2, 4};
    int target = 6;

    vector<int> result = twoSums(arr, target);

    cout << "Indices : [" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}
