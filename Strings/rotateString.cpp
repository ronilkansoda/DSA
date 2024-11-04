#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool rotateString(string s, string goal)
{
    string ans;
    if (s.length() != goal.length())
    {
        return false;
    }

    // for (int i = 1; i < goal.length(); i++)
    // {
    //     if (goal[i] == s[0])
    //     {
    //         ans = goal.substr(i) + goal.substr(0, i);
    //         break;
    //     }
    // }
    // if (s == ans)
    // {
    //     return true;
    // }

    // return false;

    string doubleS = s + s;
    cout << doubleS << endl;

    return doubleS.find(goal) != string::npos; // if it finds goal than it returns true other wise false 
}

int main()
{
    string s1 = "abcde";
    string goal = "abcde";

    cout << rotateString(s1, goal) << endl;

    return 0;
}