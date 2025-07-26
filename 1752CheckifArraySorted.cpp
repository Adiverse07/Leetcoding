#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int count =1;

        if(n==1) return true;
        for(int i = 1; i<2*n; i++)
        {
            if(nums[(i-1)%n] <= nums[i%n])
            {
                count++;
            }
            else
            count = 1;

            if(count == n)
            return true;
        }
        return false;

        
    }
};

int main()
{
    vector<int> nums = {2, 1, 3, 4};

    Solution sl;

    if (sl.check(nums))
        cout << "True";
    else
        cout << "False";
}