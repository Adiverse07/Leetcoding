#include <bits/stdc++.h>
using namespace std;

class Solution
{

#define pii pair<int, int>
#define pip pair<int, pii>

    bool isValid(int &x, int &y, int &m, int &n)
    {
        return (x >= 0 and x < m and y >= 0 and y < n);
    }

public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        set<int> sorted_quereis(queries.begin(), queries.end());

        unordered_map<int, int> query_count;
        priority_queue<pip, vector<pip>, greater<pip>> minheap;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // BFS
        minheap.push(make_pair(grid[0][0], make_pair(0, 0)));
        visited[0][0] = true;
        vector<int> dir = {-1, 0, 1, 0, -1};
        int count = 0;

        for (auto query : sorted_quereis)
        {
            while (!minheap.empty())
            {
                pip curr = minheap.top();
                minheap.pop();

                int val = curr.first;
                int x = curr.second.first;
                int y = curr.second.second;

                if (val >= query)
                {
                    minheap.push(curr);
                    break;
                }

                count++;

                for (int i = 0; i < 4; i++)
                {
                    int newX = x + dir[i];
                    int newY = y + dir[i + 1];

                    if (isValid(newX, newY, m, n) and !visited[newX][newY])
                    {
                        visited[newX][newY] = true;
                        minheap.push(make_pair(grid[newX][newY], make_pair(newX, newY)));
                    }
                }
            }
            query_count[query] = count;
        }
        // building the answer
        vector<int> answer;
        for (auto query : queries)
        {
            answer.push_back(query_count[query]);
        }

        return answer;
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> grid = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries = {5, 6, 2};

    vector<int> res = sl.maxPoints(grid, queries);

    for (auto i : res)
        cout << i << " ";
}