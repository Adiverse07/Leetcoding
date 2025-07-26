#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        //3,4,5,1,2  3,4,5,1,2
        int count = 1;

        for(int i = 1;i<2*n;i++)
        {
            if(nums[(i-1)%n] <= nums[i%n])
            {
                count++;
            }
            else
            count=1;

            if(count==n)
            return true;
        }
    
        return false;
    }
};

int main()
{
    vector<int> nums = {3,4,5,1,2};
    Solution sl;

    if(sl.check(nums))
    cout<<"yoo";
    else
    cout<<"bc";
}