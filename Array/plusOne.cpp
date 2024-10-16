#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> plusOne1(vector<int> &digits)
{
    int n = digits.size();
    int s = n - 1;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += digits[i] * pow(10, s);
        s--;
    }

    total += 1;

    vector<int> result;
    while (total > 0)
    {
        result.insert(result.begin(), total % 10);
        total /= 10;
    }

    return result;
}
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n-1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }

    vector<int> res(n + 1, 0); //it creates new vector and initialized to 0

    res[0] = 1;
    return res;
}

int main()
{
    vector<int> arr = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 2};

    vector<int> result = plusOne(arr);
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d", result[i]);
    }

    return 0;
}