#include <bits/stdc++.h>
using namespace std;

class Solution
{
public: 
    bool isValid(vector<int> nums)
    {
        if(nums[0]+nums[1] <= nums[2] || nums[0]+nums[2] <= nums[1] || nums[1]+nums[2] <= nums[0])
        return false;

        return true;

        
    }
    string triangleType(vector<int> &nums)
    {
        string res;

        if(!isValid(nums))
        return "none";

        if (nums[0] == nums[1] && nums[1] == nums[2])
        {
            res = "equilateral";
        }
        else if ((nums[0] == nums[1] || nums[1] == nums[2] || nums[0]==nums[2]))
        {
            res ="isosceles";
        }
        else if(nums[0]!=nums[1] && nums[1]!=nums[2])
        {
            res = "scalene";
        }
        
        return res;
    }
};

int main()
{
    vector<int> nums = {5,3,8};
    Solution sl;

    cout << sl.triangleType(nums);
}