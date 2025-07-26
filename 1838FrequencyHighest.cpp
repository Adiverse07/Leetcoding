#include <bits/stdc++.h>
using namespace std;

// using binary Search
//  class Solution
//  {

//     int bS(int targetidx, int k, vector<int> &nums, vector<long > &prefixSum)
//     {
//         int target = nums[targetidx];

//         int l = 0;
//         int r = targetidx;
//         int result = targetidx;

//         while(l<=r)
//         {
//             int mid = l +  (r - l)/2;

//             long count  = (targetidx-mid+1);

//             long windowSum = count*target;

//             long currSum = prefixSum[targetidx] - prefixSum[mid] +  nums[mid];

//             int ops =  windowSum-currSum;

//             if(ops>k)
//             {
//                 l=mid+1;
//             }
//             else
//             {
//                 result= mid;
//                 r = mid-1;
//             }
//         }

//         return targetidx - result +1;
//     }
// public:
//     int maxFrequency(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         int result = 0;
//         vector<long> prefixSum(n);

//         sort(begin(nums), end(nums));

//         prefixSum[0] = nums[0];

//         for (int i = 1; i < n; i++)
//         {
//             prefixSum[i] = prefixSum[i - 1] + nums[i];
//         }

//         for(int targetidx = 0;targetidx<n;targetidx++)
//         {
//             result  = max(result, bS(targetidx,k,nums, prefixSum));
//         }

//         return result;
//     }
// };

// using sliding window while loop
// class Solution
// {
// public:
//     int maxFrequency(vector<int> &nums, int k)
//     {
//         sort(begin(nums), end(nums));
//         int n = nums.size();
//         long currSum = 0; // Fix 1: Prevent overflow
//         int l = 0, r = 0;
//         int result = 0;

//         while (r < n)
//         {
//             int count = r - l + 1;
//             long ops = (long)(r - l) * nums[r] - currSum; // Fix 1: Use long arithmetic

//             if (ops > k)
//             {
//                 currSum -= nums[l];
//                 l++;
//             }
//             else
//             {
//                 currSum += nums[r];
//                 result = max(result, count); // Fix 2: Track max window
//                 r++;
//             }
//         }

//         return result;
//     }
// };

// sliding window for loop
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        long currSum = 0;
        long l = 0;
        long result = 0;
        long ops, windowSum, orignalSum, target;

        sort(nums.begin(), nums.end());

        for (int r = 0; r < n; r++)
        {
            target = nums[r];
            currSum += nums[r];

            windowSum = (r - l + 1) * target;

            orignalSum = currSum;

            ops = windowSum - orignalSum;

           if(ops > k)
            {
                currSum -= nums[l];
                l++;

                ops = ((r - l + 1) * target) - currSum;
            }

            result = max(result, (r - l + 1));
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {3, 9, 6};
    int k = 2;
    Solution sl;

    cout << sl.maxFrequency(nums, k);
}