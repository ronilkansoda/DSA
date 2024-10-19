#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int st = 1, end = arr.size() - 2;

    while (st <= end)
    {
        int mid = st + (end - st) / 2; // at if st and end is INT_MAX then it will overflow
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid - 1] < arr[mid]) // right
        {
            st = mid + 1;
        }
        else // left
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {0, 2, 3, 1, 0};

    int result = peakIndexInMountainArray(nums);

    cout << result << endl;

    return 0;
}