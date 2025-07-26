#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        vector<int> chars(26);
        int n = s.size();
        int oddcount = 0;

        if (s.size() < k)
            return false;

        for (char c : s)
            chars[c - 'a']++;

        for (auto countc : chars)
        {
            if (countc % 2 != 0)
            {
                oddcount++;
            }
        }

        if (oddcount > k)
            return false;
        else
            return true;
    }
};

int main()
{
    string s = "annabelle";
    int k = 2;

    Solution sl;

    if (sl.canConstruct(s, k))
        cout << "Ha bsdk";
    else
        cout << "Na bsdk";
}
