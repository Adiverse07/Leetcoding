#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<bool> safeNodes;

    bool isSafeState(vector<vector<int>> &graph, vector<int> &visited, int curr)
    {
        visited[curr] = 1;
        bool is_safe = true;

        for (int nbr : graph[curr])
        {
            if (visited[nbr] == 0) // unvisited
                is_safe &= isSafeState(graph, visited, nbr);

            else if (visited[nbr] == 1) //cycle
                return safeNodes[curr] = false;

            else if(visited[nbr] == 2) //processed
               is_safe &= safeNodes[nbr];
        }

        visited[curr] = 2; //mark processed
        return safeNodes[curr] = is_safe;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();
        safeNodes = vector<bool>(n, true);

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                isSafeState(graph,visited,i);
            }
        }
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            if (safeNodes[i] == true)
                res.push_back(i);
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Solution sl;
    vector<int> res = sl.eventualSafeNodes(graph);

    for (auto i : res)
        cout << i <<" ";
}