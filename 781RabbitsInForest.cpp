#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int n = answers.size();
            int rabitCount = 0;

            unordered_map<int,int> grpcount;

            for(int i =0;i<n;i++)
            {
                if(answers[i]!=0)
                grpcount[answers[i]]++;

                if(answers[i]==0)
                rabitCount++;

                if(grpcount[answers[i]]==answers[i]+1)
                {
                    rabitCount+=answers[i]+1;
                    grpcount[answers[i]]=0;
                }

            }

            for(auto &it: grpcount)
            {
                if(it.second > 0)
                rabitCount += it.first+1;
            }
            return rabitCount;
        }
    };

int main()
{
    vector<int> answers ={1,1,2};
    Solution sl;

    cout<<sl.numRabbits(answers);

}