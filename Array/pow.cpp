#include <iostream>
using namespace std;

double myPow1(double x, int n)
{
    if (n == 0)
        return 1.0;
    if (x == 0)
        return 0.0;
    if (x == 1)
        return 1.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;

    long binForm = n;
    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm;
    }

    double ans = 1;

    while (binForm > 0)
    {
        if (binForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        // cout << "Before : " << binForm << endl;
        binForm /= 2;
        // cout << "After : " << binForm << endl;
    }
    return ans;
}

double myPowRecursion(long binForm, double ans, double x)
{
    if (binForm % 2 == 1)
    {
        return myPowRecursion(binForm / 2, ans * x, x * x);
    }
    if (binForm == 0)
    {
        return ans;
    }
    return myPowRecursion(binForm /= 2, ans, x *= x);
}

double myPow(double x, int n)
{
    if (n == 0)
        return 1.0;
    if (x == 0)
        return 0.0;
    if (x == 1)
        return 1.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;

    long binForm = n;
    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm;
    }

    double ans = 1;
    return myPowRecursion(binForm, ans, x);
}

int main()
{
    double x = 2.000;
    int n = 10;

    double result = myPow(x, n);

    cout << "Power of " << x << "^" << n << ": " << result << endl;
    return 0;
}