#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        stack<char> st;
        int n = pattern.size();
        string res = "";

        for (int i = 1; i <= n + 1; i++)
        {
            st.push(i);

            char c = pattern[i - 1]; // because i starts from orignal pos + 1

            if (i == n + 1 || c == 'I')
            {
                while (!st.empty())
                {
                    res.push_back('0' + st.top());
                    st.pop();
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sl;
    string pattern = "IIIDIDDD";

    cout << sl.smallestNumber(pattern);


}