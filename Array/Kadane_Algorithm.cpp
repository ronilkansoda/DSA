#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 5;
    int arr[] = {-1, 2, -3, 4, 5};

    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int val : arr)
    {
        currentSum += val;
        maxSum = max(currentSum, maxSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    // for (int st = 0; st < n; st++)
    // {
    //     int currentSum = 0;
    //     for (int end = st; end < n; end++)
    //     {
    //         // for (int i = st; i <= end; i++)
    //         // {
    //         //     cout << arr[i];
    //         // }
    //         // cout << " ";
    //         currentSum += arr[end];
    //         maxSum = max(currentSum, maxSum);
    //     }
    //     // cout << endl;
    // }

    cout << "Max Sum : " << maxSum << endl;

    return 0;
}