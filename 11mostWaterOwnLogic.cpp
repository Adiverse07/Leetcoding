//Passes the test cases but   it is logically incorrect
// code assumes the largest height always contributes to the maximum area. This is not true; sometimes, a smaller height paired with a larger distance can result in a larger area.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxh = 0;
        int maxhindex;
        int diff=0;
        int area=0;
        int maxArea =0;

        for(int i =0;i<height.size();i++)
        {
            if(maxh<height[i])
            {
            maxh = height[i];
            maxhindex = i;
            }
        }
        for(int i = 0;i<height.size();i++)
        {
            diff = abs(i-maxhindex);
            area = min(maxh,height[i]) * diff;

            if(maxArea<area)
            maxArea = area;
            
        }
        cout<<maxArea;
       
        
    }
};

int main()
{
    Solution s;
     vector<int> arr= {1,8,6,2,5,4,8,3,7};
     s.maxArea(arr);

}