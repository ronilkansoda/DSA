#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// Brute Force O(n^2)
bool check(vector<int> &nums)
{
    int n = nums.size();
    int Cdiff = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
        {
            Cdiff++;
        }
        if (Cdiff > 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // vector<int> arr = {2, 1, 3, 4};
    vector<int> arr = {3, 4, 5, 1, 2};
    // vector<int> arr = {1, 2, 3};

    bool res = check(arr);

    cout << res;

    return 0;
}