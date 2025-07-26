#include <bits/stdc++.h>
using namespace std;

//For k positives
// class Solution{
// public:
//     int longestSubarray(vector<int> &nums, int k){
//         int l = 0,r  =0;
//         int n =  nums.size();
        
//         int longest = 0;
//         int currSum = 0;

//         while(l<n  && r<n)
//         {
//             currSum+=nums[r];

//           while(currSum>k && l<=r)
//           {
//             currSum-= nums[l];
//             l++;
//           }

//           if(currSum ==k)
//           {
//             longest =  max(longest,r-l+1);
//           }

//           r++;
//         }

//         return longest;
        
//     }
// };

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        unordered_map<int, int> prefixIndex;
        int sum = 0;
        int longest = 0;

        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];

            if(sum == k) 
                longest = i + 1;

            if(prefixIndex.find(sum - k) != prefixIndex.end()){
                longest = max(longest, i - prefixIndex[sum - k]);
            }

            // Store the first occurrence only
            if(prefixIndex.find(sum) == prefixIndex.end())
                prefixIndex[sum] = i;
        }

        return longest;
    }
};


int main()
{
    Solution sl;
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout<<sl.longestSubarray(nums,k);
}

