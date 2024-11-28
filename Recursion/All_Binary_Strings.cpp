#include <bits/stdc++.h>
using namespace std;

void All_Binary_Strings(bool arr[], int num, int r)
{
    // aa condition khali em check karse k r=1=num thai as r=1 etle che km k arr[0] = 0 or 1 aapde define kar didhu che print function ma. so 0__... aavu hase to if r==nums thase to eni jetli size kidhi che e match thai e print kar dese.
    if (r == num)
    {
        for (int i = 0; i < num; i++)
            cout << arr[i];
        cout << " ";
        return;
    }
    // aa niche ni condition if previous 1 hase to km k aapde 1 1 sathe na joiye
    else if (arr[r - 1])
    {
        arr[r] = 0;
        All_Binary_Strings(arr, num, r + 1);
    }
    // aa niche ni condition if previous 0 hase to
    else
    {
        // 0 and 1 km k if 0__... hoviyu to right side 0 and 1 kai be aai sake so we need to find all the possibilites
        arr[r] = 0;
        All_Binary_Strings(arr, num, r + 1);
        arr[r] = 1;
        All_Binary_Strings(arr, num, r + 1);
    }
}

void print(bool a[], int &num)
{
    // 0 and 1 km k if 0__... hoviyu to right side 0 and 1 kai be aai sake so we need to find all the possibilites
    a[0] = 0;
    All_Binary_Strings(a, num, 1);
    a[0] = 1;
    All_Binary_Strings(a, num, 1);
}

// driver's code
int main()
{
    int n = 1;
    bool a[n];
    print(a, n);
    return 0;
}