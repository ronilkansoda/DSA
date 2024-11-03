#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int total = 0;
    int length = s.size();

    for (int i = 0; i < length; i++)
    {

        if (i < length - 1 && romanMap[s[i]] < romanMap[s[i + 1]])
        {

            total -= romanMap[s[i]];
        }
        else
        {

            total += romanMap[s[i]];
        }
    }

    return total;
}

int main()
{
    string s1 = "MCMXCIV";

    cout << romanToInt(s1) << endl;

    return 0;
}