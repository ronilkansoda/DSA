#include <iostream>
#include <vector>
using namespace std;

int largestElement(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = max(maxi, arr[i]);
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {5, 9, 3, 4, 8, 4, 3, 10};
    int n = arr.size();

    int result = largestElement(arr, n);

    cout << "Max Number : " << result << endl;
    return 0;
}