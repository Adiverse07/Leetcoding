#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {

        int n = words.size();
        vector<int> prefix_sum(n, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            int wsize = words[i].size();
            if (vowels.count(words[i][0]) && vowels.count(words[i][wsize - 1]))
            {
                if (i == 0)
                {
                    prefix_sum[i] = 1;
                }
                else
                {
                    prefix_sum[i] = prefix_sum[i - 1] + 1;
                }
            }
            else
            {
                if(i==0)
                continue;
                else
                prefix_sum[i] = prefix_sum[i - 1];
                
            }
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            if (l == 0)
            {
                res.push_back(prefix_sum[r]);
                continue;
            }
            else
            {
                int ans = prefix_sum[r] - prefix_sum[l - 1];
                res.push_back(ans);
            }
        }
        return res;
    }
};

int main()
{
    Solution sl;
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};

    vector<int> result = sl.vowelStrings(words, queries);

    for (auto e : result)
        cout << e << " ";
}

//Syntactically Optimized
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> prefix_sum(n, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            prefix_sum[i] = (i > 0 ? prefix_sum[i - 1] : 0) + 
                            (vowels.count(words[i][0]) && vowels.count(words[i].back()));
        }

        for (const auto &q : queries)
        {
            int l = q[0], r = q[1];
            res.push_back(prefix_sum[r] - (l > 0 ? prefix_sum[l - 1] : 0));
        }
        return res;
    }
};

int main()
{
    Solution sl;
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};

    vector<int> result = sl.vowelStrings(words, queries);

    for (auto e : result)
        cout << e << " ";
}

*/