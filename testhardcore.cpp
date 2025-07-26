#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int basen = baseStr.size();

        unordered_map<char,vector<char>> best;

         for (int i = 0; i < n; i++)
        {
            best[s1[i]].push_back(s1[i]);
            best[s2[i]].push_back(s2[i]);
        }

         for (int i = 0; i < n; i++)
        {
            best[s1[i]].push_back(s2[i]);
            best[s2[i]].push_back(s1[i]);
        }

       
    }
};
int main()
{
    string s1 = "leetcode";
    string s2 = "programs";
    string baseStr = "sourcecode";

    Solution sl;

    cout << sl.smallestEquivalentString(s1, s2, baseStr);
}
