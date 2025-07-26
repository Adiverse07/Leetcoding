#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        vector<int> chars(3,0);
        int res = 0;

        int l = 0, r = 0;

        while(r<n)
        {
            int ch = s[r]- 'a';
            chars[ch]++;

            while(chars[0]>0 && chars[1]>0 && chars[2]>0)
            {
                res+=n-r;
                chars[s[l]-'a']--;
                l++;
                
            }
            r++;
           
        }
        return res;
    }
};

int main()
{
    Solution sl;
    string s = "abcabc";
    cout<<sl.numberOfSubstrings(s);
}