#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isAnagram(string s, string t)
{
    int count[26] = {0};

    // Count the frequency of characters in string s
    for (char x : s)
    {
        count[x - 'a']++;
    }

    // Decrement the frequency of characters in string t
    for (char x : t)
    {
        count[x - 'a']--;
    }

    // Check if any character has non-zero frequency
    for (int val : count)
    {
        if (val != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s1 = "rat";
    string s2 = "gat";

    cout << isAnagram(s1,s2) << endl;

    return 0;
}