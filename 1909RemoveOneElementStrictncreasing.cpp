#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> dup = nums;

            dup.erase(dup.begin() + i);

            int flag = 0;
            for (int j = 1; j < dup.size(); j++)
            {
                if (dup[j - 1] >= dup[j])
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
                return true;
                }
        return false;
    }
};

int main()

{
    Solution s;
    vector<int> nums = {1, 2, 10, 5, 7};
    vector<int> nums1 = {1, 1, 1};
    vector<int> nums2 = {105, 924, 32, 968};
    vector<int> nums3 = {512,867,904,997,403};

    if (s.canBeIncreasing(nums3))
        cout << "Yes";
    else
        cout << "No";
}