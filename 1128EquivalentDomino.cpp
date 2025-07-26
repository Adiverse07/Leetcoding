#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {

            unordered_map<int,int> freq;

            int count = 0;

            for(auto ele : dominoes){
                int a = ele[0], b = ele[1];
                if(a>b) swap(a,b);

                int key = a*10+b; //unique encoding to each pair
                count+=freq[key];

                freq[key]++;
            }
            return count;
            
        }
    };

    int main()
    {
        vector<vector<int>> dominoes = { {1,2},{2,1},{3,4},{5,6}};
        Solution sl;

        cout<<sl.numEquivDominoPairs(dominoes);
    }