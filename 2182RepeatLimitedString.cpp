#include <bits/stdc++.h>
using namespace std;

class Solution
{
    #define pii pair<int,int>
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int n = s.size();
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        priority_queue<pii> maxheap;

        for (int i = 0; i < 26; i++)
        {
            if(freq[i]>0)
            {
                maxheap.push(make_pair(i,freq[i]));
            }
        }

        string res;

        while(!maxheap.empty())
        {
            pii curr = maxheap.top();
            maxheap.pop();

            char cur_char =  'a'+ curr.first;

            int count = min(curr.second,repeatLimit);
            curr.second -= count;
            res.append(count,cur_char);  // it adds curr_char ,count number of times

            if(curr.second>0)
            {
                if(maxheap.empty()) break;  //cant insert same char again if there is no other character remaining

                pii nextpair = maxheap.top();
                maxheap.pop();

                char next_char = 'a' + nextpair.first;
                res.push_back(next_char); //append it only once

                nextpair.second--;

                if(nextpair.second>0)
                 maxheap.push(nextpair);

                maxheap.push(curr);
            }

        }
        return res;
    }
};

int main()
{
    Solution sl;
    string s = "cczazcc";
    int rL = 3;

    cout<<sl.repeatLimitedString(s,rL);

   
}