#include <bits/stdc++.h>
using namespace std;

// Difference array technique sikhli BCCCCCC
class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> diffArray(n + 1, 0);
        int sum = 0;
        int pos = 0;

        for (int i = 0; i < n; i++)
        {
            while (sum + diffArray[i] < nums[i])
            {
                if (pos == queries.size()) // ALL queries done?
                    return -1;

                int start = queries[pos][0];
                int end = queries[pos][1];
                int val = queries[pos][2];

                pos++;

                if(end < i) continue; //skip the past update like if a range has already been processed

                diffArray[max(start,i)]+=val;
                diffArray[end+1]-=val;

                
            }

            sum+=diffArray[i];
        }

        return pos;
    }
};

int main()
{
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    Solution sl;

    cout << sl.minZeroArray(nums, queries);
}