#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;
    
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            if (!st.empty())
                nge[i] = st.top();
        }
        st.push(nums[i % n]);
    }
    return nge;
}

int main()
{

    vector<int> arr1 = {1, 2, 1};

    vector<int> ans = nextGreaterElements(arr1);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " , ";
    }

    return 0;
}