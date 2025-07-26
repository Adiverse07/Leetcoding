#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long
    public:
        int numOfSubarrays(vector<int>& arr) {
            
            int n = arr.size();
            ll  total =0;
            ll odd_count =0;
            ll even_count =1;
            ll prefixsum = 0;

            for(int i =0;i<n;i++)
            {
                prefixsum+=arr[i];

                if(prefixsum & 1)
                {
                    total += even_count;
                    odd_count++;
                }
                else
                {
                    total += odd_count;
                    even_count++;
                }
            }

            return total;
        }
    };

    int main()
    {
        vector <int> arr = {1,3,5};
        Solution sl;

        cout<<sl.numOfSubarrays(arr);
    }