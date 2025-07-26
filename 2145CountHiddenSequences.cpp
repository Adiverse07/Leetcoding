#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long maxv = 0;
            long long minv = 0;
            long long currv = 0;
            int countOfValidSequences;
            for(int i =0;i<differences.size();i++)
            {
                currv+=differences[i];

                maxv = max(maxv, currv);
                minv = min(minv,currv);

            }

            countOfValidSequences = (upper-lower) - (maxv-minv) +1;

            return countOfValidSequences > 0 ? countOfValidSequences : 0;
            
        }
    };
int main(){
    Solution sl;

    vector<int> differences = {1,-3,4};
    int lower  = 1;
    int upper = 6;

    cout<<sl.numberOfArrays(differences,lower, upper);
}