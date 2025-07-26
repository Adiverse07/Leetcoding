#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {

        int res = 0;

        for(auto ele : derived)
        {
            res^= ele;
        }

        return res==0;
      
    }
};

int main()
{
    Solution sl;
    vector<int> derived = {1, 1, 0};

    if(sl.doesValidArrayExist(derived))
    cout<<"gogo";
}