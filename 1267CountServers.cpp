#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCount(m,0);
        vector<int> colcount(n,0);
        int totalServers =0;

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j])
                {
                    rowCount[i]++;
                    colcount[j]++;
                    totalServers++;
                }
            }
        }

        
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] and (rowCount[i] == 1 and colcount[j]==1))
                {
                   totalServers--;
                }
            }
        }
        return totalServers;

    }
};

int main()
{
    vector<vector<int>> grid = {{1,0},{0,1}};
    Solution sl;

    cout<<sl.countServers(grid);
}