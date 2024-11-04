#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// bool isPalindrome(string s, int i, int j)
// {
//     while (i < j)
//     {
//         if (s[i] != s[j])
//             return false;
//         i++;
//         j--;
//     }
//     return true;
// }

// string longestPalindrome(string s)
// {

//     int maxLen = 0, start = 0;
//     int n = s.length();

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (isPalindrome(s, i, j))
//             {
//                 int currentLen = j - i + 1;
//                 if (currentLen > maxLen)
//                 {
//                     maxLen = currentLen;
//                     start = i;
//                 }
//             }
//         }
//     }
//     return s.substr(start, maxLen);
// }

string longestPalindrome(string s)
{
    int n = s.length();
    if (n < 2)
        return s;

    int start = 0, maxLen = 1;

    auto expandAroundCenter = [&](int left, int right)
    {
        while (left >= 0 && right < n && s[left] == s[right])
        {
            int len = right - left + 1;
            if (len > maxLen)
            {
                maxLen = len;
                start = left;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < n - 1; i++)
    {
        expandAroundCenter(i, i);     // Odd length palindrome
        expandAroundCenter(i, i + 1); // Even length palindrome
    }

    return s.substr(start, maxLen);
}
int main()
{
    string s1 = "babad";
    cout << longestPalindrome(s1) << endl;
    return 0;
}