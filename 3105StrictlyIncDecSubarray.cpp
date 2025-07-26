#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int inc = 1;
        int finaldec = 1;
        int finalinc = 1;
        int dec = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                inc++;
                if (finalinc < inc)
                {
                    finalinc = inc;
                }
            }
            else
            {

                inc = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                dec++;
                if (finaldec < dec)
                {
                    finaldec = dec;
                }
            }
            else
            {

                dec = 1;
            }
        }

        return max(finalinc, finaldec);
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {3, 2, 1};

    cout << sl.longestMonotonicSubarray(nums);
}