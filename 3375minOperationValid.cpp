#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_set<int> unique;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > k)
                unique.insert(nums[i]);
            if(nums[i]<k) return -1;
        }
        int ans = unique.size();

        return ans >= 0 ? ans : -1;
    }
};

int main()
{
    Solution sl;

    vector<int> nums = {5, 2, 5, 4, 5};
    int k = 2;

    cout << sl.minOperations(nums, k);
}