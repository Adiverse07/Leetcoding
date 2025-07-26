#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int n = words.size();
        int res = 0;
        unordered_map<string, int> freq;
        bool hasCentral = false;

        for (int i = 0; i < n; i++)
        {

            string rev = "";
            rev += words[i][1];
            rev += words[i][0];

            if (freq[rev] > 0)
            {
                res += 4;
                freq[rev]--;
            }
            else
            {
                freq[words[i]]++;
            }
        }

        for (auto &it : freq)
        {
            string word = it.first;
            int count = it.second;

            if (word[0] == word[1] && count>0)
            {
                res += 2;
                break;
            }
        }

        return res;
    }
    };

    int main()
    {
        Solution sl;

        vector<string> words = {"lc", "cl", "gg"};

        cout << sl.longestPalindrome(words);
    }