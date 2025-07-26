#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        for(auto i = nums.begin();i!= nums.end();)
        {
            if(*i ==  val)
            {
                i = nums.erase(i);
            }
            else{
                ++i;
            }
        }
        int k = nums.size();
        
        return k;
        
    }
};

int main()
{
    Solution  s;

    vector<int> arr = {1,2,3,4,5,6,6,7};
    int val = 6;

    s.removeElement(arr,val);

}