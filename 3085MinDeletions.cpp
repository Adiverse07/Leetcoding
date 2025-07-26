#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        int n = word.length();
        vector<int> freq(26,0);

        for (int i = 0; i < n; i++)
        {
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(), freq.end());

        int result = n;
        int cumilative_deleted = 0;
        for (int i = 0; i < 26; i++)
        {
            int del = cumilative_deleted;
            for (int j = 25; j > i; j--)
            {
                if(freq[j]-freq[i] <= k)
                break;

                del += freq[j] - freq[i] - k;

            }

            result = min(result ,del);
            cumilative_deleted += freq[i];
        }

        return result;
    }
};

int main()
{
    string word = "aabcaba";
    int k = 0;

    Solution sl;

    cout << sl.minimumDeletions(word, k);
}