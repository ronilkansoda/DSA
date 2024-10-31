#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string largestOddNumber(string num)
{
    for (int i = num.length() - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 != 0)
        {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main()
{
    string s1 = "3572";

    cout << largestOddNumber(s1) << endl;

    return 0;
}