#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool check(int m, vector<int> &nums, int o)
    {
        for(int  i= 0;i<nums.size();i++)
        {
            o-=nums[i]/m;
            if(nums[i]%m==0) o++;

        }
        return o>=0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int s =1, end =  INT_MAX;
        int ans =0;

        while(s<=end)
        {
            int mid = s+(end-s)/2;
            if(check(mid,nums,maxOperations))
            {
                ans = mid;
                end=mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    
    vector<int> nums = {2,4,8,2};

    int maxOps = 4;

    cout<<sl.minimumSize(nums,maxOps);
    

}