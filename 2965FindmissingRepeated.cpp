#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int a, n = grid.size();
        vector<int> num_freq(n * n + 1, 0);
        for (vector<int> row : grid)
        {
            for (int num : row)
            {
                if (num_freq[num] == 1)
                    a = num;
                num_freq[num]++;
            }
        }
        for (int num = 1; num <= n * n; num++)
            if (num_freq[num] == 0)
                return {a, num};
        return {-1, -1};
    }

    // vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    // {
    //     int n = grid.size();
    //     vector<int> numbers(2);
    //     int missing;
    //     int duplicate;

    //     unordered_set<int> nums;

    //     for(int i = 0;i<n;i++)
    //     {
    //         for(int j = 0;j<n;j++)
    //         {
    //             if(nums.count(grid[i][j])==1)
    //             duplicate =  grid[i][j];

    //             nums.insert(grid[i][j]);
    //         }
    //     }

    //     for(int i = 1;i<=n*n;i++)
    //     {
    //         if(nums.count(i)==0) missing = i;
    //     }

    //     numbers[0] = duplicate;
    //     numbers[1] = missing;

    //     return numbers;
    // }
};

int main()
{
    Solution sl;
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> res = sl.findMissingAndRepeatedValues(grid);

    for (auto i : res)
    {
        cout << i << " ";
    }
}