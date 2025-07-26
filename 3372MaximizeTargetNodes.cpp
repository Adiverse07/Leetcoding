#include <bits/stdc++.h>
using namespace std;
class Solution
{

    int bfs(int curr, unordered_map<int, vector<int>> &adj, int d, int n)
    {
        queue<pair<int, int>> q;
        q.push({curr, 0});

        vector<bool> visited(n, false);
        visited[curr] = true;

        int count = 0;

        while (!q.empty())
        {
            int currNode = q.front().first;

            int dist = q.front().second;

            q.pop();

            if (dist > d)
                continue;

            count++;

            for (auto &ngbr : adj[currNode])
            {
                if (!visited[ngbr])
                {
                    visited[ngbr] = true;
                    q.push({ngbr, dist + 1});
                }
            }
        }
        return count;
    }

    int dfs(int curr, unordered_map<int,vector<int>> adj,int d, int currNodeParent)
    {
        if(d<0)
        return 0;

        int count = 1;
        for(auto &ngbr : adj[curr])
        {
            if(ngbr != currNodeParent)
            {
                count+= dfs(ngbr, adj, d-1, curr);
            }

            
        }

        return count;

    }
    vector<int> findCount(vector<vector<int>> &edges, int k)
    {
        int n = edges.size()+1;
        unordered_map<int, vector<int>> adj;

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            // result[i] = bfs(i, adj, k, n);
            result[i] = dfs(i,adj,k,-1);
        }

        return result;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {

        int nodes1 = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k);

        vector<int> result2 = findCount(edges2, k - 1);

        int maxTarget = *max_element(begin(result2), end(result2));

        for (int i = 0; i < result1.size(); i++)
        {
            result1[i] += maxTarget;
        }

        return result1;
    }
};

int main()
{
       vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k =2;

    Solution sl;

    vector<int> res = sl.maxTargetNodes(edges1,edges2,k);

    for(auto i:res)
    cout<<i<<" ";
}