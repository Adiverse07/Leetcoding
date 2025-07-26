#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     string clearDigits(string s)
//     {
//         stack <char> st;
//         int n = s.size();
//         string res="";
//         string temp="";
//         int stp=0;

//         for(int i =0;i<n;i++)
//         {
//             char ch = s[i];
//             if(ch>='a' && ch<='z')
//             {
//                 st.push(ch);
//             }
//             else
//             {
//                 if(!st.empty())
//                 st.pop();
//             }  
//         }

//         while(!st.empty())
//         {
//             char t = st.top();
//             temp+=t;
//             st.pop();
//         }

//         for(int i = temp.size()-1;i>=0;i--)
//         {
//             res+=temp[i];
//         }

//         return res;

        
//     }
// };
//Optimal
class Solution
{
public:
    string clearDigits(string s)
    {
       int n = s.size();
       vector <char> st;
        
       for(auto ch : s)
       {
        if(ch>='a' && ch<='z')
        st.push_back(ch);
        
        else if(!st.empty())
        st.pop_back();
        
       }

       return string(st.begin(),st.end());
        
    }
};
int main()
{
    Solution sl;
    string s = "abc3";
    
    cout<<sl.clearDigits(s);

}

