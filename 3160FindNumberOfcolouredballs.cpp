#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {

        unordered_map<int, int> colored;
        unordered_map<int, int> freq;
        vector<int> count;
        int n = queries.size();

       for(auto q : queries)
       {
        int idx =  q[0]; 
        int newColor = q[1];

        if(colored.find(idx)!=colored.end())
        {
            int oldcolor = colored[idx];
            freq[oldcolor]--;

            if(freq[oldcolor]==0)
            {
                freq.erase(oldcolor);
            }
        }

        colored[idx]  = newColor;
        freq[newColor]++;

        count.push_back(freq.size());
       }

       return count;
       
    }
};
int main()
{
    int limit = 4;
    vector<vector<int>> queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};

    Solution sl;

    vector<int> res = sl.queryResults(limit, queries);

    for (auto i : res)
        cout << i << " ";
}



//OGiest Solution
/*
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ball, color;
        vector<int> ans;
        ans.reserve(queries.size());
        int distinct = 0;
        for(auto &q : queries) {
            int pos = q[0], c = q[1];
            if(ball.count(pos))
                if(--color[ball[pos]] == 0) distinct--;
            ball[pos] = c;
            if(++color[c] == 1) distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};
*/