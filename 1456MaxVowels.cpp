#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        int pr = 1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                prefix[i + 1] = prefix[i] + 1;
            }
            else
            {
                prefix[i + 1] = prefix[i];
            }
        }

        int maxVowels = 0;
        for (int i = 0; i <= n - k; i++)
        {
            int vowelsInWindow = prefix[i + k] - prefix[i];

            maxVowels = max(maxVowels, vowelsInWindow);

            if (maxVowels == k)
                return k;
        }
        return maxVowels;
    }
};

int main()
{
    Solution sl;
    string s = "abciiidef";
    int k = 3;

    cout << sl.maxVowels(s, k);
}