#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            
            int n = nums.size();
            int freq =0;
            int me = nums[0];
            
            //moores voting algo
            for(int i=0;i<n;i++)
            {
                if(nums[i]==me)
                freq+=1;
                else
                {
                    freq-=1;

                    if(freq==0)
                    {
                        me = nums[i];
                        freq =1;
                    }
                }
            }

           int prefixsum =0;
           int maxfreq = count(nums.begin(),nums.end(),me);
           int res=-1;

           for(int i =0;i<n;i++)
           {
            if(nums[i]==me)
            {
                prefixsum++;
                if(prefixsum>((i+1)/2) and (maxfreq-prefixsum) > (n-i-1)/2 )
                {
                res =i;
                break;
                }
            }
           }

           return res;
          
        }
    };

int main()
{
    Solution sl;
    vector<int> nums = {1,2,2,2};

    cout<<sl.minimumIndex(nums);
}