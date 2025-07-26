#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int count = 0;
        int mine = nums[0];
        
        for(int i = 1;i<n;i++)
        {
            int maxe = nums[i];

            if(maxe - mine > k)
            {
                count++;
                mine = maxe;
            }
        }
        count++;

        return count;

        
    }
};

int main()
{
    vector<int> nums = { 3,6,1,2,5};
    int k =2 ;

    Solution sl;

    cout<<sl.partitionArray(nums,k);
}