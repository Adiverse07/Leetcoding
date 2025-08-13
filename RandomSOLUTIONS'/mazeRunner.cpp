#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

class Solution {
public:
    int collectKeys(vector<vector<char>> &grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();

        int total_keys = 0;
        vector<vector<int>> keyIndex(n, vector<int>(m, -1));
        int start_x = -1, start_y = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                } else if (grid[i][j] == 'K') {
                    keyIndex[i][j] = total_keys;
                    total_keys++;
                }
            }
        }

        if (start_x == -1) 
            return -1;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int total_masks = 1 << total_keys;
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(total_masks, false)));

        queue<tuple<int, int, int, int>> q;
        q.push(make_tuple(start_x, start_y, 0, 0));
        visited[start_x][start_y][0] = true;

        while (!q.empty()) {
            tuple<int, int, int, int> t = q.front();
            q.pop();
            int x = get<0>(t);
            int y = get<1>(t);
            int mask = get<2>(t);
            int steps = get<3>(t);

            if (grid[x][y] == 'E' && mask == total_masks - 1) {
                return steps;
            }

            for (auto &dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                    continue;

                if (grid[nx][ny] == '#' || grid[nx][ny] == 'T') 
                    continue;

                int new_mask = mask;
                if (grid[nx][ny] == 'K') {
                    int idx = keyIndex[nx][ny];
                    new_mask = mask | (1 << idx);
                }

                if (!visited[nx][ny][new_mask]) {
                    visited[nx][ny][new_mask] = true;
                    q.push(make_tuple(nx, ny, new_mask, steps + 1));
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<char>> grid = {{'S', '.', '.', '#', '.', 'K'},
                                {'.', '#', '.', '.', '.', '.'},
                                {'.', '#', 'T', '#', '.', '.'},
                                {'K', '.', '.', '.', '.', 'E'}};

    Solution sl;
    cout << sl.collectKeys(grid);
}