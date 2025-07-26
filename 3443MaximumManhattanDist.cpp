#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int n =  s.length();

        int maxMd = 0;
        int east = 0, west = 0, north = 0, south = 0;

        for(int i =0;i<n;i++)
        {
            if(s[i]=='E') east++;
            else if(s[i]=='W') west++;
            else if(s[i]=='N') north++;
            else if(s[i]=='S') south++;

             int currMd = abs(east - west) + abs(north - south);

             int steps = i+1;
             int wasted = steps - currMd;

             int extra = 0;

             if(wasted!=0)
             {
                extra = min(2*k,wasted);
             }

             int finalCurrMd = currMd + extra;

             maxMd = max(maxMd, finalCurrMd);
        }

        return maxMd;
       
        
    }
};

int main()
{
    Solution sl;

    string s = "NSWWEW";
    int k = 3;
    
    cout<<sl.maxDistance(s,k);
}