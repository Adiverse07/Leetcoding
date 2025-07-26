#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[100001];
    int MOD = 1000000007;

    int countWays( int &low, int &high, int &zero, int &one,int pos)
    {
        if(pos>high) return 0; // because invalid if it is greater than high, and if less than low then increment

        if(dp[pos]!=-1) return dp[pos];

        int count =0;

        if(pos>=low) count++; //if between low and high then count incremented

        count+=countWays(low,high, zero, one, pos+zero); // by increasing zero
        count+=countWays(low,high, zero,one ,pos+one); //by increasing one

        return dp[pos] = count%MOD;


    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        memset(dp,-1,sizeof(dp));

        return countWays(low,high,zero,one,0);
        
    }
};

int main()
{
    int low = 3, high = 3, zero = 1, one = 1;
    Solution sl;

    cout<<sl.countGoodStrings(low,high, zero,one);
}