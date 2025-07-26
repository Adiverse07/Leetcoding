#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.size();
        unordered_map<char,pair<int,int>> occurences;
        
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(occurences.find(s[i])==occurences.end())
            {
                occurences[s[i]] = make_pair(i,i);
            }
            else
            {
                occurences[s[i]].second = i;
            }
        }

        for(auto ele: occurences)
        {
            int start =  ele.second.first;
            int end = ele.second.second;
            unordered_set<char> unique;

            for(int i =start+1;i<end;i++)
            {
                unique.insert(s[i]);
            }

            count+= unique.size();

        }
        return count;
    }
};

int main()
{
    Solution sl;
    string s = "adc";
    cout<<sl.countPalindromicSubsequence(s);

    cout<<endl;
    unordered_map<int,string> test = { {1,"adi"},{2,"vaishnavi"}};

    test[2] = "kutri";

    for(auto k:test)
    {
        cout<<k.first<<":"<<k.second<<endl;
    }

    

}
