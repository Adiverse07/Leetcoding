#include <bits/stdc++.h>
using namespace std;

//most optimal : with space and time optimized both beat 100% in leetcode
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int xorArr = 0;

        for (int i = 0; i < n; i++) {
            xorArr ^= nums[i];
            xorArr ^= i + 1;
        }

        return xorArr;
    }
};

int main()
{
    Solution sl;

    vector<int> nums = {0,1};

    cout<<sl.missingNumber(nums);
}
//better than brute
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
        
//         unordered_set<int> numUnique;
//         int res = -1;
//         int n = nums.size();
        
//         sort(nums.begin(),nums.end());

//         for(int i = 0;i<n;i++)
//         {
//             if(nums[i]!=i)
//             res = i;
//         }

//         if(res==-1) res = n;
//         return res;
//     }
// };

//optimizing time not space
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {

//         int n = nums.size();
//         int xorArr = 0;
//         int xorAll = 0;
//         for (int i = 0; i < n; i++) {
//             xorArr ^= nums[i];
//             xorAll ^= i + 1;
//         }

//         return xorArr ^ xorAll;
//     }
// };
