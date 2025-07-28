#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countSubsets(int idx, int currOr , vector<int> &nums, int &maxOR, vector<vector<int>>& t)
    {
       
        if(idx >= nums.size())
        {
            if(currOr == maxOR)
                return 1;
            return 0;
        }

         //if it is already calculated
        if(t[idx][currOr]!=-1)
        return t[idx][currOr];

        //take
        int takeCount = countSubsets(idx + 1, currOr | nums[idx], nums, maxOR, t);

        //not take
        int notTakeCount = countSubsets(idx+1 , currOr , nums, maxOR, t);

        return t[idx][currOr] = takeCount + notTakeCount;
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;

        for(int num : nums)
            maxOR |= num;
        //T.C =  n* maxOR (with memoization) // without it is n^2
        //s.C =  n*maxOR
        vector<vector<int>> t(n+1, vector<int>(maxOR + 1, -1));
        int currOr = 0;
        return countSubsets(0,currOr, nums, maxOR,t);
    }
};

