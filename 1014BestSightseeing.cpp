#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int n = values.size();

        int first = values[0];
        int mps = INT_MIN;
        int second;

        for(int i=1;i<n;i++)
        {
         second = values[i]-i;
         mps = max(mps,first + second);
         first = max(first, values[i]+i);
        }

        return mps;
        
    }
};

int main()
{
    vector <int> v = {8,1,5,2,6};
    Solution sl;
    
    cout<<sl.maxScoreSightseeingPair(v);

}