#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {

        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> lookup(m * n + 1);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                lookup[mat[i][j]] = make_pair(i, j);

        
        vector<int> rows(m,0);
        vector<int> cols(n,0);

        for(int i = 0;i<m*n;i++)
        {
            pair<int,int> coordinates = lookup[arr[i]];
            int x = coordinates.first;
            int y = coordinates.second;

            rows[x]++;
            cols[y]++;

            if(rows[x]==m or cols[y]==n)
            {
                return i;
            }
        }

        return 0;
    }
};

int main()
{
    Solution sl;
    vector<int> arr = {1, 3, 4, 2};

    vector<vector<int>> mat = {{1, 4}, {2, 3}};

    cout << sl.firstCompleteIndex(arr, mat);
}