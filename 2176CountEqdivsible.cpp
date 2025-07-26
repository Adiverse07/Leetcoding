#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size();
            int count = 0;
            for(int i = 0;i<n;i++)
            {
                for(int j = i+1;j<n;j++)
                {
                    if(nums[i]==nums[j] && (i*j)%k==0)
                    {
                        count++;
                    }
                }
            }
            return count;
        }
    };

int main()
{
    Solution sl;
    vector<int> nums = {3,1,2,2,2,1,3};
    int k = 2;

    cout<<sl.countPairs(nums,k);
    
}