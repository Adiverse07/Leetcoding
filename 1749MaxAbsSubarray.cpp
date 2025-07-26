#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        // Kadanes algorithm

        int n = nums.size();

        int maxSum = INT_MIN;
        int sum = 0;

        int minSum = INT_MAX;
        int msum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            maxSum = max(maxSum, sum);

            if (sum < 0)
                sum = 0;
        }

        for (int i = 0; i < n; i++)
        {
            msum += nums[i];

            minSum = min(minSum, msum);
            
            if (msum > 0)
                msum = 0;
        }

        return max(abs(maxSum), abs(minSum));
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {2, -5, 1, -4, 3, -2}; // 3 4 0 3 -1 // -4 -8 -5 -7 // -3 0 -2
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << sl.maxAbsoluteSum(nums);
}