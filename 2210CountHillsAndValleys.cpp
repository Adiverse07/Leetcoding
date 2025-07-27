#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     void removeFlatSurface(vector<int> &nums)
//     {
//         int n = nums.size();
//         int write = 0;
//         for (int read = 0; read < n; read++)
//         {
//             if(nums[read]!=nums[write])
//             {
//                 write++;
//                 nums[write] = nums[read];

//             }
//         }
//         nums.resize(write+1);
//     }

//     int countHillValley(vector<int> &nums)
//     {
//         int hills = 0, valleys = 0;
//         removeFlatSurface(nums);
//         int n = nums.size();

//         for (int i = 1; i < n - 1; i++)
//         {
//             if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i])
//             {
//                 hills++;
//             }
//             else if (nums[i - 1] > nums[i] && nums[i + 1] > nums[i])
//             {
//                 valleys++;
//             }
         
//         }

//         return hills + valleys;
//     }
// };
//optimized
class Solution {
public:
    int countHillValley(vector<int> &nums) {
        int n = nums.size();
        int i =0;
        int j = 1;
        int count = 0;


        while(j+1 < n)
        {
            if((nums[i] < nums[j] && nums[j] > nums[j+1]) || (nums[i] > nums[j] && nums[j] < nums[j+1]))
            {
                count++;
                i=j;
            }
            j++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {5,7,7,1,7};
    Solution sl;

    cout << sl.countHillValley(nums);
}



