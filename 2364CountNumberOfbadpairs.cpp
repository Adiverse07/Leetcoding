#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    long long countBadPairs(vector<int> &nums)
    {
        long long n = nums.size();
        long long totalpairss = (n * (n - 1)) / 2;

        unordered_map<int, long long> dif_freq;
        long long goodpairs = 0;

        //reserving space
        dif_freq.reserve(n);

        for (int i = 0; i < n; i++)
        {
            int diff = nums[i]-i;
            goodpairs += dif_freq[diff];
            dif_freq[diff]++;
        }

        return totalpairss - goodpairs;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution sl;

    cout << sl.countBadPairs(nums);
}