#include <bits/stdc++.h>
using namespace std;

class Solution {
        int& getMin(int &a, int &b, int &c)
        {
            if(a<=b && a<=c) return a;
            if(b<=a && b<=c) return b;
            return  c;
        }
public:
    int maximumLength(string s) {
        
        int n = s.size();
        vector<vector<int>>  top3Freq(26, vector<int>(3,-1));

        char lastseen = '*';
        int win_len =0;

        for(char& curr:s)
        {
            int index = curr - 'a';

            win_len = curr==lastseen ? win_len+1 : 1;

            lastseen = curr;

            int &minimum = getMin(top3Freq[index][0],top3Freq[index][1],top3Freq[index][2]);

            if(win_len>minimum)
            minimum = win_len;
        }

        int maxLen =-1;
        for(int i =0;i<26;i++)
        {
            maxLen = max (maxLen, min({top3Freq[i][0],top3Freq[i][1],top3Freq[i][2]}));
        }
        return maxLen;
    }
};

int main()
{
    Solution sl;

    string s = "aaabbaaaacczzaaaaa";
    cout<<sl.maximumLength(s);
}