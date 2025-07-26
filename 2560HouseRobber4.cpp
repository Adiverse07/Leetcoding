#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        int low = *min(nums.begin(), nums.end());
        int high = *max(nums.begin(), nums.end());

        int mid ;

    }
};

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    int k = 2;
    Solution sl;

    cout << sl.minCapability(nums, 2);
}