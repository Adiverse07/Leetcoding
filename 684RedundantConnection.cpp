#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int ufind(vector<int> &dsuf, int v)
    {
        if (dsuf[v] == -1)
            return v;

        return dsuf[v] = ufind(dsuf, dsuf[v]);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        vector<int> dsuf(n + 1, -1);

        for(auto edge: edges)
        {
            int parent_x = ufind(dsuf,edge[0]);
            int parent_y = ufind(dsuf,edge[1]);

            if(parent_x == parent_y)
            return edge;
            else
            dsuf[parent_x] = parent_y;
        }

        return {0,0};
    }
};

int main()
{
    Solution sl;

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};

    vector<int> res = sl.findRedundantConnection(edges);

    for (auto i : res)
    {
        cout << i << " ";
    }
}