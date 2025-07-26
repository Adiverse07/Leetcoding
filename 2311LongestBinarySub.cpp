#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestSubsequence(string s, int k)
    {

        int n = s.length();
        int len =  0;
        int powerValue =  1;// pow(2,0); 

        for (int i = n - 1; i >= 0; i--)
        {
            if(s[i]=='0')
            len++;
            else if(powerValue <= k)
            {
                k = k-powerValue;
                len++;
            }

            if(powerValue<=k)
            {
                powerValue*= 2; // can also write as:  powervalue << 1;

            }
        }

        return len;
    }
};

int main()
{
    string s = "1001010";
    int k = 5;

    Solution sl;

    cout << sl.longestSubsequence(s, k);
}