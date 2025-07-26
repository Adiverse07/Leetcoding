#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();

            int maxN = *max_element(nums.begin(),nums.end());    
            
            int left = 0;
            int right = 0;
            
            ll maxCount = 0;
            ll res = 0;

            while(left<n)
            {
                while(right<n and maxCount!=k)
                {
                    if(nums[right]==maxN)
                    maxCount++;

                    right++;
                }
                if(maxCount==k)
                res+=n-right+1;

                if(nums[left]==maxN)
                maxCount--;

                left++;

            }

            return res;
            
        }
    };

    int main()
    {                     //0,1,2,3,4
        vector<int> nums = {1,3,2,3,3 };
        int k =2;

        Solution sl;

        cout<<sl.countSubarrays(nums,k);

    }