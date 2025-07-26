#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        int sum = 0;

        for(int i =0;i<n;i++)
        {
            sum+=nums[i];

            maximum = max(maximum,sum);

            if(sum<0)
            sum = 0;

        }

        return maximum;
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4 };

    cout<<sl.maxSubArray(nums);
}