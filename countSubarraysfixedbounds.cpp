#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long

    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {

            int n = nums.size();
            ll valid_subarrays=0;
            int inv_idx = -1;
            int minidx = -1;
            int maxidx = -1;

            for(int i =0;i<n;i++)
            {
                if(nums[i]<minK or nums[i]>maxK) inv_idx = i;

                if(nums[i]==minK) minidx = i;
                if(nums[i]==maxK) maxidx = i;

                int count = max((min(minidx,maxidx)-inv_idx),0);
                valid_subarrays +=count;

            }

            return valid_subarrays;
        }
    };

int main()
{
    Solution sl;
    vector<int> nums = {1,3,5,2,7,5};

    cout<<sl.countSubarrays(nums,1,5);
}