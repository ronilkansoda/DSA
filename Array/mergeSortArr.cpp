#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

void mergeSortArr(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[idx--] = nums1[i--];
        }
        else
        {
            nums1[idx--] = nums2[j--];
        }
    }

    while (j >= 0)
    {
        nums1[idx--] = nums2[j--];
    }
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};
    int m = 3, n = 3;

    mergeSortArr(arr1, m, arr2, n);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }

    return 0;
}