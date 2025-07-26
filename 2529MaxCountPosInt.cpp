#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int lowerbound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        int mid;

        while (left < right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }

    int upperbound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid;

        while (left < right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }

public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();
        int lb = lowerbound(nums, 0);
        int rb = upperbound(nums, 0);

        return max(lb, n - rb);
    }
};

// class Solution {
//     public:
//         int maximumCount(vector<int>& nums) {
//             int n = nums.size();
//             int maxn = 0;
//             int maxp = 0;

//             for(int i = 0;i<n;i++)
//             {
//                 if(nums[i]<0)
//                 {
//                     maxn++;
//                 }
//                 if(nums[i]>0)
//                 {
//                     maxp++;
//                 }
//             }

//             return max(maxn, maxp);
//         }
//     };

int main()
{
    vector<int> nums = {-2, -1, -1, 1, 2, 3};
    Solution sl;

    cout << sl.maximumCount(nums);
}