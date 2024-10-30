#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int pivot = -1, n = nums.size();

    // finding pivot
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        };
    }

    // for decreasing order [3,2,1] so we reverse it to [1,2,3]
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // as it will take [1,2,5,4,3] and swap 3 and 2 as it accepts the if condition as 3 > 2
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // arr = [1,3,5,4,2] now i will be arr[i] = 5 and j will be arr[j] = 2
    int i = pivot + 1, j = n - 1;

    // we will reverse from 5 to 2 and at last it will became arr [1,3,2,4,5]
    while (i <= j)
    {
        swap(nums[i++], nums[j--]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};

    nextPermutation(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}