#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            
            int n = nums.size();
            sort(nums.begin(),nums.end());


            ll ans = 0;

            for(int i =0; i<n;i++)
            {
                int lb = lower_bound(nums.begin()+i+1 , nums.end(), lower - nums[i])- nums.begin();
                int ub = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]) - nums.begin();

                ans += (ub - lb);
            }
            return ans;
        }
    };

int main()
{
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3;
    int upper = 6;

    Solution sl;
    

    cout<<sl.countFairPairs(nums,lower, upper);
}