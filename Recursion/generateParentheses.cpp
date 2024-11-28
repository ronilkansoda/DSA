#include <bits/stdc++.h>
using namespace std;

//                                   " "
//                                    (
//                         /--------  |  --------\
//                        ((                     ()
//                      /      \                   \
//                    (((       (()                ()(
//                  /         /     \            /     \
//                ((()))   (()())   (())()     ()()()   ()(())


// TC = O(2^n) and SC = O(n)
void genPar(int open, int close, string current, vector<string> &result, int n)
{
    if (current.length() == 2 * n)
    {
        result.push_back(current);
        return;
    }
    if (open < n)
    {
        genPar(open + 1, close, current + "(", result, n);
    }
    if (close < open)
    {
        genPar(open, close + 1, current + ")", result, n);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    genPar(0, 0, "", result, n);
    return result;
}

int main()
{
    vector<string> ans = generateParenthesis(3);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }

    return 0;
}