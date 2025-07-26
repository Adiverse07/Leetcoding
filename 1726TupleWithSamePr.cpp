#include <bits/stdc++.h>
using namespace std;

class Solution {

    int nC2(int n )
    {
        return (n*(n-1))/2;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map <int, int> freq;

        for(int i =0;i<n-1;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                freq[nums[i]*nums[j]]++;
            }
        }


        for(auto i : freq)
        {
            if(i.second>=2)
            count+= 8 * nC2(i.second);
        }

        return count;
        
    }
};

int main()
{
    Solution sl;
    vector <int> nums = {2,3,4,6 };

    cout<<sl.tupleSameProduct(nums);
}
