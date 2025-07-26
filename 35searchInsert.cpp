#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
       int startindx = 0;
       int endindx = nums.size() -1;
       int mid ;
       

        while(startindx<=endindx)
        {
            mid = (startindx + endindx)/2;

            if(nums[mid]==target)
            return mid;

            else if(nums[mid]<target)
            startindx = mid+1;

            else if(nums[mid]>target)
            endindx = mid-1;
            
        }
        return startindx;
    }
};

int main()
{
    Solution  s;

    vector<int> arr = {1,3,5,6};
    int val = 0;
    cout<<s.searchInsert(arr,val);
}