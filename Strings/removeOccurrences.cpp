#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removeOccurrences(string s, string part)
{
    while (s.length() > 0 && s.find(part) < s.length()) // in last iteration s.find(part) becomes 18446744073709551615 which is > s.length()

    {
        cout << "Before : " << s.length() << endl;
        s.erase(s.find(part), part.length());
        cout << "After : " << s.length() << endl;
    }

    return s;
}

int main()
{
    string s1 = "daabcbaabcbc";
    string part = "abc";

    cout << removeOccurrences(s1, part) << endl;
    return 0;
}