#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int result = 0;

            for(int i = low; i<=high;i++)
            {
                string num = to_string(i);
                int n = num.size();

                if(n%2) continue; // skip if number of digits is odd

                int first_sum = 0, last_sum = 0;

                for(int j =0;j<n/2;j++)
                {
                    first_sum+=num[j];
                    last_sum += num[n-j-1];
                }

                if(first_sum==last_sum) result++;

               
            }
            return result;
        }
    };

int main()
{
    Solution sl;
    int low = 1200;
    int high = 1230;

    cout<<sl.countSymmetricIntegers(low,high);

}