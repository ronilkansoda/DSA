#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// By iteration, time complexity => O(logn) and space complexity =O(1) (more optimize)
int binarySearch(vector<int> arr, int target)
{
    int n = arr.size();
    int st = 0, end = n - 1;

    while (st <= end)
    {
        // int mid = (st + end) / 2;
        int mid = st + (end - st) / 2; // at if st and end is INT_MAX then it will overflow

        if (target > arr[mid])
        {
            st = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

// By Recursion, time complexity => O(logn) and space complexity =O(logn)
int recursiveBinarySearch(vector<int> arr, int target, int st, int end)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (target > arr[mid])
        {
            return recursiveBinarySearch(arr, target, mid + 1, end);
        }
        else if (target < arr[mid])
        {
            return recursiveBinarySearch(arr, target, st, mid - 1);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int target1 = 12;
    int end = arr1.size();

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 0;

    int r1 = recursiveBinarySearch(arr1, target1, arr1[0], arr1[end - 1]);

    int result = binarySearch(arr1, target1);

    cout << result << endl;
    cout << r1 << endl;

    return 0;
}