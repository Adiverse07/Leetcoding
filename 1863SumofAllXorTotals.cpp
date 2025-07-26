#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int n = nums.size();
        int total = 1 << n;
        int xorTotal = 0;

        for (int mask = 0; mask < total; mask++)
        {
            int xorSum = 0;
            for (int i = 0; i < n; i++)
            {
                if(mask & (1<<i))
                xorSum ^= nums[i];
                
            }
            xorTotal += xorSum;
        }

        return xorTotal;
    }

};

int main()
{
    Solution sl;
    vector<int> nums = {5, 1, 6};

    cout << sl.subsetXORSum(nums);
}