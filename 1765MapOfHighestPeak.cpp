#include <bits/stdc++.h>
using namespace std;

class Solution
{

#define pii pair<int, int>

    bool isValid(int &x, int &y, int &m, int &n)
    {
        return (x >= 0 and x < m and y >= 0 and y < n);
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pii> q;

        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }

        //BFS

        vector<int> dir = {-1, 0, 1, 0, -1};
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int j = 0; j < size; j++)
            {

                pii curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;
                for (int i = 0; i < 4; ++i)
                {
                    int newX = curr.first + dir[i];
                    int newY = curr.second + dir[i + 1];

                    if (isValid(newX, newY, m, n) && !visited[newX][newY])
                    {
                        q.push(make_pair(newX, newY));
                        grid[newX][newY] = level + 1;
                        visited[newX][newY] = true;
                    }
                }
            }
            level++;
        }

        return grid;
    }
};

int main()
{
    vector<vector<int>> isWater = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    Solution sl;

    vector<vector<int>> result = sl.highestPeak(isWater);
    int n = result.size();
    int m = result[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j] << ",";
        }
        cout << endl;
    }
}