#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int MOD = 1e9 + 7;

    inline int modAdd(int a, int b)
    {
        return ((a % MOD) + (b % MOD)) % MOD;
    }

public:
    int lengthAfterTransformations(string s, int t)
    {

        int n = s.size();
        array<int,26> alpha{};

        for (int i = 0; i < n; i++)
        {
            alpha[s[i] - 'a']++;
        }

        while (t--)
        {
            array<int,26> next_freq;
            for (int i = 0; i < 26; i++)
            {
                if (i < 25)
                {
                    next_freq[i + 1] = alpha[i];
                }
                else
                {
                    next_freq[0] = alpha[25];
                    next_freq[1] =  modAdd(next_freq[1], alpha[25]);
                }
            }
             alpha = next_freq;
        }

        int stringSize = 0;
        for(int i =0;i<26;i++)
        {
            stringSize = modAdd(stringSize, alpha[i]);
        }


        return stringSize;
    }
};

int main()
{
    Solution sl;
    string s = "abcyy";
    int t = 2;

    cout << sl.lengthAfterTransformations(s, t);

  
}