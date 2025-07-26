#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;
    public:
        long long countGood(vector<int>& nums, int k) {
            
            ll n = nums.size();

            ll left = 0, right = 0;
            ll good_subarrays = 0;
            unordered_map<ll,ll> freq;
            ll equal_pairs = 0;

            while(left<n)
            {
                while(right<n and equal_pairs<k)
                {
                    freq[nums[right]]++;
                    if(freq[nums[right]]>=2)
                        equal_pairs += freq[nums[right]]-1;
                    right++;
                }

                if(equal_pairs>=k)
                good_subarrays += n-right+1;

                //Remove left item
                freq[nums[left]]--;
                if(freq[nums[left]]>0)
                     equal_pairs -= freq[nums[left]];
                
                left++;
            }
            return good_subarrays;

        }
    };

int main()
{
    Solution sl;
    vector<int> nums =  {3,1,4,3,2,2,4};
    int k = 2;

    cout<<sl.countGood(nums,k);
}