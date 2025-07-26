#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
       
        int s1 = nums1.size();
        int s2 = nums2.size();
        vector<vector<int>> res;
        int p1 = 0;
        int p2 =0;

        while(p1<s1  and p2<s2)
        {
            int firstk =  nums1[p1][0];
            int secondk = nums2[p2][0];

            int firstv =  nums1[p1][1];
            int secondv  = nums2[p2][1];

            if(firstk == secondk)
            {
                res.push_back({firstk, firstv+secondv});
                p1++;
                p2++;
            }
            else if(firstk<secondk)
            {
                res.push_back({firstk,firstv});
                p1++;
            }
            else if(secondk < firstk)
            {
                res.push_back({secondk,secondv});
                p2++;
            }
        }

        while(p1<s1)
        {
        res.push_back({nums1[p1][0],nums1[p1][1]});
        p1++;
        }

        while(p2<s2)
        {
        res.push_back({nums2[p2][0],nums2[p2][1]});
        p2++;
        }

        

        return res;
        
        
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> nums1 = {{2,4},{3,6},{5,5}};
    vector<vector<int>> nums2 = {{1,3},{4,3}};

    vector<vector<int>> res = sl.mergeArrays(nums1,nums2);

    for(auto ele: res)
    cout<<ele[0]<<" : "<<ele[1]<<endl;
}