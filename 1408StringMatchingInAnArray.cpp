#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void precompute_lps(vector<string> &words, vector<vector<int>>&lps )
    {
        for(string word : words)
        {
            int m = word.size();
            vector<int> word_lps(m);
            int i=1,j=0;

            while(i<m)
            {
                if(word[i]==word[j])
                {
                    word_lps[i]=j+1;
                    i++;
                    j++;
                }
                else if(j>0)
                {
                    j = word_lps[j-1];
                }
                else
                {
                    i++;
                }
            }
            lps.push_back(word_lps);

        }

    }

    bool stringMatcher(string &pattern, vector<int> &pattern_lps, string &text)
    {
        int pattern_size = pattern.size();
        int text_size = text.size();
        int i =0; //  pattern pointer
        int j=0; // text pointer

        while(i<pattern_size and j<text_size)
        {
            if(pattern[i] ==  text[j])
            {
                i++;
                j++;
            }
            if(i==pattern_size)
            return true;

            if(j<text_size and pattern[i]!=text[j])
            {
                if(i>0)
                {
                    i = pattern_lps[i-1];
                }
                else
                {
                    j++;
                }
            }
        }
        return false;
    }

public:
    vector<string> stringMatching(vector<string> &words)
    {
        int n =  words.size();

        sort(words.begin(),words.end(),[](const string &a, const string &b)
        {
            return a.size()<b.size();
        });

        vector<vector<int>> lps;
        precompute_lps(words,lps);

        vector<string> res;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stringMatcher(words[i],lps[i],words[j]))
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;

    }
};

int main()
{
    vector<string> words = {"mass", "as", "hero", "superhero"};

    Solution sl;

    vector<string> result = sl.stringMatching(words);

    for(auto e: result)
    cout<<e<<" ";
}