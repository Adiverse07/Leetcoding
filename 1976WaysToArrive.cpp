#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int nk, vector<vector<int>> &roads)
    {
        int n = roads.size();
        vector<vector<pair<int, int>>> adj(nk);

        for (int i = 0; i < n; i++)
        {
            adj[roads[i][0]].push_back({roads[i][2], roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2], roads[i][0]});
        }

        long long MOD = 1e9 + 7;
        priority_queue<pair<long long , int>, vector<pair<long long , int>>, greater<pair<long long, int>>> minHeap;
        minHeap.push(make_pair(0, 0));
        vector<long long> min_cost(nk, LLONG_MAX);
        vector<int> path_count(nk, 0);
        path_count[0] = 1;

        while (!minHeap.empty())
        {
            long long cost = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            for (auto &[nei_cost, nei] : adj[node])
            {
                if ((cost + nei_cost) < min_cost[nei])
                {
                    min_cost[nei] = cost + nei_cost;
                    path_count[nei] = path_count[node];
                    minHeap.push({cost + nei_cost, nei});
                }
                else if ((cost + nei_cost) == min_cost[nei])
                {
                    path_count[nei] = (path_count[nei]  + path_count[node]) % MOD;
                }
            }
        }

        return path_count[nk - 1];
    }
};

int main()
{
    Solution sl;
    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    cout << sl.countPaths(n, roads);
}