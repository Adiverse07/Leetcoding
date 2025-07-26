#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int> uniqueSet(nums.begin(),nums.end());
            unordered_map<int,int> uniqueMap;
            int completeSubarrays = 0;
            int uniqueCount =  uniqueSet.size();

            int left = 0;
            int right = 0;

           while(left<n)
           {
            while(right<n and uniqueMap.size()<uniqueCount)
            {
                uniqueMap[nums[right]]++;
                right++;
            }

            //out of bounds , when first condition fails
            if(uniqueMap.size()<uniqueCount)
            break;

            completeSubarrays += n-right+1;

            uniqueMap[nums[left]]--;
            if(uniqueMap[nums[left]]==0)
            {
                uniqueMap.erase(nums[left]);
            }
            left++;
           }

            return completeSubarrays;

        }
    };

int main()
{
    Solution sl;
    vector<int> nums = {1,3,1,2,2};
    cout<<sl.countCompleteSubarrays(nums);

}