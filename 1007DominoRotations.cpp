#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
           int masiha = -1;

            for(int i =1;i<=6;i++)
            {
                for(int j =0;j<6;j++)
                {
                    if(tops[j] == i || bottoms[j] == i)
                    {
                        masiha = i;
                    }
                    else
                    {
                        masiha = -1;
                    break;
                    }
                }
                if(masiha!=-1)
                break;
            }
            return masiha;
        }
    };

int main()
{
    vector<int> tops = {2,1,2,4,2,2};
    vector<int> bottoms = {5,2,6,2,3,2};

    Solution sl;

    cout<<sl.minDominoRotations(tops,bottoms);
}