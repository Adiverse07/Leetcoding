#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    string removeSubstr(string s, string matchStr)
    {
        int i = 0;
        int j = 0;

        int n = s.size();

        while(j<n)
        {
            s[i] = s[j]; // j reads and writes to i
            i++;
            if(i>=2 && s[i-2]==matchStr[0] && s[i-1] == matchStr[1]) // found matching string i.e ab or ba before i
            {
                i -=2;
            }

            j++;
        }

        s.erase(s.begin()+i, s.end());

        return s;
    }
    int maximumGain(string s, int x, int y) { //x:ab , y:ba
        int n = s.size();

        string maxstr = (x>y) ? "ab" : "ba";
        string minstr = (maxstr == "ab") ? "ba" : "ab";
        int score = 0;

        //first pass
        string temp_first = removeSubstr(s,maxstr);
        int L = temp_first.length();

        int charRemoved = n-L;
        score += (charRemoved/2) * max(x,y);

        //second pass
        string temp_second = removeSubstr(temp_first,minstr);
        charRemoved = L - temp_second.length();


        score+= (charRemoved/2) * min(x,y);

        return score;


    }
};

int main()
{
    Solution sl;
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    cout<<sl.maximumGain(s,x,y);
}