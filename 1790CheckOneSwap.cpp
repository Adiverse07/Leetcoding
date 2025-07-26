#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int n = s1.size();
        int nonequalpos = 0;
    
        unordered_map<char, int> ch1;
        unordered_map<char, int> ch2;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            ch1[ch] = 0;
            ch2[ch] = 0;
        }
        

        for (int i =0;i<n;i++)
        {
            ch1[s1[i]]++;
            ch2[s2[i]]++;
        }

        for(int i =0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            nonequalpos++;

            if(ch1[s1[i]]!=ch2[s1[i]])
            return false;
        }

        if (nonequalpos != 0 && nonequalpos != 2)
        return false;
        
        return true;
    }
};

int main()
{
    Solution sl;
    string s1 = "bank", s2 = "kanb";

    if (sl.areAlmostEqual(s1, s2))
        cout << "true";
    else
        cout << "False";
}
