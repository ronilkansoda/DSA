#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int myAtoi(string s)
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

int main()
{
    string s1 = "0-1";

    cout << myAtoi(s1) << endl;

    return 0;
}