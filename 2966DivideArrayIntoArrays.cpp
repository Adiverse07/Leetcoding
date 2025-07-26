#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> temp;
        for (int i = 0; i < n; i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
                return {};
            else
            {
                res.emplace_back(nums.begin() + i, nums.begin() + i + 3);
            }
        }

        return res;
    }
};

int main()
{
    Solution sl;

    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;

    vector<vector<int>> res = sl.divideArray(nums, k);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}