#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> prefix_sum(n, 0);
        int validSplitCount=0;

        for(int i =0;i<n;i++)
        {
            if(i==0)
            {
                prefix_sum[i] = nums[i];
            }
            else
            {
                prefix_sum[i] = prefix_sum[i-1] + nums[i];
            }
            // cout<<prefix_sum[i]<<" "; // debugging steps
        }
        

        for(int i=0;i<n-1;i++)
        {
            int l = i+1;
            int r = n-1;

            long long leftpart = prefix_sum[i];

            long long rightpart = prefix_sum[r] -prefix_sum[l-1];
            
            if(leftpart>=rightpart)
            validSplitCount++;
        }

        return validSplitCount;

    }
};

int main()
{
    vector<int> arr = {0,0};
    Solution sl;

    cout << sl.waysToSplitArray(arr);
}


//optimized
/*
class Solution {
public:
    static int waysToSplitArray(vector<int>& nums) {
        const int n=nums.size();
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        long long acc=0LL;
        int cnt=0;
        for(int i=0; i<n-1; i++){
            acc+=nums[i];
            cnt+=(2*acc>=sum); 
            /*
             right = left - sum , here condition must be left>=right 
             "i.e acc>= sum-acc" ......Add acc to both sides
             acc+acc >= sum - acc + acc
             2*acc >= sum
            /*
        }
        return cnt;
    }
};
*/