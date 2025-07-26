#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
            vector<int> splits;

            for(int i =0;i<n-1;i++)
            {
                splits.push_back(weights[i]+weights[i+1]);
            }
            
            sort(splits.begin(),splits.end());

            long long maxsplit = 0;
            long long minsplit = 0;

            for(int i =0;i<k-1;i++)
            {
                maxsplit += splits[splits.size()-1-i];
            }
            for(int i = 0; i < k-1; i++) {
                minsplit += splits[i];
            }
            
            
            long long max_score = weights[0] + weights[n-1] + maxsplit;
            long long min_score = weights[0] + weights[n-1] + minsplit;

            return  max_score - min_score;
        }

        
    };

int main()
{
    vector<int> weights = {1,3,5,1};
    int k = 2 ;

    Solution sl;


    cout<<sl.putMarbles(weights,k);
}