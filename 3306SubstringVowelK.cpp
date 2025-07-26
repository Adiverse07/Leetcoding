#include <bits/stdc++.h>
using namespace std;

class Solution
{

    long long atleastk(int k, string word)
    {
        unordered_map<char, int> vowel;
        int non_vowel = 0;
        long long res = 0;

        int l = 0, r = 0;
        int n = word.size();

        for (int r = 0; r < n; r++)  
        {
            char chr = word[r];
            
            if (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u')
            {
                vowel[chr]++;
            }
            else
                non_vowel++;

            while (vowel.size() == 5 and non_vowel >= k)
            {
                res += (n - r);
                char chl = word[l];
                if (chl == 'a' || chl == 'e' || chl == 'i' || chl == 'o' || chl == 'u')
                {
                    vowel[chl]--;
                    if (vowel[chl]==0)
                    vowel.erase(chl);

                }
                else
                    non_vowel--;

                
                l++;
            }
          
        }
        return res;
    }

public:
    long long countOfSubstrings(string word, int k)
    {
        return atleastk(k, word) - atleastk(k + 1, word);
    }
};

int main()
{
    string word = "ieaouqqieaouqq";
    int k = 1;

    Solution sl;

    cout << sl.countOfSubstrings(word, k);
}