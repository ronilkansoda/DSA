#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// Brute Force O(n^2)
//  vector<int> getSecondOrderElements(int n, vector<int> a)
//  {
//      bool isSwap;

//     for (int i = 0; i < n; i++)
//     {
//         isSwap = false;
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (a[j] > a[j + 1])
//             {
//                 swap(a[j], a[j + 1]);
//                 isSwap = true;
//             }
//         }

//         if (!isSwap)
//         {
//             cout << "The array is already sorted." << endl;
//             break;
//         }
//     }

//     if (n < 2)
//     {
//         cout << "Array does not have enough elements." << endl;
//         return {-1, -1};
//     }

//     return {a[n - 2], a[1]};
// }

// optimize approach O(n)
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    int largest = INT_MIN, secLargest = INT_MIN;
    int smallest = INT_MAX, secSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        largest = max(largest, a[i]);
        smallest = min(smallest, a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < secSmallest && a[i] != smallest)
        {
            secSmallest = a[i];
        }
        if (a[i] > secLargest && a[i] != largest)
        {
            secLargest = a[i];
        }
    }

    return {secLargest, secSmallest};
}

int main()
{
    vector<int> arr = {3, 7, 2, 1, 6, 5, 4};
    int n = arr.size();

    vector<int> res = getSecondOrderElements(n, arr);

    cout << res[0] << " " << res[1];

    return 0;
}