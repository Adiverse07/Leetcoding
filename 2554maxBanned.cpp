#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
     // int maxCount(vector<int>& banned, int n, int maxSum) {
        
    //     int currentSum =0;
    //     int count=0;

    //     for(int i=1;i<=n;i++)
    //     {
    //         if(find(banned.begin(),banned.end(),i)==banned.end())
    //         {
    //             currentSum+=i;
    //             if(currentSum<=maxSum)
    //             {
    //                 count=count+1;
    //             }
    //         }
    //     }
    //     return count;
    //}
    //};
    //Og solution

class Solution
{
    public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
       unordered_set <int> bannedSet(banned.begin(),banned.end());

       long long currentSum =0;
       int count =0;

       for(int i=1;i<=n;i++)
       {
        if(bannedSet.count(i)) continue;
        
        currentSum+=i;
        if(currentSum>maxSum) break;

        count=count+1;

       }
       return count;
}
};

int main()
{
    Solution sl;
    vector<int> banned = {11};
    int n = 7;
    int maxSum =50;
    cout<<sl.maxCount(banned,n,maxSum);
}