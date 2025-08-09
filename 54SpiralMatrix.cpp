#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;

        int dir = 0;
        int left = 0;
        int right = n - 1;
        int top = 0;
        int down = m - 1;
        /*
        dir = 0 = left to right
        dir = 1 = top to down
        dir = 2 = right to left
        dir = 3 = up to down
        */

        while (top<=down && left<=right)
        {

            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }

            if (dir == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }

            if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[down][i]);
                }
                down--;
            }

            if (dir == 3)
            {
                for (int i = down; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                    
                }
                left++;
            }

            dir++;

            if (dir == 4)
                dir = 0;
        }

        return res;
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> res = sl.spiralOrder(matrix);

    for (int i : res)
        cout << i << " ";
}