#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        // int n = indices.size();
        // string res = "";
        // unordered_map<int,int> mapper;
        // for(int i =0;i<n;i++)
        // {
        //    mapper[indices[i]]=i;
        // }

        // for(int i = 0;i< n;i++)
        // {
        //     res += s[mapper[i]];
        // }

        // return res;

        int n = indices.size();
        string res(n,' ');

        for(int i = 0;i<n;i++)
        {
            res[indices[i]] = s[i];
        }

        return res;
        
    }
};

int main()
{
    string s = "codeleet";
    Solution sl;
    vector<int> indices = {4,5,6,7,0,2,1,3};

    cout<<sl.restoreString(s,indices);
}