#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 =  nums2.size();
        int res = 0;

        if(n1%2 == 1)
        {
            for(auto e: nums2)
            res^=e;
        }

         if(n2%2 == 1)
        {
            for(auto e: nums1)
            res^=e;
        }

        return res;
    }
};

int main()
{
    vector<int> nums1 = { 2,1,3};
    vector <int> nums2 ={10,2,5,0};

    Solution sl;
    cout<<sl.xorAllNums(nums1,nums2);

}