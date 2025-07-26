#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {

        int n = s.size();
        int onecount=0;
        int zerocount = 0;
        int maxcount = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                onecount++;
        }

        for (int i = 0; i < n-1; i++)
        {
            if (s[i] == '0')
                zerocount++;
            else onecount--;

            maxcount = max(maxcount,zerocount+onecount);
        }

        return maxcount;
    }
};

int main()
{
    string s = "011101";
    Solution sl;

    cout << sl.maxScore(s);
}