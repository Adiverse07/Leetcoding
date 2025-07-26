#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> getMin(vector<int> nums)
    {
        int minVal = INT_MAX;
        int idx;
        vector<int> minPair;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minVal)
            {
                minVal = nums[i];
                idx = i;
            }
        }
        minPair = {idx, minVal};

        return minPair;
    }
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        vector<int> minPair;
        while (k--)
        {
            minPair = getMin(nums);
            nums[minPair[0]] = nums[minPair[0]] * multiplier;
        }

        return nums;
    }
};

// class Solution
// {
// #define pii pair<int, int>
// public:
//     vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
//     {

//         priority_queue<pii, vector<pii>, greater<pii>> maxheap;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             maxheap.push(make_pair(nums[i], i));
//         }

//         while (k--)
//         {
//             pii cur = maxheap.top();
//             maxheap.pop();

//             int idx = cur.second;
//             nums[idx] = nums[idx] * multiplier;

//             maxheap.push(make_pair(nums[idx], idx));
//         }

//         return nums;
//     }
// };

int main()
{
    Solution sl;
    vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5;
    int mulitplier = 2;

    vector<int> result = sl.getFinalState(nums, k, mulitplier);

    for (auto i : result)
        cout << i << " ";
}