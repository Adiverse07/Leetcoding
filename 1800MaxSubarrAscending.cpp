#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int maxSum = 0;
        int currentSum = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                currentSum += nums[i]; // 30 60 //15 65
            }
            else
            {
                if (maxSum < currentSum)
                    maxSum = currentSum; // 100
                currentSum = nums[i]; // 10
            }
        }

        return max(maxSum, currentSum);
    }
};

int main()
{
    vector<int> nums = {100, 10, 1};

    Solution sl;

    cout << sl.maxAscendingSum(nums);
}