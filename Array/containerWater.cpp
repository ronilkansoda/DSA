#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approch
int containerWater1(vector<int> height)
{
    int maxWater = 0;
    int n = height.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int w = j - i;
            int h = min(height[i], height[j]);
            int currentWater = w * h;

            maxWater = max(maxWater, currentWater);
        }
    }
    return maxWater;
}

// Optimize Approch
int containerWater(vector<int> height)
{
    int maxWater = 0;
    int n = height.size();
    int lp = 0;
    int rp = n - 1;

    while (lp < rp)
    {
        int w = rp - lp;
        int h = min(height[lp], height[rp]);
        int currentWater = w * h;

        maxWater = max(maxWater, currentWater);

        height[lp] < height[rp] ? lp++ : rp--;
    }
    return maxWater;
}

int main()
{
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = containerWater(arr);

    cout << "Max Area is : " << result << endl;
    return 0;
}