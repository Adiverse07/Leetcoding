#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector <string> res;
        if(n==1) return words;
        
        res.push_back(words[0]);
        for(int i = 1;i<n;i++)
        {
            if(groups[i]==groups[i-1])
            {
                continue;
            }
            else
            {
                res.push_back(words[i]);
            }

        }

        return res;

       
    }
};

int main()
{
    vector<string> words = {"a","b","c","d"};
    vector<int> groups = {1,0,1,1};

    Solution sl;

    vector<string> res = sl.getLongestSubsequence(words,groups);

    for(auto e: res)
        cout<<e<<" ";


}