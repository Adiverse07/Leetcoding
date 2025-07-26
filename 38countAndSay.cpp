#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
        string countAndSay(int n) {
            
           if(n==1)
           return "1";

           string say =  countAndSay(n-1);

           //Processing
            string res = "";
           for(int i = 0;i<say.size();i++)
           {
                char ch = say[i];
                int count = 1;

                while(i < say.length()-1 && say[i] == say[i+1])
                {
                    count++;
                    i++;
                }
                
                res += to_string(count) + string(1,ch);
           }
           return res;
        }
    };

int main()
{
    int n = 4;
    Solution sl;

    cout<<sl.countAndSay(n); 
}