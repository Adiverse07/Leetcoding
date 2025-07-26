#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        int p=0;
        int q=n-1;  
        vector<int> res;
        for(int i: nums)
        {
            if(i<pivot) res.push_back(i);
        }
        for(int i: nums)
        {
            if(i==pivot) res.push_back(i);
        }
        for(int i: nums)
        {
            if(i>pivot) res.push_back(i);
        }

        return res;

    }
};

int main()
{
    Solution sl;
    vector<int> nums = {9,12,5,10,14,3,10}; //[9,5,3,10,10,12,14]
    int pivot = 10;

    vector<int> res = sl.pivotArray(nums,pivot);

    for(auto i: res)
    cout<<i<<" ";
}