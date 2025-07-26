#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        unordered_map<char, int> lastindex;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            lastindex[s[i]] = i;
        }

        int size = 0;
        int end = 0;

        for (int i = 0; i < n; i++)
        {

            if (lastindex[s[i]] > end)
                end = lastindex[s[i]];
            size++;
            if (i == end)
            {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};

int main()
{
    Solution sl;
    ;
    string s = "ababcbacadefegdehijhklij";

    vector<int> res = sl.partitionLabels(s);

    for (auto i : res)
        cout << i << " ";
}