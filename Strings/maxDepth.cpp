#include <iostream>
#include <string>
using namespace std;

int maxDepth(string s)
{
    int curr = 0, maxi = INT_MIN;

    for (auto c : s)
    {
        if (c == '(')
        {
            curr++;
        }
        else if (c == ')')
        {
            maxi = max(curr, maxi);
            curr--;
        }
    }

    return maxi;
}

int main()
{
    string s1 = "(1+(2*3)+((8)/4))+1";

    cout << maxDepth(s1) << endl;

    return 0;
}