#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string newstring;
        int j=0;
            
        for(int i =0;i<s.size();i++)
        {
            

            
            
            if(j<spaces.size()&&i == spaces[j])
            {
                newstring+=" ";
                j++;
            }
            
            newstring+=s[i];
        }
        
        return newstring;    
}
};

int main()
{
    Solution sl;
    string str = "icodeinpython";
    vector<int> spacess = {1,5,7,9};
    cout<<sl.addSpaces(str,spacess);

    cout<<"\nmc";

    // return 0;
}


//Another beats 100% SOLUTION
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int n = s.size();
        int m = spaces.size();
        vector<char> newChrs(n + m); // Resulting array
        int i = 0, idx = 0;

        // Insert characters and spaces
        for (int spc : spaces)
        {
            while (i < spc)
            {
                newChrs[idx++] = s[i++];
            }
            newChrs[idx++] = ' '; // Insert space
        }

        // Add remaining characters
        while (i < n)
        {
            newChrs[idx++] = s[i++];
        }

        return string(newChrs.begin(), newChrs.end());
    }
};

int main()
{
    Solution sl;
    string str = "icodeinpython";
    vector<int> spacess = {1, 5, 7, 9};
    cout << sl.addSpaces(str, spacess) << endl;

    return 0;
}

*/