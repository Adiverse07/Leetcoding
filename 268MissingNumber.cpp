#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        unordered_set<int> numUnique;
        int res = -1;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++)
        {
            if(nums[i]!=i)
            res = i;
        }

        if(res==-1) res = n;
        return res;
    }
};


int main()
{
    Solution sl;

    vector<int> nums = {0,1};

    cout<<sl.missingNumber(nums);
}