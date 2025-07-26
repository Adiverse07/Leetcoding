#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
    }
};

int main()
{
    vector<string> words = {"bab","dab","cab"};
    vector<int> groups = {1,2,2};
    Solution sl;

    vector<string> res = sl.getWordsInLongestSubsequence(words,groups);

    for(auto i: res)
    cout<<i<<" ";
}