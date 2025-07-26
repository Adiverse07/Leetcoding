#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int maxSum =0;
       
        // sort(events.begin(),events.end(),[](const vector<int> &a, const vector<int> &b)
        // {
        //     return a[0] >b[0];
        // });

        for(int i=0;i<events.size();i++)
        {
            for(int j=1;j<events.size();j++)
            {
                if(events[i][1]>events[i][0] && (maxSum<events[i][2]+events[j][2] || maxSum<events[i][2]))
                {
                    maxSum = events[i][2] + events[j][2];

                    if(maxSum<events[i][2])
                    {
                        
                    }
                }
            }
        }

       
        
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};

    cout<<sl.maxTwoEvents(events);
}