#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> prevSum;
        prevSum[0] = 1; // in case the subarray starts from index 0
        // for ex :[1,1,1] and k =3; in this case when i is at index 2 it  checks for  3 - 3 which is 0

        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (prevSum.find(sum - k) != prevSum.end())
            {
                count += prevSum[sum - k];
            }

            prevSum[sum]++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;
    Solution sl;
    cout << sl.subarraySum(nums, k);
}