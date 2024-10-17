#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approch
vector<int> productOfArray1(vector<int> nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                prod *= nums[j];
            }
        }
        result[i] = prod;
    }

    return result;
}
// O(n) Approch
vector<int> productOfArray2(vector<int> nums)
{
    int n = nums.size();
    vector<int> result(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    // prefix[0] = 1;
    // suffix[n - 1] = 1;

    // prefix
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // p=suffix
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        result[i] = prefix[i] * suffix[i];
    }

    return result;
}

// Optimize Approch
vector<int> productOfArray(vector<int> nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    // prefix
    for (int i = 1; i < n; i++)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }

    int suffix = 1;

    // suffix
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        result[i] *= suffix;
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    // vector<int> arr = {-1, 1, 0, -3, 3};

    vector<int> result = productOfArray(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}