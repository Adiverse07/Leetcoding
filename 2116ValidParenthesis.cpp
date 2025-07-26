#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {

        int n = s.size();

        if (n % 2 != 0)
            return false;

        int wc = 0;
        int oc = 0;
        int cc = 0;
        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0')
                wc++;

            else if (s[i] == '(')
                oc++;

            else
                cc++;

            if (wc < (cc - oc)) // (())
                return false;
        }

        wc = oc = cc = 0;

        for (int i = n - 1; i > 0; i--)
        {
            if (locked[i] == '0')
                wc++;

            else if (s[i] == '(')
                oc++;

            else
                cc++;

            if (wc < (oc - cc))
                return false;
        }

        return true;
    }
};

int main()
{
    string s = "))()))";
    string locked = "010100";

    Solution sl;

    if (sl.canBeValid(s, locked))
        cout << "YOHO";
    else
        cout << "bkl";
}