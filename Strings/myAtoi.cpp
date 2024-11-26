#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

// Iterative approach - TC = O(n) and SC = O(1)
int myAtoi1(string s)
{
    int i = 0;
    int sign = 1;
    long ans = 0;

    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }
    if (i < s.length() && s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (i < s.length() && s[i] == '+')
    {
        i++;
    }

    while (i < s.length())
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i] - '0');
            if (ans > INT_MAX && sign == -1)
                return INT_MIN; // Return INT_MIN if overflow occurs on negative sign
            else if (ans > INT_MAX && sign == 1)
                return INT_MAX; // Return INT_MAX if overflow occurs on positive sign
            i++;
        }
        else
        {
            return ans * sign;
        }
    }

    return ans * sign;
}

// Recursive approach - TC = O(n) and SC = O(n)
int myAtoiRecursive(string &s, int i, long ans, int sign)
{
    // Base case: If we reach the end of the string or encounter a non-digit.
    if (i >= s.length() || !(s[i] >= '0' && s[i] <= '9'))
    {
        return ans * sign;
    }

    // Update the result with the current digit.
    ans = ans * 10 + (s[i] - '0');

    // Check for overflow.
    if (ans > INT_MAX && sign == -1)
        return INT_MIN;
    if (ans > INT_MAX && sign == 1)
        return INT_MAX;
    // Recursive call to process the next character.
    return myAtoiRecursive(s, i + 1, ans, sign);
}

int myAtoi(string s)
{
    int i = 0;
    int sign = 1;
    long ans = 0;

    // Skip leading whitespaces.
    while (i < s.length() && s[i] == ' ')
    {
        i++;
        cout << i << endl;
    }

    // Check for a sign.
    if (i < s.length() && s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (i < s.length() && s[i] == '+')
    {
        i++;
    }
    // Start the recursive conversion process.
    return myAtoiRecursive(s, i, ans, sign);
}

int main()
{
    string s1 = "   870-1";

    cout << myAtoi(s1) << endl;

    return 0;
}