#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

       

        int count = 0;

        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int patternL = words[i].size();
                int stringL = words[j].size();

                if(patternL > stringL) continue;

                if(words[j].find(words[i])==0)
                {
                    if(words[j].compare(stringL - patternL, patternL, words[i])==0)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
        

    }
};

int main()
{
    vector<string> words = {"a","aba","ababa","aa"};
    Solution  sl;

    cout<<sl.countPrefixSuffixPairs(words);
}