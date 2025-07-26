#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();

        int maxL = nums[0];
        long long res =0;

        long long bestDiff = 0;

        for (int i = 1; i < n; i++)
        {
            //Compute the triplet value
            res = max(res, bestDiff * nums[i]);

            //Compute the best difference too far
            bestDiff = max(bestDiff, (long long)(maxL - nums[i]));

            //Updating maxL , largest element so far
            maxL = max(maxL,nums[i]);

        }

        return res;
    }
};

// class Solution
// {

// public:
//     long long maximumTripletValue(vector<int> &nums)
//     {
//         int n = nums.size();
//         long long maxDiff = INT_MIN;
//         long long maxN = INT_MIN;
//         long long res = 0;

//         vector<int> max_left(n, INT_MIN);
//         vector<int> max_right(n,INT_MIN);

//         int maxLeft = nums[0];
//         int maxRight = nums[n-1];

//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] > maxN)
//                 maxN = nums[i];
//         }

//         //calculating max element to left of each index
//         for (int i = 1; i < n ; i++)
//         {
//            max_left[i] = maxLeft;
//            maxLeft = max(maxLeft,nums[i]);
//         }

//         //calculating max element to left of each index
//         for (int i = n-2; i >= 0 ; i--)
//         {
//            max_right[i] = maxRight;
//            maxRight = max(maxRight,nums[i]);
//         }

//         for (int i = 1; i < n -1; i++)
//         {
//         long long tripletValue = (long long)(max_left[i] - nums[i]) * max_right[i];
//         res = (max(res, tripletValue));
//         }
//         return res;
//     }
// };

int main()
{
    Solution sl;
    vector<int> nums = {1, 10, 3, 4, 19};

    cout << sl.maximumTripletValue(nums);
}