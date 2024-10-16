#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;

void reverseArray(int arr[], int sz)
{
    int start = 0, end = sz - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    // int a[] = {4, 6, 23, 66, 332, 7, 32};
    // int sz = 7;

    // reverseArray(a, sz);

    // for (int i = 0; i < sz; i++)
    // {
    //     printf("%d ", a[i]);
    // }

    vector<char> vec = {'a', 'b', 'c'};

    vec.push_back('d');

    // cout << vec.size() << endl;
    cout << "front value = " << vec.front() << endl;
    cout << "back value = " << vec.back() << endl;
    cout << "Value at 2 = " << vec.at(2) << endl;

    for (char val : vec)
    {
        cout << val << endl;
    }
    
    return 0;
}