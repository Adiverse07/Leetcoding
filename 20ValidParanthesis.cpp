#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();

        stack<char> st;
        unordered_map<char, char> brackets = {{')', '('}, {']', '['}, {'}', '{'}};
        for (int i = 0; i < n; i++)
        {

            if (s[i] == '}' or s[i] == ')' or s[i] == ']')
            {
                if (st.empty() or st.top() != brackets[s[i]])
                    return false;
               
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};

int main()
{
    string s = "([)]";
    Solution sl;

    if (sl.isValid(s))
        cout << "True";
    else
        cout << "False";
}