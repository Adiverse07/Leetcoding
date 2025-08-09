#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        
        //diagonal elements will stay at place, we just need to swap  those corresponing in row  and col
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i == j)
                    continue;

                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
int main()
{
    Solution sl;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    sl.rotate(matrix);
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}