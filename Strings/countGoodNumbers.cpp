#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MOD = 1e9 + 7;
// best approach - TC = O(logn) and SC = O(1)
long modExp1(long base, long exp, long MOD)
{
    int ans = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return ans;
}

// Recursive approach - TC = O(logn) and SC = O(logn)
long modExp(long base, long exp, long MOD, long ans)
{

    if (exp % 2 == 1)
    {
        return modExp((base * base) % MOD, exp /= 2, MOD, (ans * base) % MOD);
    }
    if (exp == 0)
    {
        return ans;
    }

    return modExp((base * base) % MOD, exp /= 2, MOD, ans);
}

int countGoodNumbers(long long n)
{
    if (n == 1)
    {
        return 5;
    }
    long evenCount = (n + 1) / 2;
    long oddCount = n / 2;

    // // for best approach
    // long evenResult = modExp(5, evenCount, MOD);
    // long oddResult = modExp(4, oddCount, MOD);

    long evenResult = modExp(5, evenCount, MOD, 1);
    long oddResult = modExp(4, oddCount, MOD, 1);

    return (evenResult * oddResult) % MOD;
}

int main()
{
    long long n = 4;

    cout << countGoodNumbers(n) << endl;

    return 0;
}