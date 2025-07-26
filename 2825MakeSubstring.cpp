#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int str1p = 0;
    int str2p = 0;
    char incremented;

    while(str1p<str1.size() && str2p < str2.size())
    {
        if(str1[str1p]=='z')
        {
            incremented = 'a';
        }
        else
        {
            incremented = str1[str1p]+1;
        }
        if ((str1[str1p] == str2[str2p] || incremented == str2[str2p]))
        {
            if(str2p < str2.size())
            {
            str1p++;
            str2p++;
            }
        }
        else
        {
            str1p++;
        }
    
    }
    
    if (str2p == str2.size())
    {
       return true;
    }
    else
    {
        return false;
    }
    }
};

int main()
{
    string str1 = "zc";
    string str2 = "ad";
    Solution sl;

    if(sl.canMakeSubsequence(str1,str2))
    {
        cout<<"True";
    }
    else
    {
        cout<<false;
    }

    
}

/*
//OG Solution
class Solution {
public:
    bool canMakeSubsequence(string source, string target) {
        int targetIdx = 0;
        int targetLen = target.length();
        for (char currChar : source) {
            if (targetIdx < targetLen && (target[targetIdx] - currChar + 26) % 26 <= 1) {
                targetIdx++;
            }
        }
        return targetIdx == targetLen;
    }
};




*/