#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

void BubbleSort(vector<int> &arr, int n) // O(n^2)
{
    bool isSwap;

    for (int i = 0; i < n; i++)
    {
        isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
    }

    if (!isSwap) // Array is already Sorted
        cout << "sorted array" << endl;
    return;
}

void SelectionSort(vector<int> &arr, int n) // O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIndex = i; // unsorted Part

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
}

void insertSort(vector<int> &arr, int n) // O(n^2)
{
    for (int i = 0; i < n; i++)
    {
        int currt = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > currt)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = currt; // Placing the currt el in its correct position
    }
}

void PrintArr(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {3, 7, 2, 1, 6, 5, 4};
    // vector<int> arr = {1, 2, 3, 4};
    int n = 7;

    // BubbleSort(arr, n);
    // SelectionSort(arr, n);
    insertSort(arr, n);
    PrintArr(arr, n);

    return 0;
}